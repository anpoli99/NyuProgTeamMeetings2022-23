# Input format: x,y = queried point
# Return: list of ints of the shortest path from (0,0) to (x,y)
#         return empty list if no path exists

def solve(x,y):
    return [] # This is a placeholder

qr = int(input())
for tc in range(1,qr+1):
    tc,x,y = map(int,input().split())
    print(tc,end=" ")
    ans = solve(x,y)
    if not ans:
        print("NO PATH")
    else:
        print(len(ans), *ans)