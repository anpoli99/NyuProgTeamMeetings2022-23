#input format: a is the list containing n elements
def greedily_increasing_subsequence(n, a):
    # Your code to find the greedily increasing subsequence goes here
    return None # This is a placeholder for the return value

n = int(input())
a = list(map(int, input().split()))
ans = greedily_increasing_subsequence(n, a)
print(len(ans))
print(" ".join(map(str, ans)))