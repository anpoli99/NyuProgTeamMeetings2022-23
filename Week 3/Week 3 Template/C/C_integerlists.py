from queue import deque 



def integerlists(commands, a):
    """
    Your code here; You should return a string, "error" if one of the commands throws an error
                otherwise return the output formatted according to the problem specification
    """
    return None # This is just a placeholder; return the output string


trials = int(input())
for i in range(trials):
    commands = input()
    n = int(input())
    a = input()
    a = a[1:-1]
    a = a.split(",")
    a = [int(x) for x in a] if a[0] != "" else []
    print(integerlists(commands, a))
        


