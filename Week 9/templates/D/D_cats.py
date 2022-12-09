
def feastforcats(c, m, edges):
    # Input format: 'c' is the number of cats, 'm' is the amount of milk and 'edges' is an array of 'c * (c - 1) / 2' edges
    # Each edge is a tuple (u, v, weight)
    return False # Return true if you have enough milk to feed all the cats, false otherwise

q = int(input())
for _ in range(q):
    m, c = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(c * (c - 1) // 2)]
    print("yes" if feastforcats(c, m, edges) else "no")
