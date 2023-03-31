import sys

# returns: -1 if the number is correct, 0 if the number is lower, 1 if the number is higher
def query(x):
    print(x)
    sys.stdout.flush() # ALWAYS flush after printing on an interactive problem!
    s = input().strip()
    if s == "correct":
        return -1
    elif s == "lower":
        return 0
    else:
        return 1

ans = -1 # This is a placeholder
# Your code here
print(ans) # You should still quit w/o using this line if you find the answer