# This but in python
import sys

# The judge returns in the format: "ACCESS DENIED (time ms)"
# This function should extract the time from the string
def extract_time(s):
    # I left this implementation to you
    # A recommendation: I'd advise testing it on its own first then solving the problem
    return -1

# Call this function to query the judge
# Returns the time it took to check the password or 0 if the password is correct
def query(q):
    print(q)
    sys.stdout.flush() # ALWAYS flush after printing on an interactive problem!
    response = input().strip()
    if response == "ACCESS GRANTED":
        return 0
    return extract_time(response)

# add any auxilary variables you need here
while True:
    guess = "" # Your code here to generate a guess
    time = query(guess)
    if time == 0: 
        break # You found the password!
    # Your code here to update the parameters of the next guess