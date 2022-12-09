def kitten(a, k):
    # Input format: k is the kitten's number
    # 'a' is a list of lists, where each a[i] has a list of branches 
    # described in the problem statement
    return None

k = int(input())
a = []
for i in range(k):
    a.append(list(map(int, input().split())))
    if a[i][0] == -1: break

print(kitten(a, k))
