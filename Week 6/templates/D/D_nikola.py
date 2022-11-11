
INF = (1 << 30) - 1
N = 2000 + 20
a = [0] * N # Just for convenience I'm leaving 'a' and 'n' global
            # Note that I'm indexing 'a' starting from 1
n = 0

# AFAIK for this problem you need DP
# Here's a template to get started on that
dp = [[-1 for _ in range(N)] for _ in range(N)]
def solve(i, j):
    # TODO: implement this function
    # (What are i and j?)
    return -1;

def nikola():
    return -1 # return solve(?, ?)

n = int(input())
for i in range(1, n + 1):
    a[i] = int(input())

print(nikola())
