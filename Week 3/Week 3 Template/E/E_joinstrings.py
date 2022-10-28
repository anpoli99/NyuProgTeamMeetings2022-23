# format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
# 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
def joinstrings(n, s, a, b):
    # Your code here; you should return the final concatenated string
    return "" # This is a placeholder

n = int(input())
s = [""]
for i in range(n):
    s.append(input())

a, b = [0], [0]
for i in range(n - 1):
    x,y = map(int, input().split())
    a.append(x)
    b.append(y)

print(joinstrings(n, s, a, b))
