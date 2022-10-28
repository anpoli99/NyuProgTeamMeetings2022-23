

def reverse(a):
    # Your code to reverse 'a' goes here
    return None # This is just a placeholder; return the reversed list of integers


n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

ans = reverse(a)
for i in ans:
    print(i)
