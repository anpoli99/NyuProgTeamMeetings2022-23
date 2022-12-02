
# You may want to use this union-find template
root = []
def find(x):
    global root
    if root[x] == -1:
        return x
    root[x] = find(root[x])
    return root[x]

def join(x,y):
    global root
    x = find(x)
    y = find(y)
    if x != y:
        root[x] = y

#input format: s is 2d list of size [n][2] where s[i][0] and s[i][1] are the new friends
#output format: list of size [n] where the i-th element is the size of the new friend group
def virtualfriends(n, s):
    global root
    root = [-1] * (2 * n) # (why 2 * n?)
    
    # Your code goes here
    return [0] * n #  This is a placeholder

qrys = int(input())
for i in range(qrys):
    n = int(input())
    s = []
    for j in range(n):
        s.append(input().split())
    for x in virtualfriends(n,s):
        print(x)