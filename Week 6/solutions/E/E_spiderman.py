
INF = (1 << 30) - 1
N = 2000 + 20
dp = [[-1 for _ in range(N)] for _ in range(N)]
visited = [[0 for _ in range(N)] for _ in range(N)]
vis_idx = 1 # this is a helpful way to avoid having to clear the while dp array every test case
a = []
n = 0

def solve(i, j): # i is index of the jump, j is the current height
    if j < 0: 
        return INF
    if i == n: 
        return 0 if j == 0 else INF
    res = dp[i][j]
    if visited[i][j] == vis_idx: return res
    visited[i][j] = vis_idx
    res = min(solve(i + 1, j - a[i]), solve(i + 1, j + a[i]))
    res = max(res, j) # the max height is at least the current height
    dp[i][j] = res
    return res

ans = ""
def build(i, j): # after solving, we need to recreate the answer  
    # we can check both possibilities and see which one gives us the correct answer
    # for a given (i,j)
    if i == n: 
        return
    global ans
    res = solve(i, j)
    if res == solve(i + 1, j + a[i]):
        ans += 'U'
        build(i + 1, j + a[i])
    else:
        ans += 'D'
        build(i + 1, j - a[i])


qr = int(input())
while qr > 0:
    qr -= 1
    n = int(input())
    a = list(map(int, input().split()))
    ans = ""
    res = solve(0, 0)
    if res >= INF:
        print("IMPOSSIBLE")
    else:             
        build(0, 0)
        print(ans)
    vis_idx += 1