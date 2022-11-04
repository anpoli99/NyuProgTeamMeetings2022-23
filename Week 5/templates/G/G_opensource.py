
# Format: return a list with tuples of the form (project_name, number_of_members)
def opensource(lines):
    # Your code to find the number of members per project goes here
    return []

lines = []
while True:
    s = input()
    if s == '1':
        ans = opensource(lines)
        for p in ans:
            print(p[0], p[1])
        lines = []
    elif s == '0':
        break
    else:
        lines.append(s)