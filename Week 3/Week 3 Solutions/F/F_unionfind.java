import java.io.*;
import java.util.*;

class Main{
    /*
    * This is a linked list problem, but the key here is an idea called "path compression".
    * When we find the final destination of a node, since we know that we're not going to
    * change the structure in between the node and the destination, we can have the node
    * point directly to the destination. This makes the problem O(n log n) instead of O(n^2).
    * You can reduce this to O(n) by always making the root the node with the smaller size,
    * but that's not necessary for this problem.
    *
    * An alternate implementation would store root[i] = i if i is it's own root.
    * It's not uncommon to see root[i] = 0 or root[i] = -1 instead, because it makes some parts of 
    * the implementation easier.
    */
    static int[] root;
    static int find(int x){
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
        root = new int[n + 1];
        Arrays.fill(root, -1);
        StringBuilder output = new StringBuilder();
        while(q-- > 0){
            st = new StringTokenizer(in.readLine());
            char c = st.nextToken().charAt(0);
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            if(c == '?'){
                if(find(a) == find(b)){
                    output.append("yes\n");
                }else{
                    output.append("no\n");
                }
            }else{
                a = find(a);
                b = find(b);
                if(a != b){
                    // We might create a cycle if a and b are already connected.
                    root[a] = b;
                }
            }
        }
        System.out.print(output);

    }
}
