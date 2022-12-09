import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!
    static class Edge{
        int u,v,weight;
        public Edge(int u, int v, int weight){
            this.u = u;
            this.v = v;
            this.weight = weight;
        }
    }
    static boolean feastforcats(int c, int m, Edge[] edges){
        // Input format: 'c' is the number of cats, 'm' is the amount of milk and 'edges' is an array of 'c * (c - 1) / 2' edges
        return false; // Return true if you have enough milk to feed all the cats, false otherwise
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(in.readLine());
        while(q-- > 0){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int m = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            Edge[] edges = new Edge[c * (c - 1) / 2];
            for(int i = 0; i < edges.length; i++){
                st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                edges[i] = new Edge(u,v,weight);
            }
            System.out.println(feastforcats(c,m,edges) ? "yes" : "no");
        }
    }
}