from queue import deque 

# Helper function to format the output
def format_output(dq):
    # Don't use +=! It's O(n^2) and will TLE on this problem
    if len(dq) == 0:
        return "[]"
    res = [str(x) + "," for x in dq]
    res[-1] = res[-1][:-1]
    return "[" + "".join(res) + "]"


def integerlists(commands, a):
    # The basic idea here is we'll use a boolean to track if the list is reversed
    # We'll store the data in a deque, and if the list is reversed, we can remove from the back instead
 
    dq = deque(a)
    reversed = False
    for cmd in commands:
        if cmd == 'D':
            if len(dq) == 0:
                return "error"
            if reversed:
                dq.pop()
            else:
                dq.popleft()
        else:
            reversed = not reversed

    if reversed:
        dq.reverse()

    return format_output(dq)


trials = int(input())
for i in range(trials):
    commands = input()
    n = int(input())
    a = input()
    a = a[1:-1]
    a = a.split(",")
    a = [int(x) for x in a] if a[0] != "" else []
    print(integerlists(commands, a))
        


