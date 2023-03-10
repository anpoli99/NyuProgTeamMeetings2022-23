
#Input n; number of students. 
#      students; iist of students scores
# Output: maximum sum of team-strengths
def icpcteam(n, students):
    # Your code here
    return 0


cases = int(input())
for _ in range(cases):
    n = int(input())
    students = map(int, input().split())
    print(icpcteam(n, students))