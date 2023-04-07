import java.util.*;
import java.io.*;

/*
Here is an example of using a segment tree.
This file takes 'n', the length of an array, and n integers as input.
(Note: 1 <= A[i] <= n for all i)
It then prints the number of inversions in the array.
An inversion is a pair of indices (i,j) such that i < j and a[i] > a[j].
*/

class Main{
    static class Tree{
        int a, b, m; // m = midpoint; convenient to store directly
        Tree left = null, right = null;
        int count = 0;
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
                count += v;
                return;
            }
            if(k <= m) left.update(k, v);
            else right.update(k, v);
            // Store the information about the children in the parent
            count = left.count + right.count;
        }
        int query(int l, int r){
            if(l <= a && b <= r) return count; // Subtree is completely contained in [l,r]
            if(r < a || b < l) return 0; // Subtree is completely outside [l,r]
            // ^ Important note! For other problems, the default value may not be 0
            // Ex., for the minimum value, the default value should be infinity (or some large number)
            return left.query(l, r) + right.query(l, r); // Subtree is partially contained in [l,r]
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Tree t = new Tree(1, n);
        long inversions = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            int x = Integer.parseInt(st.nextToken());
            inversions += t.query(x + 1, n);
            t.update(x, 1);
        }
        System.out.println(inversions);
    }
}