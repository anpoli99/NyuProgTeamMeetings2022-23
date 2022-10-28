from collections import deque

# With a queue of all people, this problem becomes solvable in linear time
# We can keep a queue of the people in front of a given person representing each cut
# It's not necessary to traverse the entire list when a cut happens;
# We can just check when the person who was cut is in the front of the queue
# I'll implement with a deque so we can simulate a cut by adding a person to the front

n = int(input())

# A tricky part here is we're given people as strings instead of integers
# A dictionary let's us index a person by their name

# A better approach would be to map each string to an integer, and then run
# the program using the integers as indices. This would mean we don't have
# to keep calling the dict, which takes time. I think the version here is
# more readable though.
line = deque()
cuts = {}
deleted = set()
for i in range(n):
    line.append(input())

q = int(input())

for i in range(q):
    query = input().split()
    if(query[0] == 'cut'):
        x,y = query[1], query[2]
        if y not in cuts:
            cuts[y] = deque()
        cuts[y].append(x)
    else: # query[0] == 'leave'
        x = query[1]
        deleted.add(x)

while len(line) > 0:
    person = line[0]
    if person in cuts and len(cuts[person]) > 0:
        line.appendleft(cuts[person].popleft())
    else:
        if person not in deleted:
            print(person)
        line.popleft()

