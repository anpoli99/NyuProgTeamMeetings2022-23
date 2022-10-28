from queue import Queue

# This problem doesn't require a queue!
# But since it's data structures week, I'll use one anyway
def apaxiaaans(s):
    q = Queue()
    for c in s:
        q.put(c)

    answer = ""
    while not q.empty():
        c = q.get()
        if q.empty() or c != q.queue[0]:
            answer += c

    return answer


s = input()
print(apaxiaaans(s))
