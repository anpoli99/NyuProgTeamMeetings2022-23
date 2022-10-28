# Input format: adj[i] is a list of the neighbors of node i
#               is_single[i][j] tells whether the edge from i to adj[i][j] is a single-lane bridge
#               adj[i].size() == is_single[i].size() for all i
# The input is 1-indexed
def bridges(n, adj, is_single):
    # Your code to find the minimum number of single-lane bridges goes here
    return -1 # This is a placeholder
    
n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
is_single = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, is_single_lane = map(int, input().split())
    adj[u].append(v)
    is_single[u].append(is_single_lane == 1)
    adj[v].append(u)
    is_single[v].append(is_single_lane == 1)

print(bridges(n, adj, is_single))