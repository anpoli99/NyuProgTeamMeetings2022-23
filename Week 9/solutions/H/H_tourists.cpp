#include <bits/stdc++.h>
using namespace std;

// I know I didn't have time to talk about it in my presentation, but
// I thought I'd show a problem that uses a pretty advanced data structure
// for trees called binary lifting. There are other approaches like using
// a segment tree, or maybe sqrt decomposition or some other trick could
// even work, but binary lifting is one of the most useful algorithms for
// trees. We can use it to find information about the path between two 
// vertices in a tree in O(log n) time. In this problem, we'll find the
// least-common-ancestor (the node with the greatest depth that is an
// ancestor of both nodes) and the number of edges between any two nodes.

const int N = 2e5 + 5;
const int L = 20; // 2^L > N
int up[N][L]; // up[i][j] is the 2^j-th ancestor of i
int depth[N];
vector<int> e[N];
void build(int i, int p){
    up[i][0] = p;
    for(int j = 1; j < L; j++){
        // The key here is that the 2^j-th ancestor of i is the
        // 2^(j-1)-th ancestor of the 2^(j-1)-th ancestor of i
        up[i][j] = up[up[i][j - 1]][j - 1]; 
    }
    for(int j : e[i]){
        if(j != p){
            depth[j] = depth[i] + 1;
            build(j, i);
        }
    }
}
int lca(int u, int v){
    // First we'll "lift" u to have the same depth
    // Then we can lift them together as long as the 2^j-th ancestor
    // of each is different. This will give us the node with the greatest depth
    // that is an ancestor of 'u' but not 'v'; the parent of this node is the
    // least common ancestor.
    if(depth[u] < depth[v]) swap(u, v);
    for(int j = L - 1; j >= 0; j--){
        if(depth[up[u][j]] >= depth[v]){
            u = up[u][j];
        }
    }
    // Now u and v have the same depth
    if(u == v) return u;  // v was an ancestor of u
     
    for(int j = L - 1; j >= 0; j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    // u and v are now the children of the LCA
    return up[u][0]; // or up[v][0]; the parent of u or v
}
int dist(int u, int v){
    // The distance between two nodes is the sum of the depths of the nodes
    // minus twice the depth of the LCA
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    depth[1] = 1;
    build(1, 0);
    long long ans = 0;
    for(int x = 1; x <= n; x++){
        for(int y = x + x; y <= n; y += x){
            // This is just from the problem statement
            ans += dist(x, y) + 1; // + 1; this problem asks for # of vertices instead of edges
        }
    }
    cout << ans << '\n';
}
