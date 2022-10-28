#include <bits/stdc++.h>
using namespace std;

void queue_example(){
    queue<int> q; // Nothing else needed to initialize a queue

    // We can push elements to the back of the queue with push()
    q.push(3);
    q.push(1);
    q.push(4);

    // We can pop elements from the front of the queue with pop()
    q.pop();

    // We can get the front element with front()
    cout << q.front() << endl; // 1
    q.pop();
    cout << q.front() << endl; // 4
    q.pop();

    // We can check if the queue is empty with empty()
    if(q.empty()) cout << "The queue is empty" << endl;
    else cout << "The queue is not empty" << endl;

    // We can get the size of the queue with size()
    q.push(2);
    q.push(7);
    q.push(1);
    q.push(8);
    cout << "The size of the queue is " << q.size() << endl;
}

void stack_example(){
    // Actually we can just use a vector, which has the added bonus of random access
    // But C++ does have a stack class:
    stack<int> s; 

    // We can push elements to the top of the stack with push()
    s.push(3);
    s.push(1);
    s.push(4);

    // We can pop elements from the top of the stack with pop()
    s.pop();

    // We can get the top element with top()
    cout << s.top() << endl; // 1

    // We can check if the stack is empty with empty()
    if(s.empty()) cout << "The stack is empty" << endl;
    else cout << "The stack is not empty" << endl;

    // We can get the size of the stack with size()
    s.push(4);
    s.push(5);
    s.push(6);
    cout << "The size of the stack is " << s.size() << endl;
}

void deque_example(){
    // A deque is a double ended queue, which means we can push and pop from both ends
    deque<int> d;

    // We can push elements to the back of the deque with push_back()
    d.push_back(3);
    d.push_back(1);
    d.push_back(4);

    // We can pop elements from the back of the deque with pop_back()
    d.pop_back();

    // We can push elements to the front of the deque with push_front()
    d.push_front(2);
    d.push_front(7);
    d.push_front(1);

    // We can pop elements from the front of the deque with pop_front()
    d.pop_front();

    // We can get the front element with front()
    cout << d.front() << endl; // 7

    // We can get the back element with back()
    cout << d.back() << endl; // 1

    // We can check if the deque is empty with empty()
    if(d.empty()) cout << "The deque is empty" << endl;
    else cout << "The deque is not empty" << endl;

    // We can get the size of the deque with size()
    cout << "The size of the deque is " << d.size() << endl;

    // deques support random access, so we can get the ith element with []
    for(int i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;
}

void linked_list_example(){
    // If the normal queue, stack, and deque are not enough, we can use a linked list
    // C++ has a built in linked list class called list, but if we want something more general
    // We can implement our own linked list using indices in a vector
    int n = 10;
    vector<int> next(n + 1);
    vector<int> prev(n + 1);
    // For a doubly linked list, we can store the next and previous nodes for each index
    for(int i = 1; i <= n; i++){
        if(i != n) next[i] = i + 1;
        if(i != 1) prev[i] = i - 1;
    }
    
    // (If you haven't seen this, this is a lambda function)
    // (It lets us define a function inside another function)
    auto remove = [&](int i){
        // Remove the ith element from the linked list
        // This can be done by making the neighbors of the ith element point to each other
        next[prev[i]] = next[i];
        prev[next[i]] = prev[i];
    };
    auto insert_after = [&](int i, int j){
        // Insert the jth element after the ith element
        // This can be done by making j point to the element after i, and then fixing all the other pointers
        next[j] = next[i];
        prev[j] = i;
        next[i] = j;
        prev[next[j]] = j;
    };

    remove(5);
    remove(8);
    remove(9);

    insert_after(2,9);
    
    // We can iterate over the whole list by following the next pointers
    int start = 1;
    while(start != 0){
        cout << start << " ";
        start = next[start];
    }
    cout << endl;

    // For more complex problems, we can keep track of different properties of the nodes
    // And have them point to nodes with other relationships
}

int main(){
    
    queue_example();
    stack_example();
    deque_example();
    linked_list_example();  
    
}
