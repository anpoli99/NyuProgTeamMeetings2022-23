import bisect

INF = 10**9 + 5


# There are a lot of approaches to this problem; the constraints are small enough
# that you can iterate over all the palindromes to find the smallest. But it becomes
# simpler to write if we just precompute them, and use a list to find the smallest

# We can store all the palindromes in a sorted list
all_palindromes = []

for i in range(100, 1000): # No leading zeroes; start at 100
    s = str(i)
    t = s[::-1]
    s += t
    all_palindromes.append(int(s))

qr = int(input())
for _ in range(qr):
    k = int(input())
    # Find the first palindrome greater than k
    # bisect.bisect_left returns the index of the first element that is greater than or equal to x
    # bisect.bisect_right returns the index of the first element that is greater than x
    right = bisect.bisect_right(all_palindromes, k)
    best = INF
    best_palindrome = -1
    if right < len(all_palindromes): # Check palindrome greater than k
        best = all_palindromes[right] - k
        best_palindrome = all_palindromes[right]
    if right > 0: # Check palindrome less than/equal to k
        left = right - 1
        if k - all_palindromes[left] <= best:
            best = k - all_palindromes[left]
            best_palindrome = all_palindromes[left]
    print(best_palindrome)
