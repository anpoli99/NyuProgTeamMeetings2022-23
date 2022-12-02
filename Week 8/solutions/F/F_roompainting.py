import bisect

n, m = map(int, input().split())
sizes = []
for i in range(n):
    sizes.append(int(input()))

#sort the sizes
sizes.sort()

ans = 0
for i in range(m):
    p = int(input()) 
    # find the index of the first element in sizes that is greater than or equal to p
    idx = bisect.bisect_left(sizes, p)
    ans += sizes[idx] - p

print(ans)
