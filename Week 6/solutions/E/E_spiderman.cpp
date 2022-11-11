#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30) - 1;
const int N = 2000 + 20;
int dp[N][N];
int visited[N][N];
int vis_idx = 1; // this is a helpful way to avoid having to clear the while dp array every test case
int a[N];
int n;
int solve(int i, int j){ // i is index of the jump, j is the current height
    if(j < 0) return INF;
    if(i == n) return j ? INF : 0;
    int& res = dp[i][j];
    if(visited[i][j] == vis_idx) return res;
    visited[i][j] = vis_idx;
    res = min(solve(i + 1, j - a[i]), solve(i + 1, j + a[i])); 
    res = max(res, j); // the max height is at least the current height
    return res;
}
string ans;
void build(int i, int j){ // after solving, we need to recreate the answer  
    // we can check both possibilities and see which one gives us the correct answer
    // for a given (i,j)
    if(i == n) return;
    int res = solve(i, j);
    if(res == solve(i + 1, j + a[i])){
        ans += 'U';
        build(i + 1, j + a[i]);
    }else{
        ans += 'D';
        build(i + 1, j - a[i]);
    }

}
int main(){
    int qr;
    cin >> qr;
    while(qr--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ans.clear();
        int res = solve(0, 0);
        if(res >= INF){
            cout << "IMPOSSIBLE\n";
        }else{             
            build(0, 0);
            cout << ans << '\n';
        }
        vis_idx++;
    }
}