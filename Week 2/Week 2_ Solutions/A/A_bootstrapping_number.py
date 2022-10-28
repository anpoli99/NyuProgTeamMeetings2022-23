

def bootstrappingnumber(n):
    lo, hi = 0, 40
    for i in range(100):
        mid = (lo + hi) / 2
        if mid ** mid < n:
            lo = mid
        else:
            hi = mid
    return lo

n = int(input())

print(bootstrappingnumber(n))
