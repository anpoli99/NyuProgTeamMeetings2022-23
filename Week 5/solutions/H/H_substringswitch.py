
def substringswitheroo(a, b):
    # Here's an example of where hashing can be useful:
    # We can hash the number of times each character appears in a substring
    # of a, and then check if the same substring of b has the same hash.
    p = 1319 # any prime number > N is fine
    # If it's less than N we might get collisions
    m1 = 10 ** 9 + 7
    m2 = 10 ** 9 + 9

    v1 = [0] * 256
    v2 = [0] * 256
    v1[0] = v2[0] = 1
    for i in range(1, 256):
        v1[i] = (v1[i - 1] * p) % m1
        v2[i] = (v2[i - 1] * p) % m2
    n = len(a)
    hashes = set()
    for i in range(n):
        h1 = 0
        h2 = 0
        for j in range(i, n):
            h1 = (h1 + v1[ord(b[j])]) % m1
            h2 = (h2 + v2[ord(b[j])]) % m2
            hashes.add((h1 << 32) + h2)
    idx = 0
    length = 0
    for i in range(n):
        h1 = 0
        h2 = 0
        for j in range(i, n):
            h1 = (h1 + v1[ord(a[j])]) % m1
            h2 = (h2 + v2[ord(a[j])]) % m2
            if ((h1 << 32) + h2) in hashes:
                if j - i + 1 > length:
                    length = j - i + 1
                    idx = i
    if length == 0:
        return "NONE"
    return a[idx:idx + length]

qr = int(input())
for i in range(qr):
    a = input()
    b = input()
    print(substringswitheroo(a, b))