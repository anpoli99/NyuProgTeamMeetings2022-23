

def fast_input():
    import sys
    return sys.stdin.readline().strip()

# Input format: a and b are lists containing n/m elements respectively
def cd(n, m, a, b):
    # Your code to find the maximum number of cds that can be bought goes here
    return -1 # Replace this line with your code


while True:
    n, m = map(int, fast_input().split())
    if n == 0 and m == 0:
        break
    a = []
    b = []
    for i in range(n):
        a.append(int(fast_input()))
    for i in range(m):
        b.append(int(fast_input()))
        
    print(cd(n, m, a, b))
