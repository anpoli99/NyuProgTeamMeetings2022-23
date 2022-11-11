#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30) - 1;
const int N = 2000 + 20;
int dp[N][N];
int delegates[N], cost[N]; 
int solve(int i, int j){
    // i is the index of the current region
    // delegates[i] is the number of delegates gained for winning region i
    // cost[i] is the number of voters we need to persuade to win region i
    // cost[i] is precalculated below
    if(j < 0) return 0;
    if(!i) return j ? INF : 0;
    int& res = dp[i][j];
    if(res != -1) return res;
    // try either winning region i or not
    res = min(solve(i - 1, j), solve(i - 1, j - delegates[i]) + cost[i]);
    res = min(res, INF); // no overflow
    return res;
}
int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> delegates[i];
        sum += delegates[i];
        int c, f, u;
        cin >> c >> f >> u;
        if(c + u <= f){
            // can't win this region; cost is INF
            cost[i] = INF;
        }else{
            if(f > c){
                // we're losing in this region, so we need at least (f - c) votes to win
                cost[i] += f - c;
                u -= f - c;
                cost[i] += u / 2 + 1; // strict majority of the remaining votes
            }else{
                u -= c - f;
                if(u >= 0) cost[i] += u / 2 + 1; // strict majority of the remaining votes
                // (but if it's negative, we'll win this region no matter what, so cost[i] = 0)
            }
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(n, sum / 2 + 1); // strict majority of delegates
    if(ans >= INF) cout << "impossible" << '\n';
    else cout << ans << '\n';
}   