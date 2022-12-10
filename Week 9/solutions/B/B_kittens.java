import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!

    static int[] parent = new int[100 + 5];
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(in.readLine());

        
        // This problem's input describes all the parent-child relationships we need to know
        // to find the path to the root from a given node. We can store the parent of each node
        // and then walk up the parent chain until we reach the root.


        Arrays.fill(parent, -1); // we know we're at the root if parent[i] == -1
        String s;
        while(true){
            s = in.readLine();
            if(s.equals("-1")) break;
            StringTokenizer st = new StringTokenizer(s);
            int p = Integer.parseInt(st.nextToken());
            while(st.hasMoreTokens()){
                int child = Integer.parseInt(st.nextToken());
                parent[child] = p;
            }
        }
        while(k != -1){
            System.out.print(k + " ");
            k = parent[k];
        }
        System.out.println();
    }
}