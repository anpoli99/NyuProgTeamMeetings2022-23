import java.io.*;
import java.util.*;

class Main{
    static void queueExample(){
        Queue<Integer> q = new LinkedList<>(); // We can declare a queue using the LinkedList class
        q.add(3); // Add an element to the end of the queue
        q.add(1);
        q.add(4);

        System.out.println(q.peek()); // Peek at the front of the queue

        System.out.println(q.poll()); // Remove and return the front of the queue

        System.out.println("The size of the queue is " + q.size()); // Get the size of the queue

        if(q.isEmpty()){  // Check if the queue is empty
            System.out.println("The queue is empty");
        }
        else{
            System.out.println("The queue is not empty");

        }
    }
    static void stackExample(){
        // We can use an ArrayList as a stack, but Java has a Stack class, so I'll show that here
        Stack<Integer> s = new Stack<>(); // We can declare a stack using the Stack class
        s.push(3); // Add an element to the top of the stack
        s.push(1);
        s.push(4);

        System.out.println(s.peek()); // Peek at the top of the stack

        System.out.println(s.pop()); // Remove and return the top of the stack

        System.out.println("The size of the stack is " + s.size()); // Get the size of the stack

        if(s.isEmpty()){  // Check if the stack is empty
            System.out.println("The stack is empty");
        }
        else{
            System.out.println("The stack is not empty");

        }
    }
    static void dequeExample(){
        Deque<Integer> d = new ArrayDeque<>(); // We can declare a deque using the ArrayDeque class
        d.addLast(3); // Add an element to the end of the deque
        d.addLast(1);
        d.addLast(4);

        System.out.println(d.peekLast()); // Peek at the end of the deque

        d.addFirst(2); // Add an element to the front of the deque
        d.addFirst(7);
        d.addFirst(1); 

        System.out.println(d.peekFirst()); // Peek at the front of the deque

        System.out.println(d.pollLast()); // Remove and return the end of the deque

        System.out.println(d.pollFirst()); // Remove and return the front of the deque

        System.out.println("The size of the deque is " + d.size()); // Get the size of the deque

        if(d.isEmpty()){  // Check if the deque is empty
            System.out.println("The deque is empty");
        }
        else{
            System.out.println("The deque is not empty");

        }

        // ArrayDeque doesn't directly support random access
        // But we can call toArray() to get an array representation of the deque
        // This takes O(n) per call; if you need to this a lot, you should probably implement your own deque
        Integer[] arr = d.toArray(new Integer[0]);
        System.out.println(Arrays.toString(arr));
    }
    static void linkedListExample(){
        // If the normal queue, stack, and deque are not enough, we can use a linked list
        // Java has a built in linked list class called list, but if we want something more general
        // We can implement our own linked list using indices in an array
        int n = 10;
        
        // For a doubly linked list, we can store the next and previous nodes for each index

        int[] next = new int[n + 1];
        int[] prev = new int[n + 1];
        
        for(int i = 1; i <= n; i++){
            if(i != n) next[i] = i + 1;
            if(i != 1) prev[i] = i - 1;
        }

        remove(5, next, prev); 
        remove(8, next, prev);
        remove(9, next, prev);

        insertAfter(2, 9, next, prev);


        // We can iterate over the whole list by following the next pointers
        int start = 1;
        while(start != 0){
            System.out.print(start + " ");
            start = next[start];
        }
        System.out.println();

        
        // For more complex problems, we can keep track of different properties of the nodes
        // And have them point to nodes with other relationships
    }
    static void remove(int x, int[] next, int[] prev){
        // This let's us remove x from the array list, by having the neighbors of x point to each other
        next[prev[x]] = next[x];
        prev[next[x]] = prev[x];
    }
    static void insertAfter(int x, int y, int[] next, int[] prev){
        // We can insert y after x by having y point to the node after x, and then fixing all the other pointers
        next[y] = next[x];
        prev[y] = x;
        next[x] = y;
        prev[next[y]] = y;
    }
    public static void main(String[] args) throws Exception{
    	queueExample();
    	stackExample();
    	dequeExample();
    	linkedListExample();
    }	
}
