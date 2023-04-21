#include <bits/stdc++.h>
using namespace std;

// The amount of money we make only increases, so if we
// have enough after 'k' days, we will always have enough
// after 'k + x' days for any 'x'. This means that we can
// binary search for the answer. When checking if a day 'k'
// is valid, we can greedily pick the most profitable stocks

const int N = 1e5 + 5;
long long profit[N], cost[N];
bool check(int n, long long k, int m){
    long long total_profit = 0;
    for(int i = 1; i <= n; i++){
        if(profit[i] * k > cost[i]){
            total_profit += profit[i] * k - cost[i];
        }
        if(total_profit >= m) return true; // stop early to prevent overflow
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> profit[i] >> cost[i];
    }
    long long lo = 0, hi = 5e9 + 5;  // 1e9 could be too small
    while(lo < hi){
        long long mid = (lo + hi) / 2;
        if(check(n, mid, m)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}