
def validate(q, m, s, l, time):

    for i in range(m):
        # Greedily add maximum long segments
        long_segments = min(l, time // q)

        remaining_time = time - long_segments * q
        l -= long_segments

        # Add the maximum remaining small segments
        s -= min(s, remaining_time)

    return l == 0 and s == 0


def small_schedule(q,m,s,l):
    lo, hi = 0, q * l + s
    while lo < hi:
        mid = (lo + hi) // 2
        if validate(q, m, s, l, mid):
            hi = mid
        else:
            lo = mid + 1

    return lo

q, m, s, l = map(int, input().split())
print(small_schedule(q,m,s,l))