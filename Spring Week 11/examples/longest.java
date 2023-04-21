import java.io.*;
import java.util.*;

class Main{
    
    // Input: ArrayList[] (array) adj; adj[i] stores the neighbors of node i
    // Output: int[] dist; dist[i] stores the longest path from a 'root' node to i
    static int[] longest(ArrayList<Integer>[] adj){
        int n = adj.length;
        // Counting the number of parents is a quick way to check if
        // removing an ancestor will make the node a root
        int[] parent_count = new int[n];
        Queue<Integer> ready = new LinkedList<>();
        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                parent_count[j]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(parent_count[i] == 0){ // This is a root
                ready.add(i);
            }
        }
        int[] dist = new int[n];
        while(!ready.isEmpty()){
            int node = ready.poll();
            for(int i : adj[node]){
                dist[i] = Math.max(dist[i], dist[node] + 1);
                parent_count[i]--;
                if(parent_count[i] == 0){ // This is a root now
                    ready.add(i);
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) throws IOException{
        // Input from stdin: n vertices with m edges; will not work if input is not a DAG
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] adj = new ArrayList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
        }
        int[] dist = longest(adj);
        for(int i = 0; i < n; i++){
            System.out.print(dist[i] + " ");
        }
        System.out.println();
    }

}