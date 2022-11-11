# input format: 'a' is a list of length 3, the 3 numbers in the first line
# 's' is a string, the 3 letters in the second line
# return the answer as a list of 3 numbers
def abc(a, s):
    b = []
    a.sort()
    for c in s:
        b.append(a[ord(c) - ord('A')])
    return b

a = list(map(int, input().split()))
s = input()
b = abc(a, s)
print(*b)
