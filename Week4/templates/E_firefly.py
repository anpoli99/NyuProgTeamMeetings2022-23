
# input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
# return a pair with the optimal # of obstacles and the # of levels where that is possible
# note that the firefly cannot fly at a height of 0
def firefly(n, h, a, b):
    # Note that initially n = len(a) + len(b)
    n = n // 2

    return -1, -1 # This is a placeholder, replace it with your code


n, h = map(int, input().split())
a, b = [], []
for i in range(n):
    if i % 2 == 0:
        a.append(int(input()))
    else:
        b.append(int(input()))

p, q = firefly(n, h, a, b)
print(p, q)
