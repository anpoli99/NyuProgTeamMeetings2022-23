N = 2e5 + 5
adj = [[] for i in range(N)]
# if we need weights, we can use:
# adj = [[] for i in range(N)] 
# adj[i] = [(child, weight), ...]

def how_many_vertices(root, parent): # how many vertices in subtree?
    ans = 1
    for child in adj[root]:
        if child == parent: continue
        ans += how_many_vertices(child, root)
    return ans

diameter = 0
# The diameter is the longest path between two vertices in a tree.
# We can find it by finding the two longest paths from a given vertex
# to the leaves of the tree. The longest path through this vertex (without
# its parent) is the sum of these two paths. The diameter will be one of
# these such paths.
def find_largest_path_to_leaves(root, parent):
    max1 = 0
    max2 = 0
    for child in adj[root]:
        if child == parent: continue
        path = find_largest_path_to_leaves(child, root) + 1 # +1 for current edge
        if path > max1: 
            max2 = max1 # we know max1 >= max2
            max1 = path 
        elif path > max2:
            max2 = path
    diameter = max(diameter, max1 + max2)
    return max1

# union-find for Kruskal's algorithm; see last week's meeting for more details
root = [-1] * N
def find(k):
    if root[k] < 0: return k
    root[k] = find(root[k])
    return root[k]

class edge:
    # In Python, we can use a class to represent an edge
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w
    def __lt__(self, other):
        return self.w < other.w

def kruskals_mst(edges, n):
    edges.sort() # lowest weight to highest weight
    root = [-1] * N
    ans = 0
    for e in edges:
        u = find(e.u)
        v = find(e.v)
        if u != v:
            root[u] = v
            ans += e.w # add edge to MST
    return ans

dist = [0] * N
parent = [0] * N # useful for reconstructing the MST
vis = [False] * N
INF = 1e9 + 5
def prims_mst_n_squared(n):
    # Assume adj is a list of lists of tuples (child, weight)
    root = 1 # start at any vertex
    for i in range(1, n + 1):
        dist[i] = INF
        vis[i] = False
    dist[root] = 0
    ans = 0
    parent[root] = -1 
    for i in range(1, n): # Tree has n - 1 edges
        best_dist = INF
        next = -1
        for j in range(1, n + 1):
            if not vis[j] and dist[j] < best_dist:
                best_dist = dist[j]
                next = j
        # if next == -1: return -1 # graph is not connected
        vis[next] = True
        ans += best_dist
        # add edge (parent[next], next) to MST
        for child, weight in adj[next]:
            if not vis[child] and weight < dist[child]:
                dist[child] = weight
                parent[child] = next
    return ans

from heapq import heappush, heappop

def prims_mst(n):
    # use a priority queue to make algorithm O(E log V)
    pq = []
    root = 1 # start at any vertex
    for i in range(1, n + 1):
        dist[i] = INF
        vis[i] = False
    dist[root] = 0
    ans = 0
    parent[root] = -1
    heappush(pq, (0, root))
    while pq:
        w, next = heappop(pq)
        if vis[next]: continue
        vis[next] = True
        ans += w
        # add edge (parent[next], next) to MST
        for child, weight in adj[next]:
            if not vis[child] and weight < dist[child]:
                dist[child] = weight
                parent[child] = next
                heappush(pq, (weight, child))
    return ans


