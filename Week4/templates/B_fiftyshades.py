

def fiftyshades(s):
    s = s.lower() # helpful to know library functions :)
    # We could also do something like:
    """
    for i in range(len(s)):
        if s[i] >= 'A' and s[i] <= 'Z':
            s[i] += 'a' - 'A'
    """
    # Check if s contains "pink" or "rose"
    if "pink" in s or "rose" in s:
        return True
    
    # More useful library functions :)

    # We could also do something like:
    """
    for i in range(max(len(s) - 3, 0)):
        if s[i:i+4] == "pink" or s[i:i+4] == "rose":
            return True
    """

    
    return False

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





