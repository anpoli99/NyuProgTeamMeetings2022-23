#include <bits/stdc++.h>
using namespace std;

// This is clearly a tree problem (given by n - 1 edges);
// Because in a tree, removing an edge will always result in exactly
// two trees, one solution could be removing each edge and checking
// the minimum cost to connect them together. Trying every pair
// of edges to add back is too slow (n edges to remove * n^2 edges to add back),
// but we have enough time to do a dfs on the whole tree.
//
// This is enough to give us a solution: running a dfs can tell us the
// _diameter_: the longest path in the tree. If we let d1 and d2 be the two 
// diameters, clearly the longest path after adding an edge must be at least
// max(d1, d2). The longest path that goes through both components can be
// minimized by attaching the two components in the middle of their diameters.
// This creates a path with length ceil(d1 / 2) + ceil(d2 / 2) + 1. So the answer
// for removing an edge is the maximum of these terms. Trying this for every
// edge gives us an n^2 solution.

const int INF = 1e9 + 5;
const int N = 2500 + 5;
vector<int> adj[N];
int u,v; // the "removed" edge; we can just make sure we don't use it in the dfs
// The longest path that goes through a node is equal to the sum of the two
// longest paths that go through different children. The diameter of a tree
// is the maximum of these values.
int diameter = -INF; // global variable for conveniences
int dfs(int k, int p){ // Return the longest path from 'k' to a leaf
    int max1 = 0, max2 = 0;
    for(int j : adj[k]){
        if(j == p) continue;
        if(make_pair(j,k) == make_pair(u,v)) continue;
        if(make_pair(j,k) == make_pair(v,u)) continue; // don't use the removed edge
        int d = dfs(j, k) + 1;
        if(d > max1){
            max2 = max1;
            max1 = d;
        }else if(d > max2){
            max2 = d;
        }
    }
    diameter = max(diameter, max1 + max2);
    return max1;
}   
int neighbors[N];
int centroid(int r){
    vector<int> all;
    set<int> in = {r};
    queue<int> q({r});
    while(!q.empty()){
        int k = q.front(); q.pop();
        all.push_back(k);
        for(int j : adj[k]){
            if(in.count(j)) continue;
            if(make_pair(j,k) == make_pair(u,v)) continue;
            if(make_pair(j,k) == make_pair(v,u)) continue; // don't use the removed edge
            in.insert(j);
            q.push(j);
        }
    }
    if(all.size() == 1) return r;
    int n = all.size();
    memset(neighbors, 0, sizeof(neighbors));
    for(int i = 0; i < n; i++){
        int k = all[i];
        for(int j : adj[k]){
            if(make_pair(j,k) == make_pair(u,v)) continue;
            if(make_pair(j,k) == make_pair(v,u)) continue; // don't use the removed edge
            neighbors[j]++;
        }
    }
    for(int i : all){
        if(neighbors[i] == 1) q.push(i);
    }
    int ans;
    while(!q.empty()){
        int k = q.front(); q.pop();
        ans = k;
        for(int j : adj[k]){
            if(make_pair(j,k) == make_pair(u,v)) continue;
            if(make_pair(j,k) == make_pair(v,u)) continue; // don't use the removed edge
            neighbors[j]--;
            if(neighbors[j] == 1) q.push(j);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INF;
    int best_u = -1, best_v = -1;
    for(int i = 1; i <= n; i++){
        for(int j : adj[i]){
            if(i > j) continue; // microptimization
            u = i, v = j;
            diameter = -INF;
            dfs(i, -1);
            int d1 = diameter;
            diameter = -INF;
            dfs(j, -1);
            int d2 = diameter;
            int tmp = max(max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
            if(tmp < ans){
                ans = tmp;
                best_u = i; best_v = j;
            }
        }
    }
    // After finding the best edge to remove, we need to find the best edge to add back.
    // This is equal to the centroid of the each component. 
    u = best_u, v = best_v;
    int c_u = centroid(best_u);
    int c_v = centroid(best_v);
    cout << ans << endl;
    cout << best_u << " " << best_v << endl;
    cout << c_u << " " << c_v << endl;
}  