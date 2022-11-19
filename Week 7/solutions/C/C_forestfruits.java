import java.io.*;
import java.util.*;

class Main{
    static class Edge{
        int v; long w;
        Edge(int v, long w){
            this.v = v;
            this.w = w;
        }
    } // We can use our own Edge class to keep track of the edge all at once
    static final int V = 20000 + 5;
    static final long INF = (long)1e18 + 5;
    static ArrayList<Edge> adj[] = new ArrayList[V];
    static long dist[] = new long[V];
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        // just a side-note; I like to ignore what they called the variables
        // n = # of vertices, m = # of edges, d = # of days
        // It means I only have to replace the variables once and I can know
        // for ALL codes 'm' = # of edges. I'm mentioning this because "clean"
        // code techniques are VERY important in contests in my opinion. Doing
        // this takes _maybe_ 10 seconds, but not doing it and mixing up 'm'
        // and 'd' can cost you 10 minutes.
        for(int i = 0; i <= n; i++) adj[i] = new ArrayList<Edge>();
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            long w = Long.parseLong(st.nextToken());
            adj[u].add(new Edge(v, w));
            adj[v].add(new Edge(u, w));
        }
        // Dijktstra's to find shortest distance to each node
        Arrays.fill(dist, INF);
        PriorityQueue<Edge> pq = new PriorityQueue<Edge>((a, b) -> Long.compare(a.w, b.w));
        pq.add(new Edge(1, 0));
        dist[1] = 0;
        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            if(cur.w > dist[cur.v]) continue;
            for(Edge nxt : adj[cur.v]){
                long ndist = cur.w + nxt.w;
                if(dist[nxt.v] > ndist){
                    dist[nxt.v] = ndist;
                    pq.add(new Edge(nxt.v, ndist));
                }
            }
        }
        // get all flowers + their distances
        ArrayList<Long> flowers = new ArrayList<Long>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < c; i++){
            int x = Integer.parseInt(st.nextToken());
            flowers.add(dist[x]);
        }
        Collections.sort(flowers);
        d = Math.min(d, k); // flowers regrow every k days; so we can revisit the same flower after this
        long ans = d <= c ? flowers.get(d - 1) : INF;
        ans *= 2;
        if(ans > INF) ans = -1;
        System.out.println(ans);
    }
}