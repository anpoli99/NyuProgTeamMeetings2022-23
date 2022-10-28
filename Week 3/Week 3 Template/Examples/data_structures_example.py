from queue import LifoQueue as Stack
from queue import Queue
from collections import deque


def queue_example():
    q = Queue()
    
    # Add elements to the queue
    q.put(3)
    q.put(1)
    q.put(4)

    # Peek at the first element
    print(q.queue[0])

    # Remove elements from the queue
    print(q.get()) # 3

    # Check if the queue is empty
    print(q.empty()) # False

    # Get the size of the queue
    print(q.qsize()) # 2
    
def stack_example():
    # We can just use a list as a stack; but I'll show an example with a Stack also.
    s = Stack()

    # Add elements to the stack
    s.put(3)
    s.put(1)
    s.put(4)

    # Peek at the top element
    print(s.queue[0])

    # Remove elements from the stack
    print(s.get()) # 4

    # Check if the stack is empty
    print(s.empty()) # False

    # Get the size of the stack
    print(s.qsize()) # 2

def deque_example():
    dq = deque()

    # Add elements to the back of the deque
    dq.append(3)
    dq.append(1)
    dq.append(4)

    # Peek at the first element
    print(dq[0])

    # Peek at the last element
    print(dq[-1])

    # Add elements to the front of the deque
    dq.appendleft(2)
    dq.appendleft(5)
    
    # Remove elements from the front of the deque
    print(dq.popleft()) # 5

    # Remove elements from the back of the deque
    print(dq.pop()) # 4

    # Check if the deque is empty
    print(len(dq) == 0) # False

    # Get the size of the deque
    print(len(dq)) # 3

    # Deques in python support random access in O(n) with a low constant factor
    
    # We can also iterate through the deque
    for i in dq:
        print(i)

def linked_list_example():
    #  If the normal queue, stack, and deque are not enough, we can use a linked list
    #  Python doesn't have a built-in generic linked list,
    #  but we can implement our own linked list using indices in a list

    n = 10 # The number of elements in the linked list
    next = [0] * (n + 1)
    prev = [0] * (n + 1)

    for i in range(1, n + 1):
        if i != 1:
            prev[i] = i - 1
        if i != n:
            next[i] = i + 1

    def remove(i):
        # We can remove an element from the linked list by having its neighbors point to each other
        next[prev[i]] = next[i]
        prev[next[i]] = prev[i]

    def insert_after(i, j):
        # Insert the jth element after the ith element
        # This can be done by making j point to the element after i, and then fixing all the other pointers
        next[j] = next[i]
        prev[j] = i
        prev[next[i]] = j
        next[i] = j
    
    remove(5)
    remove(8)
    remove(9)

    insert_after(2,9)

    # We can iterate through the linked list by starting at the first element and following the next pointers
    curr = 1
    output_string = ""
    while curr != 0:
        output_string += str(curr) + " "
        curr = next[curr]

    print(output_string)
    


queue_example()
stack_example()
deque_example()
linked_list_example()


