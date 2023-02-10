

"""
    *
 * This implementation of Dinic's algorithm is taken from
 * https://python.algorithmexamples.com/web/graphs/dinic.html. We will use
 * it to solve the Kattis problem: https://open.kattis.com/problems/maxflow.
 * Details on how to use this implementation are demonstrated below.
"""
INF = (2 ** 31) - 1
 
 
class Dinic:
    def __init__(self, n):
        self.lvl = [0] * n
        self.ptr = [0] * n
        self.q = [0] * n
        self.adj = [[] for _ in range(n)]
 
    """
    Here we will add our edges containing with the following parameters:
    vertex closest to source, vertex closest to sink and flow capacity
    through that edge ...
    """
 
    def add_edge(self, a, b, c, rcap=0):
        self.adj[a].append([b, len(self.adj[b]), c, 0])
        self.adj[b].append([a, len(self.adj[a]) - 1, rcap, 0])
 
    # This is a sample depth first search to be used at max_flow
    def depth_first_search(self, vertex, sink, flow):
        if vertex == sink or not flow:
            return flow
 
        for i in range(self.ptr[vertex], len(self.adj[vertex])):
            e = self.adj[vertex][i]
            if self.lvl[e[0]] == self.lvl[vertex] + 1:
                p = self.depth_first_search(e[0], sink, min(flow, e[2] - e[3]))
                if p:
                    self.adj[vertex][i][3] += p
                    self.adj[e[0]][e[1]][3] -= p
                    return p
            self.ptr[vertex] = self.ptr[vertex] + 1
        return 0
 
    # Here we calculate the flow that reaches the sink
    def max_flow(self, source, sink):
        flow, self.q[0] = 0, source
        for l in range(31):  # noqa: E741  l = 30 maybe faster for random data
            while True:
                self.lvl, self.ptr = [0] * len(self.q), [0] * len(self.q)
                qi, qe, self.lvl[source] = 0, 1, 1
                while qi < qe and not self.lvl[sink]:
                    v = self.q[qi]
                    qi += 1
                    for e in self.adj[v]:
                        if not self.lvl[e[0]] and (e[2] - e[3]) >> (30 - l):
                            self.q[qe] = e[0]
                            qe += 1
                            self.lvl[e[0]] = self.lvl[v] + 1
 
                p = self.depth_first_search(source, sink, INF)
                while p:
                    flow += p
                    p = self.depth_first_search(source, sink, INF)
 
                if not self.lvl[sink]:
                    break
 
        return flow

    

# End of Dinic's implementation

# Read in the number of nodes and edges
n, m, s, t = map(int, input().split())

# Create a new Dinic object with n nodes
dinic = Dinic(n)

# Read in the edges and add them to the Dinic object
for i in range(m):
    u, v, cap = map(int, input().split())
    # add edge from u to v with capacity 'cap'
    dinic.add_edge(u, v, cap)

# Compute the maximum flow from the source to the sink
maxFlow = dinic.max_flow(s, t)
edges_used = []
# Iterate through all the edges in the flow network
# An edge is used if its flow is greater than 0
# We can also check the capacity of the edge in the same way
for i in range(n):
    for e in dinic.adj[i]:
        if e[3] > 0:
            edges_used.append([i, e[0], e[3]])

print(n, maxFlow, len(edges_used))
for e in edges_used:
    print(e[0], e[1], e[2])
