
# You may want to use this union-find template
root = []
sz = []
def find(x):
    global root
    if root[x] == -1:
        return x
    root[x] = find(root[x])
    return root[x]

def join(x,y):
    global root, sz
    x = find(x)
    y = find(y)
    if x != y:
        root[x] = y
        sz[y] += sz[x]

#input format: s is 2d list of size [n][2] where s[i][0] and s[i][1] are the new friends
#output format: list of size [n] where the i-th element is the size of the new friend group
def virtualfriends(n, s):
    global root, sz
    root = [-1] * (2 * n) # (why 2 * n?)
    sz = [1] * (2 * n)

    # Declare a dictionary to store the names of the people
    names = {}
    res = []
    for i in range(n):
        # If the name is not in the dictionary, add it
        if s[i][0] not in names:
            names[s[i][0]] = len(names)
        if s[i][1] not in names:
            names[s[i][1]] = len(names)
        # Join the two names
        join(names[s[i][0]], names[s[i][1]])
        # Find the size of the group
        res.append(sz[find(names[s[i][0]])])
    return res

qrys = int(input())
for i in range(qrys):
    n = int(input())
    s = []
    for j in range(n):
        s.append(input().split())
    for x in virtualfriends(n,s):
        print(x)