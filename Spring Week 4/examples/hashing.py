
"""
    We'll be using this rolling hash class to solve the problem
    https://kattis.com/problems/hashing. It's written to be generic
    so you can copy and paste it into your own code, whenever you
    need a rolling hash.
"""
# Begin of rolling hash class (you need the boilerplate lines above too)
mod = 10**9 + 87 # A prime number
p1, p2 = 131, 499 # Two different primes; greater than size of alphabet (128 for strings)
N = 10**6 + 5 # Longer than the longest string


power1, power2 = [1] * N, [1] * N
invp1, invp2 = [1] * N, [1] * N
modpow = lambda a, b: pow(a, b, mod)


# Precomputing hashes is a lot faster; save log(n) time every time we use it.
pre_computed = False
def precompute():
    global pre_computed
    for i in range(1, N):
        power1[i] = (power1[i - 1] * p1) % mod
        power2[i] = (power2[i - 1] * p2) % mod
    invp1[N - 1] = modpow(power1[N - 1], mod - 2) # Modular inverse formula: x^(-1) == x^(m - 2) mod m
    invp2[N - 1] = modpow(power2[N - 1], mod - 2) # (Iff m is prime)
    for i in range(N - 2, -1, -1): # Compute the largest first, then just multiply by p1/p2 to get lower powers
        invp1[i] = (invp1[i + 1] * p1) % mod
        invp2[i] = (invp2[i + 1] * p2) % mod
    pre_computed = True

class rolling_hash:
    def __init__(self, s):
        global pre_computed
        if not pre_computed:
            precompute()
        self.s = s
        n = len(s)
        self.hash1 = [0] * (n + 1)
        self.hash2 = [0] * (n + 1)
        for i in range(n):
            self.hash1[i + 1] = (self.hash1[i] + ord(s[i]) * power1[i]) % mod
            self.hash2[i + 1] = (self.hash2[i] + ord(s[i]) * power2[i]) % mod
        
    def hash(self, l, r): # Hash of the substring [l, r] (0-indexed)
        r1 = (self.hash1[r + 1] - self.hash1[l] + mod) % mod
        r2 = (self.hash2[r + 1] - self.hash2[l] + mod) % mod
        r1 = (r1 * invp1[l]) % mod
        r2 = (r2 * invp2[l]) % mod
        return (r1 << 32) | r2

# End of rolling hash class
import sys

def fast_input(): # Faster input
    return sys.stdin.readline().strip()

if __name__ == "__main__":
    # Solving this problem becomes trivial with our rolling hash struct
    s = input()
    h = rolling_hash(s)
    qr = int(input())
    anss = []
    for _ in range(qr):
        l, r = map(int, fast_input().split()) 
        # r not inclusive
        r -= 1
        anss.append(h.hash(l, r)) 
    
    print("\n".join(map(str, anss))) # Faster than printing every answer individually
