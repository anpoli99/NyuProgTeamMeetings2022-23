
from queue import LifoQueue as Stack


# You don't need a Stack to solve this problem!
# But since it's data structures week, I'll use one anyway.
def reverse(a):
    # return a[::-1] If you're really pythonic you could just do this
    s = Stack()
    for i in a:
        s.put(i)
    ans = []
    while not s.empty():
        ans.append(s.get())

    return ans


n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

ans = reverse(a)
for i in ans:
    print(i)