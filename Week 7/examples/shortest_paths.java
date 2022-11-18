import java.util.*;
import java.io.*;

public class Main{
    static final int N = 100 + 5;
    static final int INF = (int)1e9 + 5;
    static class Point{
        int x,y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    } // useful for representing edges
    static ArrayList<Point> edges[] = new ArrayList[N];
    static int dist[] = new int[N];
    static class Container implements Comparable<Container>{ // we can define our own containers for priority_queue to store the distance
        int dist, vertex;                          // + any other information we need
        public Container(int dist, int vertex){
            this.dist = dist;
            this.vertex = vertex;
        }
        public int compareTo(Container other){
            return dist - other.dist;
        }
    } 
    static int prv[] = new int[N]; // This will help us reconstruct the path
    static ArrayList<Integer> dijkstrasExample(int source, int dest, int n){
        for(int i = 1; i <= n; i++) dist[i] = INF;
        PriorityQueue<Container> pq = new PriorityQueue<>();
        pq.add(new Container(0, source));
        dist[source] = 0;
        while(!pq.isEmpty()){
            int u = pq.peek().vertex;
            int d = pq.peek().dist;
            pq.poll();
            if(d > dist[u]) continue;
            for(Point p : edges[u]){
                int v = p.x;
                int w = p.y;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.add(new Container(dist[v], v));
                    prv[v] = u;
                }
            }
        }
        System.out.println("Shortest path from " + source + " to " + dest + " is " + dist[dest]);
        // If we want to reconstruct the path from 'source' to 'dest':
        ArrayList<Integer> path = new ArrayList<>();
        path.add(dest);
        int cur = dest;
        while(cur != source){
            cur = prv[cur];
            path.add(cur);
        }
        Collections.reverse(path);
        // And now path contains the shortest path from 'source' to 'dest'
        return path;
    }
    static ArrayList<Integer> floydWarshallExample(int n, int source, int dest){
        int adj[][] = new int[N][N];
        int nxt[][] = new int[N][N]; // This will help us reconstruct the path
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                adj[i][j] = INF;
                nxt[i][j] = j;
            }
            adj[i][i] = 0;
            for(Point p : edges[i]){
                int v = p.x;
                int w = p.y;
                adj[i][v] = Math.min(adj[i][v], w);
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(adj[i][j] > adj[i][k] + adj[k][j]){
                        adj[i][j] = adj[i][k] + adj[k][j];
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }
        System.out.println("Shortest path from " + source + " to " + dest + " is " + adj[source][dest]);
        // An example of reconstructing the path from 'source' to 'dest':
        ArrayList<Integer> path = new ArrayList<>();
        path.add(source);
        int cur = source;
        while(cur != dest){
            cur = nxt[cur][dest];
            path.add(cur);
        }
        // And now path contains the shortest path from 'source' to 'dest'
        return path;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= n; i++) edges[i] = new ArrayList<>();
        int m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            edges[u].add(new Point(v,w));
            edges[v].add(new Point(u,w)); // Bidirectional graph; edges go both ways
        }
        int source = 1, dest = n;
        ArrayList<Integer> path = dijkstrasExample(source, dest, n);
        for(int i = 0; i < path.size(); i++){
            System.out.print(path.get(i) + " ");
        }
        System.out.println();
        path = floydWarshallExample(n, source, dest);
        for(int i = 0; i < path.size(); i++){
            System.out.print(path.get(i) + " ");
        }
        System.out.println();
    }
}