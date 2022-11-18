# Input format: x[0],y[0] = start, x[n - 1],y[n - 1] = end
def kastenlauf(n, x, y):
    # Your code here
    pass


qr = int(input())
for _ in range(qr):
    n = int(input())
    n += 2 # 0 = begin, n + 1 = end
    x = [0] * n
    y = [0] * n
    for i in range(n):
        x[i], y[i] = map(int, input().split())
    print("happy" if kastenlauf(n, x, y) else "sad")
    