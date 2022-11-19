
from heapq import heappush, heappop

LINF = 10**18
N = 20000 + 5
adj = [[] for _ in range(N)]
dist = [LINF] * N
n, m, c, k, d = map(int, input().split())
# just a side-note; I like to ignore what they called the variables
# n = # of vertices, m = # of edges, d = # of days
# It means I only have to replace the variables once and I can know
# for ALL codes 'm' = # of edges. I'm mentioning this because "clean"
# code techniques are VERY important in contests in my opinion. Doing
# this takes _maybe_ 10 seconds, but not doing it and mixing up 'm'
# and 'd' can cost you 10 minutes.
for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))
# Dijktstra's to find shortest distance to each node
dist[1] = 0
pq = [(0, 1)]
while pq:
    cur = heappop(pq)
    if cur[0] > dist[cur[1]]: continue
    for nxt in adj[cur[1]]:
        ndist = cur[0] + nxt[1]
        if dist[nxt[0]] > ndist:
            dist[nxt[0]] = ndist
            heappush(pq, (ndist, nxt[0]))
            
# get all flowers + their distances
flowers = [int(x) for x in input().split()]
flowers = [dist[x] for x in flowers]
flowers.sort()
d = min(d, k) # flowers regrow every k days; so we can revisit the same flower after this
ans = flowers[d - 1] * 2 if d <= c else -1
if ans > LINF: ans = -1
print(ans)
