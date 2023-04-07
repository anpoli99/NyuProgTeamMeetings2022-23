import java.util.*;
import java.io.*;

/*
Here is a less typical use of a segment tree; we will use it to find the
kth largest element in a (multi)set.

This file takes 'Q', the number of queries, and Q lines of input.
Each line is either 'add x', 'del x', or 'kth k'.
- 'add x' adds x to the multiset
- 'del x' deletes one occurrence of x from the multiset
- 'kth k' prints the kth largest element in the multiset
(Note: 1 <= x <= Q <= 10^5; assume there are at least k elements in the multiset at time of query)
The typical approach to this problem is to use a balanced binary search tree,
but segment trees are extremely versatile.
*/

class Main{
    static class Tree{
        int a, b, m; // m = midpoint; convenient to store directly
        Tree left = null, right = null;
        int size = 0;
        Tree(int a, int b){
            this.a = a;
            this.b = b;
            m = (a + b) / 2;
            if(a != b){
                left = new Tree(a, m);
                right = new Tree(m + 1, b);
            }
        }
        void update(int k, int v){
            if(a == b){
                // For all segment tree problems, update the terminal node here
                size += v;
                return;
            }
            if(k <= m) left.update(k, v);
            else right.update(k, v);
            // Store the information about the children in the parent
            size = left.size + right.size;
        }
        int kth_largest(int k){
            if(a == b) return a;
            if(k <= left.size) return left.kth_largest(k);
            else return right.kth_largest(k - left.size);
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        Tree t = new Tree(1, q);
        for(int i = 1; i <= q; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            int x = Integer.parseInt(st.nextToken());
            if(command.equals("add")) t.update(x, 1);
            else if(command.equals("del")) t.update(x, -1);
            else System.out.println(t.kth_largest(x));
        }
    }
}

/*
Example input:
11
add 1
add 2
add 3
kth 2
kth 3
del 2
add 6
kth 2
kth 3
add 5
kth 3

Expected output:
2
3
3
6
5
*/
