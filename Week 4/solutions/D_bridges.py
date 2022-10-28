from collections import deque

INF = 10 ** 9 # Helpful way to store infinity as a large number

# Input format: adj[i] is a list of the neighbors of node i
#               is_single[i][j] tells whether the edge from i to adj[i][j] is a single-lane bridge
#               adj[i].size() == is_single[i].size() for all i
# The input is 1-indexed
def bridges(n, adj, is_single):
    # In a later week we'll talk about generalized shortest paths problems
    # Dijkstra's algorithm solves this problem too

    dist = [INF] * (n + 1)
    dq = deque() # The trick to this problem is to use a deque instead of a queue
                    # If a vertex isn't a bridge, we can push it to the front of the deque instead
    
    dq.append(1)
    dist[1] = 0
    while len(dq) > 0:
        u = dq.popleft()
        for i in range(len(adj[u])):
            v = adj[u][i]
            new_dist = dist[u] + (1 if is_single[u][i] else 0)
            if new_dist < dist[v]:
                dist[v] = new_dist
                if new_dist == dist[u]:
                    dq.appendleft(v)
                else:
                    # It's fine if we push a vertex 2 times; the algorithm still takes O(n) time.
                    # Because we can show each vertex won't be pushed more than twice, 
                    # we don't need to do any processing to make sure we don't push the same vertices.
                    dq.append(v)
    return dist[n]


n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
is_single = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, is_single_lane = map(int, input().split())
    adj[u].append(v)
    is_single[u].append(is_single_lane == 1)
    adj[v].append(u)
    is_single[v].append(is_single_lane == 1)

print(bridges(n, adj, is_single))