#include<bits/stdc++.h>
using namespace std;

// Input: vector of vector<int> adj; adj[i] stores the neighbors of node i
// Output: vector<int> dist; dist[i] stores the longest path from a 'root' node to i
vector<int> longest(vector<vector<int>> adj){
    int n = adj.size();
    // Counting the number of parents is a quick way to check if
    // removing an ancestor will make the node a root
    vector<int> parent_count(n, 0); 
    queue<int> ready;
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            parent_count[j]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(parent_count[i] == 0){ // This is a root
            ready.push(i);
        }
    }
    vector<int> dist(n, 0);
    while(!ready.empty()){
        int node = ready.front();
        ready.pop();
        for(int i : adj[node]){
            dist[i] = max(dist[i], dist[node] + 1);
            parent_count[i]--;
            if(parent_count[i] == 0){ // This is a root now
                ready.push(i);
            }
        }
    }
    return dist;
}

int main(){
    // Input from stdin: n vertices with m edges; will not work if input is not a DAG
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> dist = longest(adj);
    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}