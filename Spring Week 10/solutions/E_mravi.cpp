#include <bits/stdc++.h>
using namespace std;

// This problem is a fairly straightforward DFS on a tree:
// if X% of a node goes to a child that requires K, then
// that node needs at least K/X% liquid. If that edge has
// a superpower, then we have:
// (X% * Req)^2 = K
// Req = sqrt(K) / X% 
// Taking the maximum gives the amount that any node needs
// to be filled to, and  the answer is the amount of liquid
// needed to fill the root node.

struct edge{
    int v; 
    bool super;
    double p;
};
const int N = 1000 + 5;
vector<edge> adj[N];
int k[N];
double dfs(int u, int par){
    double ans = k[u];
    for(auto [v,super,p] : adj[u]){
        if(v == par) continue;
        double req = dfs(v, u);
        if(super){
            ans = max(ans, sqrt(req) / p);
        }else{
            ans = max(ans, req / p);
        }
    }
    return ans;
}
int main(){
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; double p; bool s;
        cin >> u >> v >> p >> s;
        p /= 100.0;
        adj[u].push_back({v, s, p});
        adj[v].push_back({u, s, p});
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    cout << dfs(1, 0) << endl;

}  