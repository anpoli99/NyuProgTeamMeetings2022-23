import sys

# Input: N and A, where A is a list of N integers
# Output: True if the list is Jolly, False otherwise
def jollyjumpers(N,A):
    #Your code here
    return True

for line in sys.stdin:
    if(line == "#\n") : break # You can manually end input with a '#'
    line_ints = list(map(int, line.split()))
    N = line_ints[0]
    A = line_ints[1:]
    print("Jolly" if jollyjumpers(N,A) else "Not jolly")