#include<bits/stdc++.h>
using namespace std;

// Input: vector of vector<int> adj; adj[i] stores the neighbors of node i
// Output: integer; the (a) centroid of the tree
// Note that this is a tree; edges are bidirectional
int centroid(vector<vector<int>> adj){
    int n = adj.size();
    // Counting the number of parents is a quick way to check if
    // removing an ancestor will make the node a leaf
    vector<int> parent_count(n, 0); 
    queue<int> ready;
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            parent_count[j]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(parent_count[i] == 1){ // This is a leaf
            ready.push(i);
        }
    }
    int centroid = -1;
    while(!ready.empty()){
        int node = ready.front();
        ready.pop();
        centroid = node; // The last node to be removed is the centroid
        for(int i : adj[node]){
            parent_count[i]--;
            if(parent_count[i] == 1){ // This is a leaf now
                ready.push(i);
            }
        }
    }
    return centroid;
}

int main(){
    // Input from stdin: Tree with n vertices (n - 1) edges
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << centroid(adj) << endl;
}
