import java.io.*;
import java.util.*;


/* 
* This implementation of Dinic's algorithm is borrowed from UCF's 
* programming team, http://www.cs.ucf.edu/~dmarino/progcontests/cop4516/samplecode/Dinic.java.
* We will use it to solve the Kattis problem: https://open.kattis.com/problems/maxflow .
* Details on how to use this code are demonstrated in the main method.
*/

// An edge connects v1 to v2 with a capacity of cap, flow of flow.
class Edge {
	int v1, v2, cap, flow;
	Edge rev;
	Edge(int V1, int V2, int Cap, int Flow) {
		v1 = V1;
		v2 = V2;
		cap = Cap;
		flow = Flow;
	}
}

class Dinic {

	// Queue for the top level BFS.
	public ArrayDeque<Integer> q;

	// Stores the graph.
	public ArrayList<Edge>[] adj;
	public int n;

	// s = source, t = sink
	public int s;
	public int t;


	// For BFS.
	public boolean[] blocked;
	public int[] dist;

	final public static int oo = Integer.MAX_VALUE;

	// Constructor.
	public Dinic (int N) {

		// s is the source, t is the sink, add these as last two nodes.
		n = N; s = n++; t = n++;

		// Everything else is empty.
		blocked = new boolean[n];
		dist = new int[n];
		q = new ArrayDeque<Integer>();
		adj = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			adj[i] = new ArrayList<Edge>();
	}

	// Just adds an edge and ALSO adds it going backwards.
	public void add(int v1, int v2, int cap, int flow) {
		Edge e = new Edge(v1, v2, cap, flow);
		Edge rev = new Edge(v2, v1, 0, 0);
		adj[v1].add(rev.rev = e);
		adj[v2].add(e.rev = rev);
	}

	// Runs other level BFS.
	public boolean bfs() {

		// Set up BFS
		q.clear();
		Arrays.fill(dist, -1);
		dist[t] = 0;
		q.add(t);

		// Go backwards from sink looking for source.
		// We just care to mark distances left to the sink.
		while(!q.isEmpty()) {
			int node = q.poll();
			if(node == s)
				return true;
			for(Edge e : adj[node]) {
				if(e.rev.cap > e.rev.flow && dist[e.v2] == -1) {
					dist[e.v2] = dist[node] + 1;
					q.add(e.v2);
				}
			}
		}

		// Augmenting paths exist iff we made it back to the source.
		return dist[s] != -1;
	}

	// Runs inner DFS in Dinic's, from node pos with a flow of min.
	public int dfs(int pos, int min) {

		// Made it to the sink, we're good, return this as our max flow for the augmenting path.
		if(pos == t)
			return min;
		int flow = 0;

		// Try each edge from here.
		for(Edge e : adj[pos]) {
			int cur = 0;

			// If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
			// can go this way.
			if(!blocked[e.v2] && dist[e.v2] == dist[pos]-1 && e.cap - e.flow > 0) {

				// Recursively run dfs from here - limiting flow based on current and what's left on this edge.
				cur = dfs(e.v2, Math.min(min-flow, e.cap - e.flow));

				// Add the flow through this edge and subtract it from the reverse flow.
				e.flow += cur;
				e.rev.flow = -e.flow;

				// Add to the total flow.
				flow += cur;
			}

			// No more can go through, we're good.
			if(flow == min)
				return flow;
		}

		// mark if this node is now blocked.
		blocked[pos] = flow != min;

		// This is the flow
		return flow;
	}

	public int flow() {
		clear();
		int ret = 0;

		// Run a top level BFS.
		while(bfs()) {

			// Reset this.
			Arrays.fill(blocked, false);

			// Run multiple DFS's until there is no flow left to push through.
			ret += dfs(s, oo);
		}
		return ret;
	}

	// Just resets flow through all edges to be 0.
	public void clear() {
		for(ArrayList<Edge> edges : adj)
			for(Edge e : edges)
				e.flow = 0;
	}
}
/* End of Dinic's algorithm */

public class maxflow{
    final static int INF = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException{
        // Read in the input.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = parseInt(st), m = parseInt(st), s = parseInt(st), t = parseInt(st);
        Dinic d = new Dinic(n);
        d.add(d.s, s, INF, 0);
        d.add(t, d.t, INF, 0); // This implementation creates its own source and sink.
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int u = parseInt(st), v = parseInt(st), cap = parseInt(st);
            // Add an edge from u to v with capacity 'cap'.
            d.add(u, v, cap, 0); // If there is already flow in the edge, you can change the '0'.
        }
        int maxFlow = d.flow();
        ArrayList<Edge> edgesUsed = new ArrayList<Edge>();
        // Get the edges used in the max flow.
        // An edge is used if it has flow > 0.
        // We can also compare the flow to the capacity if we want to know how much flow is left.
        for(int i = 0; i < d.n; i++){
            for(Edge e : d.adj[i]){
                if(e.v1 == d.s || e.v2 == d.t) // Since it adds its own source and sink, we don't want to include them.
                    continue;
                if(e.flow > 0){
                    edgesUsed.add(e);
                }
            }
        }
        System.out.println(n + " " + maxFlow + " " + edgesUsed.size());
        for(Edge e : edgesUsed){
            System.out.println(e.v1 + " " + e.v2 + " " + e.flow);
        }
    }
    static int parseInt(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}