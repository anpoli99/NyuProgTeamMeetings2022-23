#input format: a is the list containing n elements
def greedily_increasing_subsequence(n, a):
    ans = [a[0]]
    for i in range(1, n):
        if a[i] > ans[-1]:
            ans.append(a[i])
    return ans

n = int(input())
a = list(map(int, input().split()))
ans = greedily_increasing_subsequence(n, a)
print(len(ans))
print(" ".join(map(str, ans)))