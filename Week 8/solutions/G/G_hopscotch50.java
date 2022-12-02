import java.io.*;
import java.util.*;

class Main{
    // We can use Dijkstra's algorithm to solve this problem;
    // If we're in a square, we implicitly get it's value
    // so we can just look for the next value in the sequence.
    static class Point implements Comparable<Point>{
        int x, y, dist;
        Point(int x, int y, int dist){
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
        public int compareTo(Point p){
            return dist - p.dist;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] a = new int[n][n];
        int[][] dist = new int[n][n];
        PriorityQueue<Point> pq = new PriorityQueue<Point>();
        ArrayList<Point>[] list = new ArrayList[k + 1]; // small optimization; don't search whole grid
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
                if(a[i][j] == 1) pq.add(new Point(i, j, 0));
                else {
                    dist[i][j] = Integer.MAX_VALUE;
                    if(list[a[i][j]] == null) list[a[i][j]] = new ArrayList<Point>();
                    list[a[i][j]].add(new Point(i, j, 0));
                }
            }
        }
        while(!pq.isEmpty()){
            Point p = pq.poll();
            if(p.dist > dist[p.x][p.y]) continue;
            int val = a[p.x][p.y];
            if(val == k){
                // first 'k' reached; we're done
                System.out.println(p.dist);
                return;
            }
            if(list[val + 1] == null){
                // stuck here; no next value
                System.out.println(-1);
                return;
            }
            // check next value in sequence
            for(Point q : list[val + 1]){
                int newDist = p.dist + Math.abs(p.x - q.x) + Math.abs(p.y - q.y);
                if(dist[q.x][q.y] > newDist){
                    dist[q.x][q.y] = newDist;
                    pq.add(new Point(q.x, q.y, newDist));
                }
            }
        }
        System.out.println(-1); // unreachable
    }

}