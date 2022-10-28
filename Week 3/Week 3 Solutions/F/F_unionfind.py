
import sys

def fast_input():
    return sys.stdin.readline().strip()

"""
* This is a linked list problem, but the key here is an idea called "path compression".
* When we find the final destination of a node, since we know that we're not going to
* change the structure in between the node and the destination, we can have the node
* point directly to the destination. This makes the problem O(n log n) instead of O(n^2).
* You can reduce this to O(n) by always making the root the node with the smaller size,
* but that's not necessary for this problem.
*
* An alternate implementation would store root[i] = i if i is it's own root.
* It's not uncommon to see root[i] = 0 or root[i] = -1 instead, because it makes some parts of 
* the implementation easier.
"""
n, q = map(int, input().split())
root = [-1] * (n + 1)
def find(x):
    if root[x] < 0:
        return x
    else:
        root[x] = find(root[x])
        return root[x]

ans = []
for i in range(q):
    c, a, b = fast_input().split()
    a, b = int(a), int(b)
    if c == '?':
        a = find(a)
        b = find(b)
        if(a == b):
            ans.append(1)
        else:
            ans.append(0)

    else:
        a = find(a)
        b = find(b)
        if a != b:
            #we might create a cycle if the roots are already connected
            root[a] = b

print(''.join(map(lambda x: 'yes\n' if x else 'no\n', ans)))