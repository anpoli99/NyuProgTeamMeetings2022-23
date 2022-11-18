import java.io.*;
import java.util.*;

class Main{  
    // Make sure the class name is Main if you use this template
    static class Edge{
        int v, w;
        Edge(int v, int w){
            this.v = v;
            this.w = w;
        }
    }
    static final int V = 20000 + 5;
    static final int INF = (int)1e9 + 5;
    static ArrayList<Edge> adj[] = new ArrayList[V];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= v; i++) adj[i] = new ArrayList<Edge>();
        for(int i = 0; i < e; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            adj[x].add(new Edge(y,w));
            adj[y].add(new Edge(x,w));
            // Input format: adj[u] has a list of edges (v,w) where v is the destination vertex and w is the weight
        }
        // Your code to find the shortest path to gather flowers goes here
    }
}