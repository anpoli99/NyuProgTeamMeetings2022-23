
import sys

# For this problem, I'm only including the Fast I/O methods for the template.
# The time limit is pretty tight for this problem; 
# You will probably TLE if you don't use them.

# Call this whenever you want to read a line from input
def fast_input():
    return sys.stdin.readline().strip()


n, q = map(int, fast_input().split())

# Feel free to put whatever preprocessing you need here

ans = [] # To make it fast enough, I kept a list of integers to store the answers
        # 1 = "yes\n" and 0 = "no\n"
for i in range(q):
    pass
    # Answer the queries here

# Then we can convert our answer list to a string
# join() is a lot faster than using a for loop to concatenate strings
print(''.join(map(lambda x: 'yes\n' if x else 'no\n', ans)))