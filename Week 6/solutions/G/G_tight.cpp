#include <bits/stdc++.h>
using namespace std;


const int N = 100 + 5;
double dp[N][N];
bool vis[N][N];
int n, k;
double solve(int i, int j){
    // There's only (at most) 2 neighbors that satisfy the "tight" condition
    // We can try both of them and take their sum
    // The proportion of lists that take any given number as the next element is 
    // 1 / (k + 1)
    if(i == n) return 1;
    double& ans = dp[i][j];
    if(vis[i][j]) return ans;
    vis[i][j] = true;
    ans = solve(i + 1, j) / (k + 1);
    if(j > 0) ans += solve(i + 1, j - 1) / (k + 1);
    if(j < k) ans += solve(i + 1, j + 1) / (k + 1);
    return ans;
}
int main() {
    cout << fixed << setprecision(10); // another 'magic line'
    // enforces that it will always print 10 decimal places
    // otherwise could get WA due to rounding errors
    while(cin >> k >> n){
        memset(vis, false, sizeof vis);
        double ans = 0;
        for(int i = 0; i <= k; i++){
            ans += solve(1, i) / (k + 1);
        }
        cout << ans * 100 << '\n';
    }
}