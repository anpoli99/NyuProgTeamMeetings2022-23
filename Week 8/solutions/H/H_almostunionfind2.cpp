#include <bits/stdc++.h>
using namespace std;

// This solution uses a union-find data structure to implement each operation.
// Keeping track of the sums and sizes of each set is fairly simple with
// normal union-find, but when we move an element, we run into some issues.
// If the element we moved was the root of the set, we can't directly update it
// without moving the entire set. To solve this, we can create a new node
// to represent the element we moved, and place this new node in the destination
// set. This solution is faster than the alternative given, at the cost of 
// being slightly more complicated.

const int N = 1e5 + 5;
int root[N];
long long sum[N];
int sz[N];
int find(int x){
    if(root[x] == -1) return x;
    return root[x] = find(root[x]);
}
int ptr;
void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    sz[ptr] = sz[x] + sz[y];
    sum[ptr] = sum[x] + sum[y];
    root[x] = ptr;
    root[y] = ptr;
    ptr++; // create a new node to represent the merged set
}
void move(int x, int y){
    int rx = find(x), ry = find(y);
    // create a new node with (ry) and (x)
    // in case (x == rx)
    sum[rx] -= x;
    sz[rx]--;
    root[x] = ptr;
    root[ry] = ptr; // Still create a new node to represent the merged set.
                    // We don't have to worry about moving 'x', because it won't
                    // be the root of any set (one of the ptr nodes will be)
    sum[ptr] = x + sum[ry];
    sz[ptr] = sz[ry] + 1;
    ptr++;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); // fast input/output
    int n, q;
    while(cin >> n >> q){
        memset(root, -1, sizeof root);
        for(int i = 1; i <= n; i++) {
            sz[i] = 1;
            sum[i] = i;
        }
        ptr = n + 1;
        while(q--){
            int t;
            cin >> t;
            if(t == 1){
                int x, y;
                cin >> x >> y;
                join(x, y);
            }else if(t == 2){
                int x, y;
                cin >> x >> y;
                if(find(x) == find(y)) continue;
                move(x,y);
            }else{
                int x;
                cin >> x;
                int rx = find(x);
                cout << sz[rx] << " " << sum[rx] << '\n';
            }
        }
    }
}