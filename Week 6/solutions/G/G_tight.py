
from sys import stdin

N = 100 + 5
dp = [[-1 for _ in range(N)] for _ in range(N)]
vis = [[False for _ in range(N)] for _ in range(N)]
n, k = -1, -1
def solve(i, j):
    # There's only (at most) 2 neighbors that satisfy the "tight" condition
    # We can try both of them and take their sum
    # The proportion of lists that take any given number as the next element is
    # 1 / (k + 1)
    if i == n: return 1
    if vis[i][j]: return dp[i][j]
    vis[i][j] = True
    dp[i][j] = solve(i + 1, j) / (k + 1)
    if j > 0: dp[i][j] += solve(i + 1, j - 1) / (k + 1)
    if j < k: dp[i][j] += solve(i + 1, j + 1) / (k + 1)
    return dp[i][j]

for line in stdin:
    k, n = map(int, line.split())
    for i in range(N):
        for j in range(N):
            vis[i][j] = False
    ans = 0
    for i in range(k + 1):
        ans += solve(1, i) / (k + 1)
    print("{:.10f}".format(ans * 100))