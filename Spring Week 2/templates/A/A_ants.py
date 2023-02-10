import sys
# Parameters:
# Input: (N,L) as described in the problem statement
# positions: a list of the ants' positions
# Return: list of two integers as described in the problem statement
def ants(N,L, positions):
    #Your code here
    return [0,0]

queries = int(input())
all_inputs = []
for line in sys.stdin:
    if(line == "#\n") : break # You can manually end input with a '#'
    line_ints = list(map(int, line.split()))
    for i in line_ints:
        all_inputs.append(i)

ptr = 0
for _ in range(queries):
    L = all_inputs[ptr]
    ptr += 1
    N = all_inputs[ptr]
    ptr += 1
    positions = []
    for _ in range(N):
        positions.append(all_inputs[ptr])
        ptr += 1
    print(*ants(N,L,positions))
