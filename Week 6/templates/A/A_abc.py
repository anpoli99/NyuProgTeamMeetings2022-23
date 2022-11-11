# input format: 'a' is a list of length 3, the 3 numbers in the first line
# 's' is a string, the 3 letters in the second line
# return the answer as a list of 3 numbers
def abc(a, s):
    # Your code here
    return [0, 0, 0]

a = list(map(int, input().split()))
s = input()
b = abc(a, s)
print(*b)
