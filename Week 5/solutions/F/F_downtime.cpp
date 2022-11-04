#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30) - 1;

int downtime(int n, int k, vector<int>& a){
    // There's other solutions to this problem, such as using a two-pointer approach.
    // If you implement it fast enough, we could just have an array that has the count of 
    // requests at each time, and then iterate over every subarray of size 1000.
    // I think it's worth noting that the set approach requires almost no code compared to
    // these alternatives and is still pretty fast.

    set<pair<int,int>> s; 
    for(int i = 0; i < n; i++){
        // A useful trick; we can find the index of a lower bound in a set in O(log n) time
        // by storing it as a pair
        s.insert({a[i], i}); 
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound({a[i] - 1000, INF});
        ans = max(ans, i - it->second + 1);
    }
    ans = (ans + k - 1) / k;
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << downtime(n, k, a) << '\n';
}