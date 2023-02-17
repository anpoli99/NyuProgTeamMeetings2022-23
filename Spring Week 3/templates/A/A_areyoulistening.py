# Input format: c = Your location
# n = # of enemy spies
# cen[i] = Location of enemy spy i
# rad[i] = Radius of enemy spy i
# Output: Return maximum communication range as specified in the problem statement
def solve(c, n, cen, rad):
    return -1 # This is a placeholder

x,y,n = map(int,input().split())
c = [x,y]
cen = []
rad = []
for i in range(n):
    cen.append(list(map(int,input().split())))
    rad.append(cen[-1].pop())

print(solve(c,n,cen,rad))
