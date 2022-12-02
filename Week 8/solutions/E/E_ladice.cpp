#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int root[N];
bool used[N];
int find(int x){
    if(root[x] == -1) return x;
    return root[x] = find(root[x]);
}
int main(){
    int n, l;
    cin >> n >> l;
    // If we just do exactly what the problem statement says,
    // it will be correct but take O(n^2). To speed up the 
    // steps where we are looking for the final sock drawer,
    // we can use the same path compression technique we use
    // in union-find.
    // This implementation uses 0 to represent no sock drawer
    // available.
    memset(root, -1, sizeof(root));
    for(int i = 1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        bool okay = true;
        if(!used[a]){
            // Place in drawer A
            used[a] = true;
            int rb = find(b);
            if(rb == a){
                root[a] = 0; // B's final drawer is A, but A is full
            }else{
                root[a] = rb; // A's final drawer is B's final drawer
            }
        }else if(!used[b]){
            used[b] = true;
            int ra = find(a);
            if(ra == b){
                root[b] = 0; // same logic for B
            }else{
                root[b] = ra;
            }
        }else{
            int ra = find(a), rb = find(b);
            if(ra != 0){
                // if find(a) == 0, then a is full
                used[ra] = 1; // we're using this drawer so still mark it as used
                if(ra == rb){
                    root[ra] = 0; // same idea as above; B's final drawer is A, but A is full
                }else{
                    root[ra] = rb;
                }
            }else if(rb != 0){
                used[rb] = 1;
                // ra == 0; can't be equal
                root[rb] = ra; // = 0
            }else{
                okay = false; // all drawers are full; can't place this sock
            }
        }
        if(okay){
            cout << "LADICA\n";
        }else{
            cout << "SMECE\n";
        }
    }
}