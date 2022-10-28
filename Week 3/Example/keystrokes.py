
s = input()
prev = [-1] * (len(s) + 2)
next = [-1] * (len(s) + 2)

def remove(i):
    prev[next[i]] = prev[i]
    next[prev[i]] = next[i]

def insert(i, j):
    prev[next[i]] = j
    next[j] = next[i]
    next[i] = j
    prev[j] = i



cursor = 0


next_pointer = 1
output = ['.']
for c in s:
    if c == 'L':
        if prev[cursor] != -1:
            cursor = prev[cursor]
    elif c == 'R':
        if next[cursor] != -1:
            cursor = next[cursor]
    elif c == 'B':
        if cursor != 0:
            remove(cursor)
            cursor = prev[cursor]
    else:
        insert(cursor, next_pointer)
        cursor = next_pointer
        output.append(c)
        next_pointer += 1

cursor = next[0]
while cursor != -1:
    print(output[cursor], end='')
    cursor = next[cursor]



