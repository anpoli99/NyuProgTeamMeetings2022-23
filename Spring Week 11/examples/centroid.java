import java.io.*;
import java.util.*;

class Main{
    // Input: ArrayList[] (array) adj; adj[i] stores the neighbors of node i
    // Output: int; the (a) centroid of the tree
    // Note that this is a tree; edges are bidirectional
    static int centroid(ArrayList<Integer>[] adj){
        int n = adj.length;
        // Counting the number of parents is a quick way to check if
        // removing an ancestor will make the node a leaf
        int[] parent_count = new int[n];
        Queue<Integer> ready = new LinkedList<>();
        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                parent_count[j]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(parent_count[i] == 1){ // This is a leaf
                ready.add(i);
            }
        }
        int centroid = -1;
        while(!ready.isEmpty()){
            int node = ready.poll();
            centroid = node; // The last node to be removed is the centroid
            for(int i : adj[node]){
                parent_count[i]--;
                if(parent_count[i] == 1){ // This is a leaf now
                    ready.add(i);
                }
            }
        }
        return centroid;
    }

    public static void main(String[] args) throws IOException{
        // Input from stdin: Tree with n vertices (n - 1) edges
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] adj = new ArrayList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < n - 1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        System.out.println(centroid(adj));
    }

}