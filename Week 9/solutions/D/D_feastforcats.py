# This is also a minimum spanning tree problem. The optimal path
# will not have any cycles, so the weight of the MST is the minimum
# amount of milk spilled. Also we need to give each cat one unit
# of milk; subtract the number of cats from m to begin with.
# If the weight of the MST is <= m, then we can give each cat
# one unit of milk without running out.

# Keep in mind that Kruskal's algorithm is E log E. This is slower than
# the N^2 Prim's algorithm when E ~= N^2! In C++ Kruskal's passes in about 2s
# which is fast enough, but other languages may time out.
# Here's a faster version using Prim's algorithm:

N = int(2e3) + 5
adj = [[0] * N for _ in range(N)]
dist = [0] * N
vis = [False] * N
def feastforcats(c, m, e):
    for u,v,w in e:
        adj[u][v] = adj[v][u] = w

    mst_weight = 0
    for i in range(c):
        dist[i] = adj[0][i]
        vis[i] = False

    dist[0] = 0
    vis[0] = True
    for i in range(c - 1):
        best_dist = 1e9
        next = -1
        for j in range(c):
            if not vis[j] and dist[j] < best_dist:
                best_dist = dist[j]
                next = j
        vis[next] = True
        mst_weight += best_dist
        for j in range(c):
            if not vis[j] and adj[next][j] < dist[j]:
                dist[j] = adj[next][j]

    return mst_weight <= m - c

for _ in range(int(input())):
    m,c = map(int, input().split())
    e = [tuple(map(int, input().split())) for _ in range(c * (c - 1) // 2)]
    print("yes" if feastforcats(c,m,e) else "no")