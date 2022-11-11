
INF = (1 << 30) - 1
N = 2000 + 20
a = [0] * N # Just for convenience I'm leaving 'a' and 'n' global
            # Note that I'm indexing 'a' starting from 1
n = 0

# AFAIK for this problem you need DP
# Here's a template to get started on that
dp = [[-1 for _ in range(N)] for _ in range(N)]
def solve(i, j):
    if i == n: return a[i]
    if i > n or i < 1: 
        return INF
    if dp[i][j] != -1:
        return dp[i][j]
    # jump forward 'j' increasing the jump size, or jump back 'j - 1' leaving the jump size the same
    dp[i][j] = min(solve(i + j, j + 1), solve(i - j + 1, j)) + a[i]
    return dp[i][j]

def nikola():
    return solve(2, 2) # first jump must be from 1 to 2, so we start at 2

n = int(input())
for i in range(1, n + 1):
    a[i] = int(input())

print(nikola())
