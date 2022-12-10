#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
struct edge{
    int u,v,w; // We can sort edges by weight with a struct
    bool operator<(const edge& e) const{
        return w < e.w;
    }
};
int root[N];
int find(int x){
    if(root[x] == -1) return x;
    return root[x] = find(root[x]);
}
bool feastforcats(int c, int m, vector<edge>& e){
    // This is also a minimum spanning tree problem. The optimal path
    // will not have any cycles, so the weight of the MST is the minimum
    // amount of milk spilled. Also we need to give each cat one unit
    // of milk; subtract the number of cats from m to begin with.
    // If the weight of the MST is <= m, then we can give each cat
    // one unit of milk without running out.

    // Since we're given all edges in the input, it's not too hard
    // to extend this to Kruskal's algorithm. All we need is to let
    // our edge structure be comparable so we can sort the edges.
    // Then we can iterate through the edges in increasing order.
    sort(e.begin(), e.end());
    memset(root, -1, sizeof(root));
    int mst_weight = 0;
    for(auto [u,v,w] : e){
        int ru = find(u);
        int rv = find(v);
        if(ru != rv){ // different components
            root[ru] = rv;
            mst_weight += w;
        }
    }
    return mst_weight <= m - c;
}
int main(){
    int qr;
    for(cin >> qr; qr; qr--){
        int c,m;
        cin >> m >> c;
        vector<edge> e(c * (c - 1) / 2);
        for(int i = 0; i < e.size(); i++){
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        cout << (feastforcats(c,m,e) ? "yes" : "no") << '\n';
    }
}