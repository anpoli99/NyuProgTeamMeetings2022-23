from queue import Queue

INF = 10 ** 9 # useful way to keep track of infinity as a really large number

#input format: for each index i, related[i] is a list of indices adjacent to i
def horrorlist(n, horror_movies, related):
    horror_index = [INF] * n
    q = Queue()
    for i in range(len(horror_movies)): 
        horror_index[horror_movies[i]] = 0
        q.put(horror_movies[i])

    while not q.empty():
        curr = q.get()
        for i in related[curr]:
            if horror_index[i] == INF:
                horror_index[i] = horror_index[curr] + 1
                q.put(i)

    highest_score, best_index = -1, 0
    for i in range(n):
        if horror_index[i] > highest_score:
            highest_score = horror_index[i]
            best_index = i

    
    return best_index


n,h,l = map(int, input().split())
horror_movies = list(map(int, input().split()))
related = [ [] for i in range(n) ]
for i in range(l):
    u,v = map(int, input().split())
    related[u].append(v)
    related[v].append(u)

print(horrorlist(n, horror_movies, related))