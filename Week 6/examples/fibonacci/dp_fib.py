import time 
def fibonacci(n):
    if n == 0: return 0
    if n == 1: return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

dp = [-1] * 100
def fibonacci_dp(n):
    if n == 0: return 0
    if n == 1: return 1
    if dp[n] != -1: 
        return dp[n]
    dp[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2)
    return dp[n]

n = int(input())
start = time.time()
print(fibonacci(n))
end = time.time()
print("It took " + str(round(end - start, 4)) + " seconds to calculate that!")

start = time.time()
fibonacci_dp(n)
end = time.time()
print("It took " + str(round(end - start, 4)) + " seconds with dp!")
