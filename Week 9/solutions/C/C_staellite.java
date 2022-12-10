import java.util.*;
import java.io.*;

class Main{

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // The structure being described is example a minimum spanning tree.
        // The length of titanium rod needed between satellite dishes (i,j) is their
        // distance minus the radius of each dish.
        // Since N is small we can use Prim's algorithm and not worry about
        // any other data structures.
        int n = Integer.parseInt(br.readLine());
        int[] x = new int[n], y = new int[n], r = new int[n];
        double[] dist = new double[n];
        boolean[] visited = new boolean[n];
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            r[i] = Integer.parseInt(st.nextToken());
            // 0 is the root; initialize dist[i] using index 0
            double dx = x[i] - x[0];
            double dy = y[i] - y[0];
            double cost = Math.sqrt(dx * dx + dy * dy) - r[i] - r[0];
            dist[i] = Math.max(0, cost);
        }
        double ans = 0;
        visited[0] = true; // 0 is the root
        for(int i = 0; i < n - 1; i++){
            double best_dist = 1e9;
            int next = -1;
            for(int j = 0; j < n; j++){ // 0 is the root
                if(!visited[j] && dist[j] < best_dist){
                    best_dist = dist[j];
                    next = j;
                }
            }
            visited[next] = true;
            ans += best_dist;
            for(int j = 0; j < n; j++){
                if(!visited[j]){
                    double dx = x[j] - x[next];
                    double dy = y[j] - y[next];
                    double cost = Math.sqrt(dx * dx + dy * dy) - r[j] - r[next];
                    dist[j] = Math.min(dist[j], Math.max(0, cost));
                }
            }
        }
        System.out.println(ans);
    }
}