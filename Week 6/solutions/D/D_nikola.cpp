#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30) - 1;
const int N = 2000 + 20;
int a[N]; // Just for convenience I'm leaving 'a' and 'n' global
            //Note that I'm indexing 'a' starting from 1
int n;

// AFAIK for this problem you need DP
// Here's a template to get started on that
int dp[N][N]; 
int solve(int i, int j){
    if(i == n) return a[i];
    if(i > n || i < 1) return INF;
    int& res = dp[i][j];
    if(res != -1) return res;
       // jump forward 'j' increasing the jump size, or jump back 'j - 1' leaving the jump size the same
    res = min(solve(i + j, j + 1), solve(i - j + 1, j)) + a[i];
    return res;
}

int nikola(){
    memset(dp, -1, sizeof dp);
    return solve(2, 2); // first jump must be from 1 to 2, so we start at 2
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << nikola() << '\n';
}