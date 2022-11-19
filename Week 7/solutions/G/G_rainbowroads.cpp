#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 7 * 7 * 7 *7 + 5;
const ll INF = 1e18 + 5;
struct edge{
    int to, cost, color;
};
vector<edge> adj[N];
ll dis[N][128]; // dist[i][j] = min distance to node i with colors mask(j)

int to_int(char c){
    string x = "ROYGBIV";
    for(int i = 0; 1; i++){
        if(x[i] == c) return i;
    }
}
struct pq_ctnr{
    int node, mask; ll dist;
    bool operator<(const pq_ctnr &other) const{
        return dist > other.dist; // reversed for priority queue
    }
};
int main() {
    priority_queue<pq_ctnr> pq;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        char c;
        cin >> u >> v >> w >> c;
        adj[u].push_back({v,w,to_int(c)});
        adj[v].push_back({u,w,to_int(c)});
    }   
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 128; j++){
            dis[i][j] = INF;
        }
    }
    // This is a fancy Dijkstra's algorithm where we include the colors we visited
    // as a bitmask in the state of the node. The current node and the colors we've
    // seen define the state completely, so we can run Dijkstra's algorithm on this
    // state space.
    dis[1][0] = 0;
    pq.push({1,0,0});
    ll ans = INF;
    while(pq.size()){
        auto c = pq.top();
        auto x = c.node;
        auto y = c.mask;
        auto z = c.dist;
        pq.pop();
        if(y == 127 && x == 1){
            ans = z;
            break;
        }
        for(auto e : adj[x]){
            int new_mask = y | (1 << e.color);
            if(z + e.cost < dis[e.to][new_mask]){
                dis[e.to][new_mask] = z + e.cost;
                pq.push(pq_ctnr{e.to,new_mask,dis[e.to][new_mask]});
            }
        }
    }
    cout << ans << '\n';
}       