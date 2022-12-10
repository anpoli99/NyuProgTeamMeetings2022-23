
import sys

# We're given the sprinkler system is a tree, and now we can DFS on it.
# The minimum cost to isolate a subtree from the root is the minimum of:
# - The cost of closing off the root from its parent
# - The cost of closing off all of the root's children

N = 1000 + 5
INF = 10**9 + 5
e = [[] for _ in range(N)]
dist = [[0] * N for _ in range(N)]
def solve(k, p):
    ans = 0
    for i in e[k]:
        if i == p: continue
        # close child from parent, or close all of the childs' children
        ans += min(dist[k][i], solve(i, k))
    if ans == 0:
        # this is a leaf; we can't close it!
        return INF
    return ans

for line in sys.stdin:
    n, root = map(int, line.split())
    for i in range(1, n + 1):
        e[i] = []
    for i in range(1, n):
        u, v, w = map(int, input().split())
        e[u].append(v)
        e[v].append(u)
        dist[u][v] = dist[v][u] = w
    print(solve(root, -1))