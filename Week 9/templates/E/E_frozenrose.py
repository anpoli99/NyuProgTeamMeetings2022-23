
import sys
adj = []
def frozenrose(n, c):
    # Input format: 'n' is the number of nodes, 'c' is the central node
    # 'adj' is a list of edges of length 'n + 1' (1-indexed, same as input)
    # 'adj' will be initialized so that adj[u] is a list of edges from node u
    # Each edge is a tuple (v, weight)
    # Return the minimum cost to ensure no water leaves from a sprinkler
    return -1

# A note about this problem; it reads until EOF, which means that if you're
# typing the input in manually, you need to press Ctrl+C after the last test case,
# or type "end" on a line by itself (in case it's not flushing the output)
for line in sys.stdin:
    if line.strip() == "end":
        break
    n, c = map(int, line.split())
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v, weight = map(int, input().split())
        adj[u].append((v, weight))
        adj[v].append((u, weight))
    print(frozenrose(n,c))