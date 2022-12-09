import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!
    static class Edge{
        int v, weight;
        Edge(int v, int weight){
            this.v = v;
            this.weight = weight;
        }
    }
    static ArrayList<Edge>[] adj;
    static int frozenrose(int n, int c){
        // Input format: 'n' is the number of nodes, 'c' is the central node
        // 'adj' is a list of edges of length 'n + 1' (1-indexed, same as input)
        // 'adj' will be initialized so that adj[u] is a list of edges from node u
        // Return the minimum cost to ensure no water leaves from a sprinkler
        return -1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // A note about this problem; it reads until EOF, so if you type in the input manually,
        // you need paste the input all at once with this implementation, or put it in a file
        // and use the console pipeline to read from the file in stdin
        while(!in.ready()); // You could remove this line if you didn't want to ever paste in the input manually
        while(in.ready()){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            adj = new ArrayList[n + 1];
            for(int i = 1; i <= n; i++){
                adj[i] = new ArrayList<Edge>();
            }
            for(int i = 0; i < n - 1; i++){
                st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                adj[u].add(new Edge(v,weight));
                adj[v].add(new Edge(u,weight));
            }
            System.out.println(frozenrose(n,c));
        }
    }
}