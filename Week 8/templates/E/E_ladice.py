
# Input: 'a' is a 2d list of size [b][2]
# Output: boolean list of size b; true if the sock can be put in the drawer, false otherwise
def ladice(n, l, a):
    # Your code goes here
    return [False] * n # This is a placeholder

n, l = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))

ans = ladice(n, l, a)
print(''.join(['LADICA\n' if ans[i] else 'SMECE\n' for i in range(n)]))
