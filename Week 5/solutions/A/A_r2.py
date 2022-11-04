

def r2(r1, s):
    diff = s - r1
    return s + diff


r1, s = map(int, input().split())
print(r2(r1, s))