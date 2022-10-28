


    # writing this to be generic means we only have to write it once
def calculate_distance(distances, times, target_time):
    # This function tells us how far we will travel in a given time
    current_distance, current_time = 0, 0
    for i in range(len(times)):
        next_time = current_time + times[i]
        if next_time > target_time:
            remaining_time = target_time - current_time
            current_distance += remaining_time * (distances[i] / times[i])
            break
        else:
            current_distance += distances[i]
            current_time = next_time
    return current_distance

def travelling_monk(a, d, ascent_times, descent_times, ascent_dists, descent_dists):
    total_time, total_dist = 0, 0
    for i in range(a):
        total_time += ascent_times[i]
        total_dist += ascent_dists[i] 
    
    lo, hi = 0, total_time
    for i in range(100):
        mid = (lo + hi) / 2
        dist_ascending = calculate_distance(ascent_dists, ascent_times, mid)
        dist_descending = calculate_distance(descent_dists, descent_times, mid)
        if dist_ascending < total_dist - dist_descending:
            lo = mid
        else:
            hi = mid

    return lo


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
