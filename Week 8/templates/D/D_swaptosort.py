
# Input: 'a' is 2d list of size [k][2] representing the k swaps
# Output: True if a descending list of size n can be sorted with the swaps, false otherwise
def swapToSort(n, k, a):
    # Your code goes here
    return False # This is a placeholder

n, k = map(int, input().split())
a = []
for i in range(k):
    a.append(list(map(int, input().split())))

print("Yes" if swapToSort(n, k, a) else "No")