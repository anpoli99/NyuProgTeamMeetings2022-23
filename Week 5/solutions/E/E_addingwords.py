from sys import stdin

UNKNOWN = 10**9 + 5
# Each string is a line of input
# You can split the line into strings using the split() function:
# words = line.split()
def adding_words(lines):
    result = []
    variables = {} # We can use a dictionary to store the variables
    values = {}
    for line in lines:
        words = line.split()
        if words[0] == "clear":
            variables.clear()
            values.clear()
        elif words[0] == "def":
            var = words[1]
            value = int(words[2])
            if var in variables:
                del values[variables[var]]
            variables[var] = value
            values[value] = var
        else: # word == "calc"
            equation = line[5:] # It wants the whole equation too, but that's just part of the original line
            sub = False
            value = 0
            for i in range(1, len(words), 2):
                var = words[i]
                if var not in variables:
                    value = UNKNOWN
                    break
                if sub:
                    value -= variables[var]
                else:
                    value += variables[var]
                sub = words[i + 1] == "-"
            if value not in values:
                value = UNKNOWN
            if value == UNKNOWN:
                result.append(equation + " unknown")
            else:
                result.append(equation + " " + values[value])
    return result


lines = []
for line in stdin:
    lines.append(line.strip())
    if line == '#':
        break

result = adding_words(lines)
for line in result:
    print(line)