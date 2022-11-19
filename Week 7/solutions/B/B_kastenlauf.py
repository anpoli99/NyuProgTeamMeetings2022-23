N = 1000 + 5
x = [0] * N
y = [0] * N
vis = [0] * N

qr = int(input())
for _ in range(qr):
    # You could also use Floyd-Warshall or Dijkstra's with 'n' this small
    # I think BFS is the easiest to implement, and it's also the fastest.
    # Usually using Dijkstra's when you could use a BFS won't actually
    # matter in practice, but there could be a case where Dijkstra's is too
    # slow. Either way, recognizing when you can just BFS is a useful skill.
    n = int(input())
    n += 2 # 0 = begin, n + 1 = end
    for i in range(n):
        x[i], y[i] = map(int, input().split())
        vis[i] = 0
    vis[0] = 1
    q = [0]

    while q:
        k = q.pop(0)
        for i in range(n):
            if vis[i]: continue
            # One bottle every 50 meters; 20 bottles in a box
            # They can travel 1000 meters, so if the next store is 
            # at least that close, they can get there
            dx = abs(x[i] - x[k])
            dy = abs(y[i] - y[k])
            if dx + dy <= 1000:
                q.append(i)
                vis[i] = 1
    print("happy" if vis[n - 1] else "sad")
    