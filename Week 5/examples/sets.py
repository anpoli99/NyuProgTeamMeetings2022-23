import bisect

# A set in python is unordered by default
# An unordered set is a set that stores elements in no particular order.
# It has O(1) time complexity for insertion, deletion, and search.
s = {1, 2, 3, 4, 5}
# To declare an empty set:
# s = set()
print(3 in s) # True
print(6 in s) # False

s.add(6)
s.remove(3)
print(3 in s) # False
print(6 in s) # True

# An unordered map is given by Dicts in Python
# An unordered map let's you associate a value with a key.
m = {"one": 1, "two": 2, "three": 3}
# To declare an empty dict:
# m = dict()
print(m["one"]) # 1
print("four" in m) # False
#print(m["four"]) throws KeyError: 'four'
m["four"] = 4
print("four" in m) # True
print(m["four"]) # 4

# Somewhat frustratingly in my opinion, Python doesn't have a built-in ordered set.
# You can copy one from online if you need one, or bisect with sorting may be fast enough
# but it's slower than sets in other language libraries (O(N) per insertion)
# For most of the problems in today's contest, removing/adding elements dynamically isn't
# necessary.
# If we wanted a built-in way to get a lower or upper bound, we could use bisect
# on just a regular sorted list.
# bisect.bisect_left returns the index of the first element that is greater than or equal to x
# bisect.bisect_right returns the index of the first element that is greater than x

lst = [1,3,5,7,9,11]

left = bisect.bisect_left(lst, 7) 
print(lst[left]) # 7
right = bisect.bisect_right(lst, 7)
print(lst[right]) # 9

left = bisect.bisect_left(lst, 8)
print(lst[left]) # 9
right = bisect.bisect_right(lst, 8)
print(lst[right]) # 9


left = bisect.bisect_left(lst, 12)
print(left == len(lst)) # True