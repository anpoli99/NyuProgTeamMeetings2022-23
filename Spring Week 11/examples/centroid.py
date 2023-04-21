from collections import deque

# Input: list of lists adj; adj[i] stores the neighbors of node i
# Output: integer; the (a) centroid of the tree
# Note that this is a tree; edges are bidirectional
def centroid(adj):
    n = len(adj)
    # Counting the number of parents is a quick way to check if
    # removing an ancestor will make the node a leaf
    parent_count = [0] * n
    ready = deque()
    for i in range(n):
        for j in adj[i]:
            parent_count[j] += 1
    for i in range(n):
        if parent_count[i] == 1: # This is a leaf
            ready.append(i)
    centroid = -1
    while ready:
        node = ready.popleft()
        centroid = node # The last node to be removed is the centroid
        for i in adj[node]:
            parent_count[i] -= 1
            if parent_count[i] == 1: # This is a leaf now
                ready.append(i)
    return centroid

# Input from stdin: Tree with n vertices (n - 1) edges
n = int(input())
adj = [[] for i in range(n)]
for i in range(n - 1):
    a,b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
print(centroid(adj))
