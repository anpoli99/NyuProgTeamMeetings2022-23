
n = int(input())
dist, x, y, r, visited = [0] * n, [0] * n, [0] * n, [0] * n, [False] * n
for i in range(n):
    x[i], y[i], r[i] = map(int, input().split())
    # 0 is the root; initialize dist[i] using index 0
    dx, dy = x[i] - x[0], y[i] - y[0]
    cost = (dx * dx + dy * dy) ** 0.5 - r[i] - r[0]
    dist[i] = max(0, cost)

ans = 0
visited[0] = True
for i in range(n - 1):
    best_dist, next = 1e9, -1
    for j in range(n):
        if not visited[j] and dist[j] < best_dist:
            best_dist, next = dist[j], j
    visited[next] = True
    ans += best_dist
    for j in range(n):
        if not visited[j]:
            dx, dy = x[j] - x[next], y[j] - y[next]
            cost = (dx * dx + dy * dy) ** 0.5 - r[j] - r[next]
            dist[j] = min(dist[j], max(0, cost))

print(ans)