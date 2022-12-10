import java.util.*;
import java.io.*;

class Main{
    // We're given the sprinkler system is a tree, and now we can DFS on it.
    // The minimum cost to isolate a subtree from the root is the minimum of:
    // - The cost of closing off the root from its parent
    // - The cost of closing off all of the root's children

    static final int INF = (int)1e9 + 5;
    static final int N = 1000 + 5;
    static ArrayList<Integer>[] e = new ArrayList[N];
    static int[][] dist = new int[N][N];
    static int solve(int k, int p){
        int ans = 0;
        for(int i : e[k]){
            if(i == p) continue;
            // close child from parent, or close all of the childs' children
            ans += Math.min(dist[k][i], solve(i, k));
        }
        if(ans == 0){
            // this is a leaf; we can't close it!
            return INF;
        }
        return ans;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for(int i = 1; i <= N; i++){
            e[i] = new ArrayList<Integer>();
        }
        while(br.ready()){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int root = Integer.parseInt(st.nextToken());
            for(int i = 1; i <= n; i++){
                e[i].clear();
            }
            for(int i = 1; i < n; i++){
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                e[u].add(v);
                e[v].add(u);
                dist[u][v] = dist[v][u] = w;
            }
            System.out.println(solve(root, -1));
        }
    }
}