from heapq import heappush, heappop


N = 100 + 5
INF = 10 ** 9 + 5
edges = [[] for _ in range(N)]
dist = [INF] * N
prv = [0] * N # This will help us reconstruct the path

def dijkstras_example(source, dest, n):
    for i in range(1, n + 1):
        dist[i] = INF
    pq = [] # priority queue in python can be implemented with a list and the heapq module
    heappush(pq, (0, source)) # we can use a tuple to store any extra information we want with the distance
    dist[source] = 0
    while pq:
        u = pq[0][1]
        d = pq[0][0]
        heappop(pq)
        if d > dist[u]:
            continue
        for v, w in edges[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heappush(pq, (dist[v], v))
                prv[v] = u
    print("Shortest path from {} to {} is {}".format(source, dest, dist[dest]))
    # If we want to reconstruct the path from 'source' to 'dest':
    path = [dest]
    cur = dest
    while cur != source:
        cur = prv[cur]
        path.append(cur)
    path.reverse()
    # And now path contains the shortest path from 'source' to 'dest'
    return path

# For Floyd-Warshall, it's more helpful to use a matrix instead of a vector of pairs
adj = [[INF] * N for _ in range(N)]
nxt = [[0] * N for _ in range(N)] # This will help us reconstruct the path
def floyd_warshall_example(n, source, dest):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            adj[i][j] = INF
            nxt[i][j] = j
        adj[i][i] = 0
        for v, w in edges[i]:
            adj[i][v] = min(adj[i][v], w)

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if adj[i][j] > adj[i][k] + adj[k][j]:
                    adj[i][j] = adj[i][k] + adj[k][j]
                    nxt[i][j] = nxt[i][k]
    print("Shortest path from {} to {} is {}".format(source, dest, adj[source][dest]))

    # An example of reconstructing the path from 'source' to 'dest':
    path = [source]
    cur = source
    while cur != dest:
        cur = nxt[cur][dest]
        path.append(cur)
    # And now path contains the shortest path from 'source' to 'dest'
    return path

n, m = map(int, input().split())
for i in range(m):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))
    edges[v].append((u, w)) # Bidirectional graph; edges go both ways

source, dest = 1, n
path = dijkstras_example(source, dest, n)
print(*path)

path = floyd_warshall_example(n, source, dest)
print(*path)




