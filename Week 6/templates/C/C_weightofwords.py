#That but in python:

# There's some non DP approaches to this problem
# If you wanted to get started w/ a DP approach, I'd recommend something like this:
L, W = 40 + 5, 1000 + 5
visited = [[False for _ in range(W)] for _ in range(L)]
ans = ""
def solve(i, j):
    # TODO: implement this function
    # Return true if we find a word of length i with weight j
    return False

def weightofwords(l, w):
    if not solve(l, w):
        return "impossible"
    return ans

l, w = map(int, input().split())
print(weightofwords(l, w))