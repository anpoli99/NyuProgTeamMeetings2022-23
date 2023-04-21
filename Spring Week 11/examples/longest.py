from collections import deque

# Input: list of lists adj; adj[i] stores the neighbors of node i
# Output: list dist; dist[i] stores the longest path from a 'root' node to i
def longest(adj):
    n = len(adj)
    # Counting the number of parents is a quick way to check if
    # removing an ancestor will make the node a root
    parent_count = [0] * n
    ready = deque()
    for i in range(n):
        for j in adj[i]:
            parent_count[j] += 1
    for i in range(n):
        if parent_count[i] == 0: # This is a root
            ready.append(i)

    dist = [0] * n
    while ready:
        node = ready.popleft()
        for i in adj[node]:
            dist[i] = max(dist[i], dist[node] + 1)
            parent_count[i] -= 1
            if parent_count[i] == 0: # This is a root now
                ready.append(i)
    
    return dist


# Input from stdin: n vertices with m edges; will not work if input is not a DAG
n,m = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
   a,b = map(int, input().split())
   adj[a].append(b)
dist = longest(adj)
print(*dist)