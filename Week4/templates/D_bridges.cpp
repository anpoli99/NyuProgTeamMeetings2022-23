#include <bits/stdc++.h>
using namespace std;

// Input format: adj[i] is a vector of the neighbors of node i
//               is_single[i][j] tells whether the edge from i to adj[i][j] is a single-lane bridge
//               adj[i].size() == is_single[i].size() for all i
// The input is 1-indexed
int bridges(int n, vector<vector<int>> adj, vector<vector<bool>> is_single){
    // In a later week we'll talk about generalized shortest paths problems
    // Dijkstra's algorithm solves this problem too 

    vector<int> dist(n + 1, INT_MAX);
    deque<int> dq; // The trick to this problem is to use a deque instead of a queue
                    // If a vertex isn't a bridge, we can push it to the front of the deque instead

    dq.push_back(1);
    dist[1] = 0;
    while(dq.size()){
        int u = dq.front();
        dq.pop_front();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            int new_dist = dist[u] + (is_single[u][i] ? 1 : 0);
            if(new_dist < dist[v]){
                dist[v] = new_dist;
                if(new_dist == dist[u]){
                    dq.push_front(v);
                }else{
                    // It's fine if we push a vertex 2 times; the algorithm still takes O(n) time
                    // Because we can show each vertex won't be pushed more than twice, 
                    // we don't need to do any processing to make sure we don't push the same vertices 
                    dq.push_back(v);
                }
            }
        }
    }
    return dist[n];
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