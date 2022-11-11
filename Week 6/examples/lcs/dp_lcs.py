
dp = [[-1] * 100 for _ in range(100)]
# returns the length of the longest common subsequence of a[0..i] and b[0..j]
a,b = input(), input()
def longest_common_subsequence(i, j):
    if i < 0 or j < 0: return 0
    if dp[i][j] != -1: return dp[i][j]
    if a[i] == b[j]:
        dp[i][j] = 1 + longest_common_subsequence(i - 1, j - 1)
    else:
        dp[i][j] = max(longest_common_subsequence(i - 1, j), longest_common_subsequence(i, j - 1))
    return dp[i][j]

# call this after calling longest_common_subsequence to get the actual subsequence
ans = ""
def build_lcs(i, j):
    global ans
    if i < 0 or j < 0:
        ans = ""
        return
    if a[i] == b[j]:
        build_lcs(i - 1, j - 1)
        ans += a[i]
    elif i > 0 and dp[i - 1][j] > dp[i][j - 1]: # move in the direction that gives the longer subsequence
        build_lcs(i - 1, j)
    else:
        build_lcs(i, j - 1)

print(longest_common_subsequence(len(a) - 1, len(b) - 1))
build_lcs(len(a) - 1, len(b) - 1)
print(ans)
