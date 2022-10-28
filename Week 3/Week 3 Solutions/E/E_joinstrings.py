# format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
# 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
def joinstrings(n, s, a, b):
    # First we'll find the order of the indices in the final string, then we can concatenate them at the end
    # To do this, notice that when we concatenate two strings (i)(j), it becomes one string
    # beginning with 'i' and ending with 'j'
    # So the only thing we need to know to join two strings is which original string was 
    # the first and which was the last
    
    next = [-1] * (n + 1) # next[i] = j if 'j' is the index of the string concatenated after 'i'
    last = [0] * (n + 1) # last[i] will store the last string concatenated to 'i'
                        # For example, if (1 2) is concatenated to (3 4), then last[1] = 4, next[1] = 2

    for i in range(1, n + 1):
        last[i] = i # Initially, each string is its own last string

    is_beginning = [True] * (n + 1) # is_beginning[i] = True if 'i' is the first string in the final string

    for i in range(1, n):
        x,y = a[i], b[i]
        next[last[x]] = y # 'y' is the string concatenated to the end of 'x'
        last[x] = last[y] # 'x' now ends with the same string as 'y'
        is_beginning[y] = False # 'y' is no longer the beginning of a string

    # Now we can find the beginning of the final string
    beginning = 1
    while not is_beginning[beginning]:
        beginning += 1
    
    # Join the strings to get the final string
    final_indices = []
    for i in range(n):
        final_indices.append(beginning)
        beginning = next[beginning]
    
    return ''.join([s[i] for i in final_indices])

n = int(input())
s = [""]
for i in range(n):
    s.append(input())

a, b = [0], [0]
for i in range(n - 1):
    x,y = map(int, input().split())
    a.append(x)
    b.append(y)

print(joinstrings(n, s, a, b))
