from queue import Queue

INF = 10 ** 9 # useful way to keep track of infinity as a really large number

#input format: for each index i, related[i] is a list of indices related to i
def horrorlist(n, horror_movies, related):
    # Your code to find the index with the highest horror-index goes here
    return None # This is a placeholder, replace it with your code


n,h,l = map(int, input().split())
horror_movies = list(map(int, input().split()))
related = [ [] for i in range(n) ]
for i in range(l):
    u,v = map(int, input().split())
    related[u].append(v)
    related[v].append(u)

print(horrorlist(n, horror_movies, related))