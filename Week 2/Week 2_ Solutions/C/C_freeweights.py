

def validate(n, a, b, max_weight):
    # Greedily remove all weights we can; we'll always be able to pair these
    # Check if remaining weights are paired together

    # remove all i in a <= max_weight
    a_remaining = [i for i in a if i > max_weight] 
    b_remaining = [i for i in b if i > max_weight]
    '''
    #equivalent to:
    a_remaining = []
    for i in a:
        if i > max_weight:  
            a_remaining.append(i)

    b_remaining = []
    for i in b:
        if i > max_weight:  
            b_remaining.append(i)
    '''


    if len(a_remaining) % 2 != 0:
        # can't pair an odd number of weights
        return False
    
    if len(b_remaining) % 2 != 0:
        return False
    
    for i in range(0, len(a_remaining), 2):
        if a_remaining[i] != a_remaining[i + 1]:
            return False
    
    for i in range(0, len(b_remaining), 2):
        if b_remaining[i] != b_remaining[i + 1]:
            return False

    return True



def freeweights(n, a, b):
    lo, hi = 0, 10**9
    while lo < hi:
        mid = (lo + hi) // 2
        if validate(n, a, b, mid):
            hi = mid
        else:
            lo = mid + 1
    
    return lo


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(freeweights(n, a, b))
