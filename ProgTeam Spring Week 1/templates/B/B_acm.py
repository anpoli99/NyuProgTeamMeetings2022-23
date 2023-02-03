# Place any auxilary variables you need here
time_solved = 0
score, penalty = 0, 0
while True:
    line = input()
    if line == "-1":
        break
    time_solved, problem, correct = line.split()
    time_solved = int(time_solved)
    if correct == "right":
        # Your code here
    else:
        # Your code here
    
print(score, penalty)