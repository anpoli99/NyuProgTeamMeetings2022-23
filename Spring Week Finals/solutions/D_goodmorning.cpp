#include "bits/stdc++.h"
using namespace std;

// You can turn this into a graph problem by noticing that
// for each button, we can either go down (+ 3) or left (+1).
// This is an implicit graph, and we can run a DFS to find all
// reachable values. Then we can store them in a set, and check
// the left/right neighbors to find the closest to each query

set<int> reachable;
void dfs(int k, int x){
    if(k >= 10) return;  // Invalid button; buttons are 1-9
    if(x > 400) return; // Prune the search: if x = 400, any 1 digit number is closer
    reachable.insert(x);
    if(k != 8 && k != 0){ // Easy way to code "moving down"; we're really adding 3
        dfs(k + 3, x);
    }
    if(k == 8){ // ... with the exception of 8, which has 0 below it
        dfs(0, x);
    }
    if(k % 3 != 0){ // If not a left-most button, try moving left
        dfs(k + 1, x); 
    }
    if(x || k) dfs(k, x * 10 + k); // Don't add leading 0s, but we can add any other
    // number as many times as we want 
}
int main(){

    for(int i = 1; i <= 9; i++){
        dfs(i, 0);
    }
    int qrys;
    cin >> qrys;
    while(qrys--){
        int x;
        cin >> x;
        auto it = reachable.lower_bound(x);
        int ans = 1e9;
        if(it != reachable.end() && abs(*it - x) < abs(ans - x)){
            // Neighbor above
            ans = *it;
        }
        if(it != reachable.begin()){
            --it;
            if(abs(*it - x) < abs(ans - x)){
                // Neighbor below
                ans = *it;
            }
        }
        cout << ans << endl;
    }
}