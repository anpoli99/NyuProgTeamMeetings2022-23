#include <bits/stdc++.h>
using namespace std;

// This solution does all of the operations directly, but with one very big
// optimization: we use always insert the smaller set into the larger set.
// What does this do to the runtime? It turns out it makes it into an 
// n log n algorithm. Here's a not-quite-proof:
// The worst case for this solution is a complete binary tree, where 
// the height is log(n), and each non-leaf represents a merge operation. 
// If we had an unbalanced tree, we would only need to insert the smaller
// half so it would be faster. With a complete binary tree, we have to merge
// each element at most log(n) times, so the runtime is O(n log n).

// This problem changes that a little by moving each element, but there's
// at most O(N) moves in the worst case.

// With hashsets, the constant is large, but with N = 10^5, this solution
// still passes quickly. An advantage to this approach is that it's (conceptually)
// simpler, because we're directly implementing the problem statement, so
// it's easier to not get lost in abstractions.

const int N = 1e5 + 5;
int root[N]; // root[i] represents which set 'i' is in
long long sum[N];
unordered_set<int> s[N]; 

void join(int x, int y){
    if(root[x] == root[y]) return;
    x = root[x], y = root[y];
    if(s[x].size() < s[y].size()) swap(x, y); // smaller set into larger set
    for(int i : s[y]) {
        s[x].insert(i);
        root[i] = x;
        sum[x] += i;
    }
    s[y].clear();
    sum[y] = 0;
}
void place(int x, int y){
    s[root[x]].erase(x);
    sum[root[x]] -= x;
    s[root[y]].insert(x);
    sum[root[y]] += x;
    root[x] = root[y];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); // fast input/output

    int n, q;
    while(cin >> n >> q){
        for(int i = 1; i <= n; i++){
            root[i] = i;
            s[i] = {i};
            sum[i] = i;
        }
        while(q-- > 0){
            int t;
            cin >> t;
            if(t == 1){
                int x,y;
                cin >> x >> y;
                join(x, y);
            }else if(t == 2){
                int x,y;
                cin >> x >> y;
                place(x, y);
            }else{
                int x;
                cin >> x;
                cout << s[root[x]].size() << " " << sum[root[x]] << '\n';
            }
        }
    }
}


