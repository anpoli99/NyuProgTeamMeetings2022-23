#include <bits/stdc++.h>
using namespace std;

/*
 * This implementation of Dinic's algorithm is taken from
 * https://cp-algorithms.com/graph/dinic.html. We will use
 * it to solve the Kattis problem: https://open.kattis.com/problems/maxflow.
 * Details on how to use this implementation are demonstrated in the main method.
 */ 

//https://cp-algorithms.com/graph/dinic.html

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
/*
* End of Dinic's algorithm implementation
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read in the number of nodes and edges
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    // Create a new Dinic object with n nodes, source node s, and sink node t
    Dinic dinic(n, s, t);

    // Read in the edges and add them to the Dinic object
    for (int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        // add edge from u to v with capacity 'cap'
        dinic.add_edge(u, v, cap);
    }

    // Compute the maximum flow from the source to the sink
    long long maxFlow = dinic.flow();
    vector<FlowEdge> edges_used;
    // Iterate through all the edges in the flow network
    // An edge is used if its flow is greater than 0
    // We can also check the capacity of the edge in the same way
    for (FlowEdge e : dinic.edges) {
        if (e.flow > 0) {
            edges_used.push_back(e);
        }
    }
    cout << n << ' ' << maxFlow << ' ' << edges_used.size() << '\n';
    for (FlowEdge e : edges_used) {
        cout << e.v << ' ' << e.u << ' ' << e.flow << '\n';
    }
}
 