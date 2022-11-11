# input format: 'n' is an integer, the first line
# 'a' is a list of n integers, the second line
def awkward_party(n, a):
    # This is a callback to last week :) we can use a hash map to solve it
    prev = {}
    ans = n # base case according to problem statement
    for i in range(n):
        if a[i] in prev:
            ans = min(ans, i - prev[a[i]])
        prev[a[i]] = i
    return ans

n = int(input())
a = list(map(int, input().split()))
print(awkward_party(n, a))