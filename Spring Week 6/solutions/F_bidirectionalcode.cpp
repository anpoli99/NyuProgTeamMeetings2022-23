#include <bits/stdc++.h>
using namespace std;

// This problem has multiple approaches, but one is to
// greedily take the largest possible palindrome at each step.
// An easy way to see _why_ this works is that at each step,
// we can always eliminate at least half of all digits:
// ex.:
// 17236246742734
// 17236244263271 is the largest palindrome <= n
// XXXXXXX        are eliminated
// 982646246242444
// 982646242646289 is the largest palindrome <- n
// XXXXXXXX        are eliminated
// We could find this largest palindrome greedily, 
// but in my opinion, it's easier to binary search. 
// The only caveat here is we need to worry about an even case
// and an odd-length case. (242 vs 2442).

using ll = long long; 
ll to_even_palindrome(ll x){
    // Reflects x: 
    // 134 -> 134431
    ll res = x;
    ll add = 0;
    while(x > 0){
        res *= 10;
        add *= 10;
        add += x % 10;
        x /= 10;
    }
    return res + add;
}
ll to_odd_palindrome(ll x > 0){
    // Reflects x, _except_ the last digit:
    // 134 -> 13431
    ll res = x / 10;
    ll add = x % 10;
    x /= 10;
    while(x > 0){
        res *= 10;
        add *= 10;
        add += x % 10;
        x /= 10;
    }
    return res * 10 + add;
}
int main(){
    FASTIO
    PRECISION
    ll t;
    cin >> t;
    vector<ll> ans;
    while(t > 0){
        ll lo = 0, hi = 1e9;
        while(lo < hi){
            ll mid = (lo + hi + 1) / 2;
            if(to_odd_palindrome(mid) > t){
                hi = mid - 1;
            }else{
                lo = mid;
            }
        }
        ll cur = to_odd_palindrome(lo);
        lo = 0, hi = 1e9;
        while(lo < hi){
            ll mid = (lo + hi + 1) / 2;
            if(to_even_palindrome(mid) > t){
                hi = mid - 1;
            }else{
                lo = mid;
            }
        }
        cur = max(cur, to_even_palindrome(lo));
        ans.push_back(cur);
        t -= cur;
    }    
    cout << ans.size() << nl;
    for(auto x : ans){
        cout << x << nl;
    }
}  