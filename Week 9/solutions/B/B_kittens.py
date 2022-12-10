# This problem's input describes all the parent-child relationships we need to know
# to find the path to the root from a given node. We can store the parent of each node
# and then walk up the parent chain until we reach the root.

N = 100 + 5
parent = [-1] * N # we know we're at the root if parent[i] == -1


k = int(input())
while True:
    s = input()
    if s == "-1":
        break
    p, *children = map(int, s.split())
    for child in children:
        parent[child] = p

while k != -1:
    print(k, end=' ')
    k = parent[k]
print()