

def phonelist(n, s):
    # Input: n, s, the string as described in the problem statement
    # Output: True or False
    # Your code here
    return True

qrys = int(input())
for _ in range(qrys):
    n = int(input())
    s = []
    for _ in range(n):
        s.append(input().strip())
    print("YES" if phonelist(s) else "NO")