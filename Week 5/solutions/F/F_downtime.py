import bisect

INF = 10 ** 9 + 5
#input format: 'a' is a list containing n elements
def downtime(n, k, a):
    # There's other solutions to this problem, such as using a two-pointer approach.
    # If you implement it fast enough, we could just have an array that has the count of 
    # requests at each time, and then iterate over every subarray of size 1000.
    # I think it's worth noting that the bisect approach requires almost no code compared to
    # these alternatives and is still pretty fast.
    s = []
    for i in range(n):
        # A useful trick; we can find the index of a lower bound in a set in O(log n) time
        # by storing it as a pair
        s.append((a[i], i))
    s.sort()
    ans = 0
    for i in range(n):
        # bisect.bisect_left returns the index of the first element that is greater than or equal to x
        # bisect.bisect_right returns the index of the first element that is greater than x
        it = bisect.bisect_left(s, (a[i] - 1000, INF))
        ans = max(ans, i - s[it][1] + 1)
    ans = (ans + k - 1) // k
    return ans

n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))
print(downtime(n, k, a))


