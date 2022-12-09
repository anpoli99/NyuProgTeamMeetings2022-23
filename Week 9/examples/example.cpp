#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
// if we need weights, we can use:
// using pi = pair<int, int>;
// vector<pi> adj[N];

int how_many_vertices(int root, int parent){ // how many vertices in subtree?
    int ans = 1;
    for(int child : adj[root]){
        if(child == parent) continue;
        ans += how_many_vertices(child, root);
    }
    return ans;
}

int diameter = 0;
// The diameter is the longest path between two vertices in a tree.
// We can find it by finding the two longest paths from a given vertex
// to the leaves of the tree. The longest path through this vertex (without
// its parent) is the sum of these two paths. The diameter will be one of
// these such paths.
int find_largest_path_to_leaves(int root, int parent){
    int max1 = 0, max2 = 0;
    for(int child : adj[root]){
        if(child == parent) continue;
        int path = find_largest_path_to_leaves(child, root) + 1; // +1 for current edge
        if(path > max1){ 
            max2 = max1; // we know max1 >= max2
            max1 = path; 
        }else if(path > max2){
            max2 = path;
        }
    }
    diameter = max(diameter, max1 + max2);
    return max1;
}

// union-find for Kruskal's algorithm; see last week's meeting for more details
int root[N];
int find(int k){
    if(root[k] < 0) return k;
    return root[k] = find(root[k]);
}
struct edge{
    // In C++, we can use a struct to represent an edge
    int u, v, w;
    bool operator<(const edge& other) const{
        return w < other.w;
    }
};
int kruskals_mst(vector<edge> edges, int n){
    sort(edges.begin(), edges.end()); // lowest weight to highest weight
    memset(root, -1, sizeof(root));
    int ans = 0;
    for(edge e : edges){
        int u = find(e.u), v = find(e.v);
        if(u != v){
            root[u] = v;
            ans += e.w; // add edge to MST
        }
    }
    return ans;
}
int dist[N];
int parent[N]; // useful for reconstructing the MST
bool vis[N];
using pi = pair<int, int>;
const int INF = 1e9 + 5;
vector<pi> neighbors[N];
int prims_mst_n_squared(int n){
    int root = 1; // start at any vertex
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    dist[root] = 0;
    int ans = 0;
    parent[root] = -1;
    for(int i = 1; i < n; i++){ // Tree has n - 1 edges
        int best_dist = INF, next = -1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dist[j] < best_dist){
                best_dist = dist[j];
                next = j;
            }
        }
        // if(next == -1) return -1; // graph is not connected
        vis[next] = true;
        ans += best_dist;
        // add edge (parent[next], next) to MST
        for(pi p : neighbors[next]){
            int child = p.first, weight = p.second;
            if(!vis[child] && weight < dist[child]){
                dist[child] = weight;
                parent[child] = next;
            }
        }
    }
    return ans;
}

int prims_mst(int n){
    // use a priority queue to make algorithm O(E log V)
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int root = 1; // start at any vertex
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    dist[root] = 0;
    int ans = 0;
    parent[root] = -1;
    pq.push({0, root});
    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();
        int next = p.second;
        if(vis[next]) continue;
        vis[next] = true;
        ans += p.first;
        // add edge (parent[next], next) to MST
        for(pi p : neighbors[next]){
            int child = p.first, weight = p.second;
            if(!vis[child] && weight < dist[child]){
                dist[child] = weight;
                parent[child] = next;
                pq.push({weight, child});
            }
        }
    }
    return ans;
}

int main(){

}