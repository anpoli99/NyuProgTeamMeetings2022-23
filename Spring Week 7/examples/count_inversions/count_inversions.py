import sys
def fast_input():
    return sys.stdin.readline().strip()

"""
Here is an example of using a segment tree.
This file takes 'n', the length of an array, and n integers as input.
(Note: 1 <= A[i] <= n for all i)
It then prints the number of inversions in the array.
An inversion is a pair of indices (i,j) such that i < j and a[i] > a[j].
"""

class Tree:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.m = (a + b) // 2 # m = midpoint; convenient to store directly
        self.left = None
        self.right = None
        self.count = 0
        if a != b:
            self.left = Tree(a, self.m)
            self.right = Tree(self.m + 1, b)

    def update(self, k, v):
        if self.a == self.b:
            # For all segment tree problems, update the terminal node here
            self.count += v
            return
        if k <= self.m:
            self.left.update(k, v)
        else:
            self.right.update(k, v)
        # Store the information about the children in the parent
        self.count = self.left.count + self.right.count

    def query(self, l, r):
        if l <= self.a and self.b <= r:
            return self.count  # Subtree is completely contained in [l,r]
        if r < self.a or self.b < l:
            return 0  # Subtree is completely outside [l,r]
        # ^ Important note! For other problems, the default value may not be 0
        # Ex., for the minimum value, the default value should be infinity (or some large number)
        return self.left.query(l, r) + self.right.query(l, r)  # Subtree is partially contained in [l,r]
    
n = int(fast_input())
t = Tree(1, n)
a = list(map(int, fast_input().split()))
inversions = 0
for i in range(n):
    inversions += t.query(a[i] + 1, n)
    t.update(a[i], 1)

print(inversions)