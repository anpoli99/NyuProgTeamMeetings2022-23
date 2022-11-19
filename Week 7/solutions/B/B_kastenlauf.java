import java.io.*;
import java.util.*;

class Main{
    static final int N = 1000 + 5;
    static int[] x = new int[N];
    static int[] y = new int[N];
    static boolean[] vis = new boolean[N];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            int n = Integer.parseInt(br.readLine());
            // You could also use Floyd-Warshall or Dijkstra's with 'n' this small
            // I think BFS is the easiest to implement, and it's also the fastest.
            // Usually using Dijkstra's when you could use a BFS won't actually
            // matter in practice, but there could be a case where Dijkstra's is too
            // slow. Either way, recognizing when you can just BFS is a useful skill.

            n += 2; // 0 = begin, n + 1 = end
            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                x[i] = Integer.parseInt(st.nextToken());
                y[i] = Integer.parseInt(st.nextToken());
                vis[i] = false;
            }
            vis[0] = true;
            Queue<Integer> q = new LinkedList<>();
            q.add(0);
            while(q.size() > 0){
                int k = q.poll();
                for(int i = 0; i < n; i++){
                    if(vis[i]) continue;
                    // One bottle every 50 meters; 20 bottles in a box
                    // They can travel 1000 meters, so if the next store is 
                    // at least that close, they can get there
                    int dx = Math.abs(x[i] - x[k]);
                    int dy = Math.abs(y[i] - y[k]);
                    if(dx + dy <= 1000){
                        q.add(i);
                        vis[i] = true;
                    }
                }
            }
            System.out.println(vis[n - 1] ? "happy" : "sad");
        }
    }
}