N = 200 + 5
dist = [[0] * N for _ in range(N)]  
n = int(input())
while n > 0:
    mp = {}
    names = input().split()
    for i in range(n):
        mp[names[i]] = i
        for j in range(n):
            dist[i][j] = 0
        dist[i][i] = 1
    
    # We can modify Floyd-Warshall to be converting between currencies
    # by multiplying the exchange rate instead of adding. Then we want
    # to look for a cycle where the product of the exchange rates is
    # greater than 1. This is analogous to looking for a negative cycle
    # in the shortest path problem.

    m = int(input())
    for i in range(m):
        a, b, c = input().split()
        x, y = map(int, c.split(':'))
        dist[mp[a]][mp[b]] = y / x

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j])

    ok = True
    for i in range(n):
        if dist[i][i] > 1:
            ok = False
            break

    print("Ok" if ok else "Arbitrage")
    n = int(input())
    