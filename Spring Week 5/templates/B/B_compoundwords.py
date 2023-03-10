# To test this, I'd recommend having a file with the input called 'input.txt'
# and running: python3 (your file).py < input.txt

# Input: a list of all words
# Output: a list of all compound words
def compound_words(words):
    # Your code here
    return []


import sys

words = sys.stdin.read().strip().split()
print("\n".join(compound_words(words)))