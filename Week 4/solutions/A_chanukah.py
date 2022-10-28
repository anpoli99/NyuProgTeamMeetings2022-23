

def chanukah(n, k):
    # There's also a formula: n * (n + 1) / 2 + n
    # But the constraints are small enough that we can just count each candle
    res = 0
    for i in range(1, n + 1):
        res += i + 1 # + 1 for the shama
    
    return res


for _ in range(int(input())):
    k, n = map(int, input().split())
    print(k, chanukah(n, k))