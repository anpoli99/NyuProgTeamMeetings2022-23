import sys
def fast_input():
    return sys.stdin.readline().strip()

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
    
# The idea here is to keep track of what the 
# current state of each bit is in an auxiliary array.
# Then, when we flip a bit, we can either add or subtract
# 1 based on the current state of the bit.
# Getting the actual sums is a straight-forward application
# of segment trees.

n, q = map(int, fast_input().split())
t = Tree(1, n)
ans = []
cur = [0] * (n + 1)
for _ in range(q):
    line = fast_input()
    if line[0] == 'F':
        pos = int(line[2:])
        cur[pos] ^= 1 # Flip the bit
        t.update(pos, 1 if cur[pos] else -1) 
    elif line[0] == 'C':
        l, r = map(int, line[2:].split())
        ans.append(t.query(l, r))

print('\n'.join(map(str, ans)))