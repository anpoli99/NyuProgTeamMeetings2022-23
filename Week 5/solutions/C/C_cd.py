

def fast_input():
    import sys
    return sys.stdin.readline().strip()

# Input format: a and b are lists containing n/m elements respectively
def cd(n, m, a, b):
    a_set = set(a)
    ans = 0
    for j in b:
        if j in a_set:
            ans += 1

    return ans


while True:
    n, m = map(int, fast_input().split())
    if n == 0 and m == 0:
        break
    a = []
    b = []
    for i in range(n):
        a.append(int(fast_input()))
    for i in range(m):
        b.append(int(fast_input()))
        
    print(cd(n, m, a, b))
