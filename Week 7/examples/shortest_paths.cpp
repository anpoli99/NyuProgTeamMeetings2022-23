#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

// Example implementation of Dijkstra's algorithm
typedef pair<int, int> pi;
vector<pi> edges[N];
int dist[N];
struct ctnr{ // we can define our own containers for priority_queue to store the distance
            // + any other information we need
    int dist, vertex;
    bool operator<(const ctnr &other) const{
        return dist > other.dist; // In C++ this goes backwards (priority_queue is a max heap but we want a min heap)
    }
};  
const int INF = 1e9;
int prv[N]; // This will help us reconstruct the path
vector<int> dijkstras_example(int source, int dest, int n){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<ctnr> pq;
    // If we had just Integers in the priority_queue, we can use: priority_queue<pi, vector<pi>, greater<pi>> pq;
    // greater<pi> makes the priority_queue a min heap
    pq.push({0, source});
    dist[source] = 0;
    while(!pq.empty()){
        int u = pq.top().vertex;
        int d = pq.top().dist;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : edges[u]){ // autocasting for C++17 and above
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                prv[v] = u;
            }
        }
    }
    cout << "Shortest path from " << source << " to " << dest << " is " << dist[dest] << endl;
    // If we want to reconstruct the path from 'source' to 'dest':
    vector<int> path = {dest};
    int cur = dest;
    while(cur != source){
        cur = prv[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    // And now path contains the shortest path from 'source' to 'dest'
    return path;
}

// For Floyd-Warshall, it's more helpful to use a matrix instead of a vector of pairs
int adj[N][N];
int nxt[N][N]; // This will help us reconstruct the path
vector<int> floyd_warshall_example(int n, int source, int dest){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[i][j] = INF;
            nxt[i][j] = j;
        }
        adj[i][i] = 0;
        for(auto [v, w] : edges[i]){
            adj[i][v] = min(adj[i][v], w);
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
    cout << "Shortest path from " << source << " to " << dest << " is " << adj[source][dest] << endl;

    // An example of reconstructing the path from 'source' to 'dest':
    vector<int> path = {source};
    int cur = source;
    while(cur != dest){
        cur = nxt[cur][dest];
        path.push_back(cur);
    }
    // And now path contains the shortest path from 'source' to 'dest'
    return path;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w}); // Bidirectional graph; edges go both ways
    }
    int source = 1, dest = n;
    vector<int> path = dijkstras_example(source, dest, n);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    path = floyd_warshall_example(n, source, dest);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}