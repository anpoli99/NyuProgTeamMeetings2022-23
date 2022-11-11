#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 5, 10, 25, 50}; // You can change this, and we will always get the right answer
int dp[400];
int min_coins(int n){
    int& ans = dp[n];
    if(ans != -1) return ans;
    ans = 1e9;
    for(int c : coins){
        // try using each coin
        if(n - c >= 0){
            ans = min(ans, 1 + min_coins(n - c));
        }
    }
    return ans;
}

vector<int> ans;
// call this after calling min_coins to get the actual coins
void get_coins(int n){
    if(n == 0) return;
    for(int c : coins){
        if(n - c >= 0 && dp[n] == 1 + dp[n - c]){
            ans.push_back(c);
            get_coins(n - c);
            return;
        }
    }
}

int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; // base case; 0 coins are needed to make 0
    cout << min_coins(n) << endl;
    get_coins(n);
    for(int i : ans) cout << i << " ";
    cout << endl;
}