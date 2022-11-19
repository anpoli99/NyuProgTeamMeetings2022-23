
def validate(x, y, z):
    if x + y == z or x * y == z:
        return True
    return False

qr = int(input())
for _ in range(qr):
    x, y, z = map(int, input().split())
    # Division (x / y = z) is really the same as multiplication (x = y * z)
    # The numbers are so small it probably won't matter, but we can avoid
    # precision by only checking addition/multiplication, skipping subtraction/division
    ok = validate(x, y, z) or validate(x, z, y) or validate(y, z, x)
    # a small bonus: multiplication is commutative, so we only have to check 3 cases
    if ok:
        print("Possible")
    else:
        print("Impossible")