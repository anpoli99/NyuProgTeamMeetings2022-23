from sys import stdin

# Each string is a line of input
# You can split the line into strings using the split() function:
# words = line.split()
def adding_words(lines):
    result = []
    # Your code to process the lines goes here
    return result


lines = []
for line in stdin:
    lines.append(line.strip())
    if line == '#':
        break

result = adding_words(lines)
for line in result:
    print(line)