
def find_missing_gnome(gnomes): 
    n = len(gnomes)
    for i in range(1, n - 1):
        sorted = True
        prev = -1
        for j in range(0, n):
            if i == j:
                continue
            sorted = sorted and gnomes[j] >= prev
            prev = gnomes[j]

        if sorted:
            return i


trials = int(input())
for trial in range(trials):
    gnomes = list(map(int, input().split()))
    n = gnomes[0]   
    gnomes = gnomes[1:]
    print(  find_missing_gnome(gnomes) )