#include "bits/stdc++.h"
using namespace std;
 
// I like this problem quite a bit. To explain the solution,
// I'll start with a simpler problem. Suppose there are only
// 7 colors. How can we solve this?
// Well, we can keep track of whether we've seen each color
// with a bitmask. This creates an augmented graph, where each
// vertex can be in 2^7 different states (and with only 1000
// vertices, this is small enough). Running Dijkstra's gives
// us a solution.
//
// The really clever trick (that I can't take credit for) is
// to randomly assign each existing color to one of seven colors.
// We can use the same bitmask trick, and if we find a path, we know
// it used seven different colors. What's the probability of this
// solution working? If there's exactly one optimal solution, then
// the probability that each ball is assigned to the same color is
// 1/(2^6). So if we repeat this 600 times, we're very likely to randomly
// find a solution.
// 
// The total runtime is: log(2^7 * N) * 2^7 * N * T, where N is the
// size of the graph and T is the number of trials. For N = 1000 and
// T = 600, this is about 10^9. With 16 seconds, this is enough
// to pass.


const int INF = 1e9 + 5;
using pi = pair<int, int>;

int dist[1005][(1 << 7) + 5];
vector<pi> adj[1005];
int mask[1005]; // We'll use this to keep track of the colors at a given city
struct ctnr{
    // Container for PQ
    int v; int mask; int dist;
    bool operator<(const ctnr& o) const{
        return dist > o.dist;
    }
};
int solve(int n){
    priority_queue<ctnr> pq;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (1 << 7); j++){
            dist[i][j] = INF;
        }
    }
    dist[1][mask[1]] = 0;
    pq.push({1, mask[1], 0});
    while(!pq.empty()){
        auto [u, m, d] = pq.top(); pq.pop();
        if(d > dist[u][m]) continue;
        if(m == (1 << 7) - 1) break;
        for(auto [v, w] : adj[u]){
            int new_mask = m | mask[v];
            if(dist[v][new_mask] > d + w){
                dist[v][new_mask] = d + w;
                pq.push({v, new_mask, d + w});
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++){
        ans = min(ans, dist[i][(1 << 7) - 1]);
    }
    return ans;
}
int city[10005], color[10005];
int color_map[1005];
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    for(int i = 1; i <= k; i++){
        cin >> city[i] >> color[i];
    }

    srand(time(NULL));
    int ans = INF;
    for(int i = 0; i < 600; i++){
        for(int j = 1; j <= k; j++){
            color_map[color[j]] = rand() % 7;
        }
        for(int j = 1; j <= n; j++){
            mask[j] = 0;
        }
        for(int j = 1; j <= k; j++){
            mask[city[j]] |= (1 << color_map[color[j]]);
        }
        ans = min(ans, solve(n));
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;
}
