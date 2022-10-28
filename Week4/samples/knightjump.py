from queue import Queue

# open.kattis.com/problems/knightjump
# This is an implicit graph; for a graph with defined edges, the idea is very similar
# We'd want to still initialize a distance array to infinity and use a queue
# The only difference is we'd want to iterate over all of a vertex's neighbors instead of
# all of the possible moves.

INF = 10 ** 9 # Helpful way to store infinity as a large number

dx = [2,1,-1,-2,-2,-1,1,2]
dy = [1,2,2,1,-1,-2,-2,-1]
n = int(input())
s = []
for i in range(n):
    s.append(input())
    
start = None
dist = [[INF] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        if s[i][j] == 'K':
            start = (i,j)
            dist[i][j] = 0

# bfs starts here
q = Queue()
q.put(start)
dist[start[0]][start[1]] = 0
while not q.empty():
    x, y = q.get()
    for i in range(8): # this lets us try all neighbors
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
             continue # out of bounds
        if s[nx][ny] == '#':
             continue # blocked
        if dist[nx][ny] != INF: 
            continue # already visited
        dist[nx][ny] = dist[x][y] + 1
        q.put((nx,ny))

if dist[0][0] == INF:
    dist[0][0] = -1

print(dist[0][0])