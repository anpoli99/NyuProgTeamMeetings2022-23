#include <bits/stdc++.h>
using namespace std;

// This problem is very similar to finding the centroid of a tree;
// the difference here is that because the graph is not a tree, there
// may be several vertices left over. We just need to check if the
// queried vertex is one of them.

const int N = 2e5 + 5;
vector<int> adj[N];
int neighbor_count[N];
int initial_count[N];
bool removed[N];
int main(){
    int n, m, x, l;
    cin >> n >> m >> x >> l;
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        neighbor_count[i] = adj[i].size();
        initial_count[i] = adj[i].size();
    }
    q.push(l);
    removed[l] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            neighbor_count[v]--;
            if(neighbor_count[v] * 2 <= initial_count[v] && !removed[v]){
                removed[v] = true;
                q.push(v);
            }
        }
    }
    if(removed[x]){
        cout << "leave" << endl;
    }else{
        cout << "stay" << endl;
    }
}