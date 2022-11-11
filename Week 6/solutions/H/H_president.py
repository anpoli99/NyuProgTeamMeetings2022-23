import sys

INF = (1 << 30) - 1
N = 2000 + 20
dp = [[-1 for _ in range(N)] for _ in range(N)]
delegates = [0] * N
cost = [0] * N
def solve(i, j):
    # i is the index of the current region
    # delegates[i] is the number of delegates gained for winning region i
    # cost[i] is the number of voters we need to persuade to win region i
    # cost[i] is precalculated below
    if j < 0: return 0
    if i == 0: return INF if j else 0
    res = dp[i][j]
    if res != -1: return res
    # try either winning region i or not
    res = min(solve(i - 1, j), solve(i - 1, j - delegates[i]) + cost[i])
    res = min(res, INF) 
    dp[i][j] = res
    return res

n = int(input())
sum = 0
for i in range(1, n + 1):
    delegates[i], c, f, u = map(int, input().split())
    sum += delegates[i]
    if c + u <= f:
        # can't win this region; cost is INF
        cost[i] = INF
    else:
        if f > c:
            # we're losing in this region, so we need at least (f - c) votes to win
            cost[i] += f - c
            u -= f - c
            cost[i] += u // 2 + 1 # strict majority of the remaining votes
        else:
            u -= c - f
            if u >= 0: cost[i] += u // 2 + 1 # strict majority of the remaining votes
            # (but if it's negative, we'll win this region no matter what, so cost[i] = 0)

sys.setrecursionlimit(N + 10) # to be honest I forgot you'd need this when I picked this problem
# Python's default recursion limit is 1000, which is too low for this problem

ans = solve(n, sum // 2 + 1) # strict majority of delegates
if ans >= INF: print("impossible")
else: print(ans)


