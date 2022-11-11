

coins = [1, 5, 10, 25, 50] # this function will work, regardless of what coins we have
dp = [-1] * 400
def min_coins(n):
    if dp[n] != -1: 
        return dp[n]
    ans = 1e9
    for c in coins:
        # try using each coin
        if n - c >= 0:
            ans = min(ans, 1 + min_coins(n - c))
    dp[n] = ans
    return ans

ans = []
# call this after calling min_coins to get the actual coins
def get_coins(n):
    if n == 0: return
    for c in coins:
        if n - c >= 0 and dp[n] == 1 + dp[n - c]:
            ans.append(c)
            get_coins(n - c)
            return

n = int(input())
dp[0] = 0 # base case; 0 coins are needed to make 0
print(min_coins(n))
get_coins(n)
print(*ans)