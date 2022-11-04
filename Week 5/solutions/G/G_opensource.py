def opensource(lines):
    ans = []
    # We'll use this to store the users for each projects:
    members = {}
    # We'll use this to store how many projects each user is in:
    user_projects = {}

    projects = [lines[0]]
    current = lines[0]
    members[current] = set()
    for i in range(1, len(lines)):
        is_new_project = False
        for c in lines[i]:
            is_new_project |= c.isupper()
        if is_new_project:
            current = lines[i]
            projects.append(current)
            members[current] = set()
        elif lines[i] not in members[current]:
            members[current].add(lines[i])
            user_projects[lines[i]] = user_projects.get(lines[i], 0) + 1
    for s in projects:
        ct = 0
        for t in members[s]:
            ct += user_projects[t] == 1
        ans.append((s, ct))
    ans.sort(key = lambda x: (-x[1], x[0]))
    return ans

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