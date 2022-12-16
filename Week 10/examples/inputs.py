
# Read a line
line = input() # This is the foundation of getting input from stdin in python

# Read 5 integers on a single line
# 1 2 3 4 5

a = list(map(int, input().split()))  # doesn't matter how many numbers there are

# Read 5 integers on 5 lines
# 1
# 2
# 3
# 4
# 5
a = []
for i in range(5):
    a.append(int(input()))

# Read an integer, followed by an unknown number of strings
x, *s = input().split()
x = int(x)

# Read a double on a single line
# 1.234
x = float(input())

# Great! Now let's say we have our output in a list of strings
# and we want to print it on a single line to stdout
# ['1', '2', '3', '4', '5']
print(' '.join(s))

# Let's say we wanted them on separate lines

for i in s:
    print(i)

# or
# print('\n'.join(s), end='')

# Let's say we wanted to read until end-of-file
# I can use the following
"""
while True:
    try:
        line = input()
    except EOFError:
        break
"""


# If we need really fast input, we can use the following
import sys

def readline():
    return sys.stdin.readline().strip() # Calling the system directly saves some time

# Read a line
line = readline()

# Read 5 integers on a single line
# 1 2 3 4 5
a = list(map(int, readline().split()))


# Let's say I wanted to read until end-of-file
# I can use the following
"""
while True:
    try:
        line = readline()
    except EOFError:
        break
"""
