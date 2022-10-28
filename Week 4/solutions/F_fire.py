from queue import Queue

INF = 10 ** 9

#input format: grid contains 'rows' rows, with a string of 'cols' characters
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
def fire(rows, cols, grid):
    # We can do two bfs's, one from the person and one from each fire source
    # An endpoint is valid iff the person can reach it before the fire does
    dist_to_person, dist_to_fire = [[INF] * cols for _ in range(rows)], [[INF] * cols for _ in range(rows)]
    fire_q, person_q = Queue(), Queue()
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == '@':
                person_q.put((i, j))
                dist_to_person[i][j] = 0
            elif grid[i][j] == '*':
                fire_q.put((i, j))
                dist_to_fire[i][j] = 0
    
    while not fire_q.empty():
        x, y = fire_q.get()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != '#' and dist_to_fire[nx][ny] == INF:
                dist_to_fire[nx][ny] = dist_to_fire[x][y] + 1
                fire_q.put((nx, ny))

    while not person_q.empty():
        x, y = person_q.get()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != '#' and dist_to_person[nx][ny] == INF and dist_to_fire[nx][ny] > dist_to_person[x][y] + 1:
                dist_to_person[nx][ny] = dist_to_person[x][y] + 1
                person_q.put((nx, ny))

    # Now we can check all endpoints
    ans = INF
    for i in range(rows):
        if dist_to_person[i][0] < dist_to_fire[i][0]:
            ans = min(ans, dist_to_person[i][0] + 1)

        if dist_to_person[i][cols - 1] < dist_to_fire[i][cols - 1]:
            ans = min(ans, dist_to_person[i][cols - 1] + 1)
    
    for j in range(cols):
        if dist_to_person[0][j] < dist_to_fire[0][j]:
            ans = min(ans, dist_to_person[0][j] + 1)

        if dist_to_person[rows - 1][j] < dist_to_fire[rows - 1][j]:
            ans = min(ans, dist_to_person[rows - 1][j] + 1)
    
    return ans if ans != INF else -1

q = int(input())
for _ in range(q):
    cols, rows = map(int, input().split())
    grid = []
    for _ in range(rows):
        grid.append(input())
    
    ans = fire(rows, cols, grid)
    if ans == -1:
        print('IMPOSSIBLE')
    else:
        print(ans)