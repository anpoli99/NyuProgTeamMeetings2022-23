def communicationsSatellite(n, x, y, r):
    # Input format: n is the number of satellite dishes
    # x,y,r are lists of length n describing each satellite dish
    return -1.0
    
n = int(input())
x,y,r = [0]*n, [0]*n, [0]*n
for i in range(n):
    x[i], y[i], r[i] = map(int, input().split())

print(communicationsSatellite(n, x, y, r))


