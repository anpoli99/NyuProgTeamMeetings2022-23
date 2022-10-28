
# input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
# return a pair with the optimal # of obstacles and the # of levels where that is possible
# note that the firefly cannot fly at a height of 0
def firefly(n, h, a, b):
    # Note that initially n = len(a) + len(b)
    n = n // 2

    # We can keep track of where each stalagmite ends and each stalactite begins
    # To do this, it's easier if we have the height of where the stalagtite begins instead of its length
    for i in range(n):
        b[i] = h - b[i]

    
    min_obstacles, num_levels = 10 ** 9, 0

    curr_obstacles = n

    # We can use a sliding window to find the minimum number of stalagmites that need to be removed
    # At each height, we'll advance the pointer as it passes the beginning/end of obstacles 
    a.sort()
    b.sort()

    a_ptr, b_ptr = 0, 0
    for i in range(1, h + 1):
        while a_ptr < n and a[a_ptr] < i:
            a_ptr += 1
            curr_obstacles -= 1
        while b_ptr < n and b[b_ptr] < i:
            b_ptr += 1
            curr_obstacles += 1

        if curr_obstacles < min_obstacles:
            min_obstacles = curr_obstacles
            num_levels = 1
        elif curr_obstacles == min_obstacles:
            num_levels += 1


    return min_obstacles, num_levels


n, h = map(int, input().split())
a, b = [], []
for i in range(n):
    if i % 2 == 0:
        a.append(int(input()))
    else:
        b.append(int(input()))

p, q = firefly(n, h, a, b)
print(p, q)
