#include <bits/stdc++.h>
using namespace std;

/*
* This is a linked list problem, but the key here is an idea called "path compression".
* When we find the final destination of a node, since we know that we're not going to
* change the structure in between the node and the destination, we can have the node
* point directly to the destination. This makes the problem O(n log n) instead of O(n^2).
* You can reduce this to O(n) by always making the root the node with the smaller size,
* but that's not necessary for this problem.
*
* An alternate implementation would store root[i] = i if i is it's own root.
* It's not uncommon to see root[i] = 0 or root[i] = -1 instead, because it makes some parts of 
* the implementation easier.
*/

const int N = 1e6 + 5;
int root[N]; 
int find(int x){
    if(root[x] == -1) return x;
    return root[x] = find(root[x]);
}
void join(int x, int y){
    x = find(x);
    y = find(y);
    root[x] = y;
}
int main(){
    // without this you might get TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(root, -1, sizeof(root)); // -1 means that the node is it's own root
    int n, qr;
    cin >> n >> qr;
    while(qr-- > 0){
        char c; int x,y;
        cin >> c >> x >> y;
        if(c == '?'){
            int root_x = find(x);
            int root_y = find(y);
            if(root_x == root_y) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }else{
            int root_x = find(x);
            int root_y = find(y);
            if(root_x != root_y) {
                // we might create a cycle if the roots are already connected
                join(x, y);
            }
        }
    }
    
}
