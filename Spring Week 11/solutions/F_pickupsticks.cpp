#include <bits/stdc++.h>
using namespace std;

// This actually might feel more at home in last week's
// problem set; there we covered finding a cycle, and that's
// exactly what we need to do here. But sticking with the BFS
// theme, I'll show how you can use a BFS to detect a cycle in
// a directed graph. (This actually makes printing it _slightly_
// easier).

const int N = 1e6 + 5;
vector<int> adj[N];
int parent_count[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); // Faster I/O
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        parent_count[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(parent_count[i] == 0) q.push(i);
    }
    vector<int> ans;
    int removed = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : adj[u]){
            parent_count[v]--;
            if(parent_count[v] == 0) q.push(v);
        }
        removed++;
    }
    if(removed != n){
        // This is how you can detect a cycle with the BFS method;
        // If some vertex is "stuck" and can't be removed, then it
        // still has a parent, but its parent has to have a parent,
        // and so on. The only thing this can mean is that there's a
        // cycle. (ex. 1 -> 2 -> 3 -> 1)
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i : ans){
            cout << i << '\n';
        }
    }
}