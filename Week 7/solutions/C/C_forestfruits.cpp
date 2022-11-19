#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using pl = pair<ll, ll>; // Make sure you're using 64-bit integers for this problem
const ll LINF = 1e18;

const int N = 20000 + 5;
vector<pl> adj[N];
ll dist[N];
int main(){
    int n, m, c, k, d; // just a side-note; I like to ignore what they called the variables
                       // n = # of vertices, m = # of edges, d = # of days
                       // It means I only have to replace the variables once and I can know
                       // for ALL codes 'm' = # of edges. I'm mentioning this because "clean"
                       // code techniques are VERY important in contests in my opinion. Doing
                       // this takes _maybe_ 10 seconds, but not doing it and mixing up 'm'
                       // and 'd' can cost you 10 minutes.

    cin >> n >> m >> c >> k >> d;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // Dijktstra's to find shortest distance to each node
    for(int i = 0; i <= n; i++) dist[i] = LINF;
    std::priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        pl cur = pq.top();
        pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for(pl nxt : adj[cur.second]){
            ll ndist = cur.first + nxt.second;
            if(dist[nxt.first] > ndist){
                dist[nxt.first] = ndist;
                pq.push({ndist, nxt.first});
            }
        }
    }
    // get all flowers + their distances
    vector<ll> flowers;
    for(int i = 0; i < c; i++){
        int x;
        cin >> x;
        flowers.push_back(dist[x]);
    }
    sort(flowers.begin(), flowers.end());
    d = min(d, k); // flowers regrow every k days; so we can revisit the same flower after this
    ll ans = d <= c ? flowers[d - 1] : LINF;
    ans *= 2;
    if(ans > LINF) ans = -1;
    cout << ans << '\n';
}