#include <bits/stdc++.h>
using namespace std;

// We're given the sprinkler system is a tree, and now we can DFS on it.
// The minimum cost to isolate a subtree from the root is the minimum of:
// - The cost of closing off the root from its parent
// - The cost of closing off all of the root's children

const int INF = 1e9 + 5;

const int N = 1000 + 5;
vector<int> e[N];
int dist[N][N];
int solve(int k, int p){
    int ans = 0;
    for(int i : e[k]){
        if(i == p) continue;
        // close child from parent, or close all of the childs' children
        ans += min(dist[k][i], solve(i, k));
    }
    if(ans == 0){
        // this is a leaf; we can't close it!
        return INF;
    }
    return ans;
}
int main(){
    int n, root;
    while(cin >> n >> root){
        for(int i = 1; i <= n; i++){
            e[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back(v);
            e[v].push_back(u);
            dist[u][v] = dist[v][u] = w;
        }
        cout << solve(root, -1) << '\n';
    }
}   