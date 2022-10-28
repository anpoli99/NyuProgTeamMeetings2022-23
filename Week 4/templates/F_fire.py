from queue import Queue

INF = 10 ** 9 # Helpful way to store infinity as a large number

#input format: grid contains 'rows' rows, with a string of 'cols' characters
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0] # You may want to use these lists in your implementation

# Return the minimum distance to escape the fire, or -1 if it is impossible
def fire(rows, cols, grid):
    # Your code to find the minimum distance to escape the fire
    return -1 # Replace this with your return value

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