#include<bits/stdc++.h>
using namespace std;

// We can use DP to represent dropping a hammer and never
// using it again. The DP state in this case is (current nail,
// current hammer), and if we always move to the "next" hammer,
// we can avoid reusing one we dropped. So now the question 
// becomes which order should we use our hammers? This code solves 
// that by keeping track of a permutation representing the order of hammers. 

const int N = 3e5 + 5;
int a[N];
int dp[N][3];
vector<int> perm;
int solve(int i, int j){
    if(i == 0) return 0;    // Out of nails
    if(j == 3) return 0;    // Out of hammers
    int& r = dp[i][j];      // Notice: changing 'r' will also change dp[i][j]
    if(r != -1) return r;   // We've seen this DP state before
    r = solve(i - 1, j);
    if(a[i] == perm[j]) r += 1;  // Current hammer matches current nail; add one
    r = max(r, solve(i, j + 1)); // Try dropping this hammer and moving to the next
    return r;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> all_perms = {
        {0,1,2},
        {0,2,1},
        {1,0,2},
        {1,2,0},
        {2,0,1},
        {2,1,0}
    };
    int ans = 0;
    for(auto v : all_perms){ // Iterate over all permutations
        perm = v;
        memset(dp, -1, sizeof dp);
        ans = max(ans, solve(n, 0));
    }
    cout << ans << endl;
}  