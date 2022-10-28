
# The brute force approach is to handle each query with a list.
# We can traverse the whole list, and process the person in the query when we find them
# This is O(N * Q * |S|) time, which is fine for this problem
# (N = # of people, Q = # of queries, |S| = length of each string)
# If we had harsher constraints, we would need to use the other approach

n = int(input())
line = []
for i in range(n):
    line.append(input())

q = int(input())
for i in range(q):
    query = input().split()
    if(query[0] == 'cut'):
        x, y = query[1], query[2]
        next_line = []
        for person in line:
            if(person == y):
                next_line.append(x)
            next_line.append(person)

        line = next_line
    else: # query[0] == 'leave'
        x = query[1]
        line.remove(x) # O(N) time

for person in line:
    print(person)

