


def travelling_monk(a, d, ascent_times, descent_times, ascent_dists, descent_dists):
    # Your code to find the time when the heights are equal goes here
    return -1


a, d = map(int, input().split())
ascent_times, ascent_dists = [], []
descent_times, descent_dists = [], []
for i in range(a):
    new_ascent_dist, new_ascent_time = map(int, input().split())
    ascent_times.append(new_ascent_time)
    ascent_dists.append(new_ascent_dist)


for i in range(d):
    new_descent_dist, new_descent_time = map(int, input().split())
    descent_times.append(new_descent_time)
    descent_dists.append(new_descent_dist)

print(travelling_monk(a, d, ascent_times, descent_times, ascent_dists, descent_dists))
