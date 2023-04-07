#include<bits/stdc++.h>
using namespace std;

// It's always optimal to destroy K floors, and
// then destroy whatever buildings are left one 
// at a time. So what's the optimal K? Since 
// we know all the buildings ahead of time, we 
// can sort the array and test each K one-by-one.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); // Fast IO

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int ans = n; // Destroy all buildings one at a time
    for(int i = 0; i < n; i++){
        // Destory all buildings with height <= a[i]
        // with a[i] detonations. Then destroy the rest
        // one at a time.
        ans = min(ans, n - i - 1 + a[i]); 
    }
    cout << ans << '\n';

}