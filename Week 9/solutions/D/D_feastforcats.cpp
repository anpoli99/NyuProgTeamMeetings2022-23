#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
struct edge{
    int u,v,w; // We can sort edges by weight with a struct
    bool operator<(const edge& e) const{
        return w < e.w;
    }
};
int dist[N];
bool vis[N];
int adj[N][N];
bool feastforcats(int c, int m, vector<edge>& e){
    // This is also a minimum spanning tree problem. The optimal path
    // will not have any cycles, so the weight of the MST is the minimum
    // amount of milk spilled. Also we need to give each cat one unit
    // of milk; subtract the number of cats from m to begin with.
    // If the weight of the MST is <= m, then we can give each cat
    // one unit of milk without running out.

    // Keep in mind that Kruskal's algorithm is E log E. This is slower than
    // the N^2 Prim's algorithm when E ~= N^2! In C++ Kruskal's passes in about 2s
    // which is fast enough, but other languages may time out.
    // Here's a faster version using Prim's algorithm:
    for(auto [u,v,w] : e){
        adj[u][v] = adj[v][u] = w;
    }
    int mst_weight = 0;
    for(int i = 0; i < c; i++) {
        dist[i] = adj[0][i];
        vis[i] = false;
    }
    dist[0] = 0;
    vis[0] = true;
    for(int i = 0; i < c - 1; i++){
        int best_dist = 1e9, next = -1;
        for(int j = 0; j < c; j++){
            if(!vis[j] && dist[j] < best_dist){
                best_dist = dist[j];
                next = j;
            }
        }
        vis[next] = true;
        mst_weight += best_dist;
        for(int j = 0; j < c; j++){
            if(!vis[j] && adj[next][j] < dist[j]){
                dist[j] = adj[next][j];
            }
        }
    }
    return mst_weight <= m - c;
}
int main(){
    int qr;
    for(cin >> qr; qr; qr--){
        int c,m;
        cin >> m >> c;
        vector<edge> e(c * (c - 1) / 2);
        for(int i = 0; i < e.size(); i++){
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        cout << (feastforcats(c,m,e) ? "yes" : "no") << '\n';
    }
}