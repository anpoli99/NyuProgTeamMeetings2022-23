#include <bits/stdc++.h>
using namespace std;

// If we treat "there is a recipe that uses u to create v"
// as an edge from v to u, then we can use the BFS topological sort
// and pass down the required amounts from each node to its descendants.
// For example, if we need 3 v, and a recipe uses 2 u to create 1 v,
// then we need 6 (additional) u to create 3 v.

const int N = 50 + 5;
vector<pair<int,int>> adj[N];
long long required[N];
int parent[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> required[i];
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[v].push_back({u,w});
        parent[u]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(parent[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v,w] : adj[u]){
            required[v] += required[u] * w;
            parent[v]--;
            if(parent[v] == 0) q.push(v);
        }
    }
    for(int i = 0; i < n; i++){
        cout << required[i] << " ";
    }
    cout << endl;
}