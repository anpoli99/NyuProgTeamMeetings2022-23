

def fiftyshades(s):
    # Your code to check if a string 's' is valid goes here
    return None # This is a placeholder, replace it with your code

q = int(input())
ttl = 0
for i in range(q):
    s = input()
    if fiftyshades(s):
        ttl += 1

if ttl == 0:
    print("I must watch Star Wars with my daughter")
else:
    print(ttl)
