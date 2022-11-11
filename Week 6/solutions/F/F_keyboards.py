
INF = (1 << 30) - 1
N = 1000 + 5

dp = [[-1 for _ in range(N)] for _ in range(N)]
notes = [set() for _ in range(N)]
played_by = [[] for _ in range(N)]
a = []
def solve(i,j):
    # i = idx of current note, j = current instrument
    # if j == 0, we need to switch instruments
    # we can store which instruments play which notes and iterate, and just recursively call again
    if i == m + 1: return 0
    if dp[i][j] != -1: return dp[i][j]
    if j == 0:
        dp[i][j] = INF
        for k in played_by[a[i]]:
            dp[i][j] = min(dp[i][j], solve(i + 1, k))
        dp[i][j] += 1 # +1 for switching instruments
    elif a[i] in notes[j]:
        # current instrument can play current note; don't switch
        dp[i][j] = solve(i + 1, j)
    else:
        # current instrument doesn't play this note, so we need to switch
        dp[i][j] = solve(i, 0)

    return dp[i][j]

n, m = map(int, input().split())
for i in range(1, n + 1):
    ls = list(map(int, input().split()))
    k = ls[0]
    for j in range(1, k + 1):
        notes[i].add(ls[j])
        played_by[ls[j]].append(i)

a = [0] + list(map(int, input().split()))
print(solve(1, 0) - 1)