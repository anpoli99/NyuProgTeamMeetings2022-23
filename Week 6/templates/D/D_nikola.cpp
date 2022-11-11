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
    // TODO: implement this function
    // (What are i and j?)
    return -1;
}

int nikola(){
    memset(dp, -1, sizeof dp);
    return -1; // return solve(?, ?);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << nikola() << '\n';
}