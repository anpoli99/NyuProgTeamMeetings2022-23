#That but in python:

# There's some non DP approaches to this problem
# If you wanted to get started w/ a DP approach, I'd recommend something like this:
L, W = 40 + 5, 1000 + 5
visited = [[False for _ in range(W)] for _ in range(L)]
ans = ""
def solve(i, j):
    if i == 0:
        return j == 0
    if j < 0:
        return False
    if visited[i][j]:
        # visiting a state twice can't help us! if it returned false the first time,
        # it will return false the second time
        return False
    visited[i][j] = True
    for k in range(1, 27):
        if solve(i - 1, j - k):
            global ans
            ans += chr(ord('a') + k - 1)
            return True
    return False

def weightofwords(l, w):
    if not solve(l, w):
        return "impossible"
    return ans

l, w = map(int, input().split())
print(weightofwords(l, w))