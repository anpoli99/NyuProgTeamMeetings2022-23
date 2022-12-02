#input format: s and t as strings
def doublepassword(s,t):
    # The input is small enough that we can use brute force
    ans = 0
    for i in range(10000):
        p = str(i)
        while len(p) < 4: p = "0" + p
        okay = True
        for j in range(4):
            if s[j] != p[j] and t[j] != p[j]: okay = False  
        if okay: ans += 1
    return ans
    # alternate solution
    # ct = 0
    # for i in range(4): 
    #   ct += (s[i] != t[i])
    # return (1 << ct) # 2^{mismatched digits}


s = input()
t = input()
print(doublepassword(s,t))