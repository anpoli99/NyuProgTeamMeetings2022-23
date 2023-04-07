import sys
def fast_input():
    return sys.stdin.readline().strip()

"""
Here is a less typical use of a segment tree; we will use it to find the
kth largest element in a (multi)set.

This file takes 'Q', the number of queries, and Q lines of input.
Each line is either 'add x', 'del x', or 'kth k'.
- 'add x' adds x to the multiset
- 'del x' deletes one occurrence of x from the multiset
- 'kth k' prints the kth largest element in the multiset
(Note: 1 <= x <= Q <= 10^5; assume there are at least k elements in the multiset at time of query)
The typical approach to this problem is to use a balanced binary search tree,
but segment trees are extremely versatile.
"""

class Tree:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.m = (a + b) // 2
        self.left = None
        self.right = None
        self.size = 0
        if a != b:
            self.left = Tree(a, self.m)
            self.right = Tree(self.m + 1, b)

    def update(self, k, v):
        if self.a == self.b:
            # For all segment tree problems, update the terminal node here
            self.size += v
            return
        if k <= self.m:
            self.left.update(k, v)
        else:
            self.right.update(k, v)
        # Store the information about the children in the parent
        self.size = self.left.size + self.right.size

    def kth_largest(self, k):
        if self.a == self.b:
            return self.a
        if k <= self.left.size:
            return self.left.kth_largest(k)
        else:
            return self.right.kth_largest(k - self.left.size)
        
n = int(fast_input())
t = Tree(1, n)
for i in range(n):
    command, x = fast_input().split()
    x = int(x)
    if command == "add":
        t.update(x, 1)
    elif command == "del":
        t.update(x, -1)
    else:
        print(t.kth_largest(x))

"""
Example input:
11
add 1
add 2
add 3
kth 2
kth 3
del 2
add 6
kth 2
kth 3
add 5
kth 3

Expected output:
2
3
3
6
5
"""