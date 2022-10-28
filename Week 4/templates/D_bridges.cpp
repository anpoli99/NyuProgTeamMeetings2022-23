#include <bits/stdc++.h>
using namespace std;

// Input format: adj[i] is a vector of the neighbors of node i
//               is_single[i][j] tells whether the edge from i to adj[i][j] is a single-lane bridge
//               adj[i].size() == is_single[i].size() for all i
// The input is 1-indexed
int bridges(int n, vector<vector<int>> adj, vector<vector<bool>> is_single){
    // Your code goes here
    return -1; // This is a placeholder
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<bool>> is_single(n + 1);
    for(int i = 0; i < m; i++){
        int u,v,b;
        cin >> u >> v >> b;
        adj[u].push_back(v);
        adj[v].push_back(u);
        is_single[u].push_back(b);
        is_single[v].push_back(b);
    }
    cout << bridges(n, adj, is_single) << endl;
}