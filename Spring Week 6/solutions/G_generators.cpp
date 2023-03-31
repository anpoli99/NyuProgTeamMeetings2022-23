#include <bits/stdc++.h>
using namespace std;

// One way we can approach this problem is through
// the lens of an MST. We have a virtual vertex as 
// the initial vertex, and edges to all generator-
// candidates with cost of a_i. Then to connect to
// a neighbor, we have a cost of b_i. This creates
// a virtual graph, on which this code uses Prim's
// algorithm to find the MST.

const int N = 1e5 + 5;
bool in_tree[N];
int cost_to_add[N]; // Keep track of the minimum edge between this vertex
                    // and a vertex in the MST (either the initial vertex
                    // or a neighbor
int b[N];
int main(){
    FASTIO
    PRECISION
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) best[i] = INF;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < m; i++){
        int c, a;
        cin >> c >> a;
        if(a < cost_to_add[c]){
            cost_to_add[c] = a;
            pq.push({a, c});
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    while(pq.size()){
        auto [t, v] = pq.top();
        pq.pop();
        if(in_tree[v]) continue;
        in_tree[v] = true;
        ans += t;

        int x = (v - 1); if(x == 0) x = n; // x = node to the left 
        int y = (v + 1); if(y == n + 1) y = 1; // y = node to the right
        if(!in_tree[x] && cost_to_add[x] > b[x]){
            cost_to_add[x] = b[x];
            pq.push({b[x], x});
        }
        if(!in_tree[y] && cost_to_add[y] > b[v]){
            cost_to_add[y] = b[v];
            pq.push({b[v], y});
        }
    }
    cout << ans << nl;
}  