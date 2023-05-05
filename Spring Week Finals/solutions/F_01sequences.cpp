#include "bits/stdc++.h"
using namespace std;

// If we scan from left to right, an inversion appears when there
// is a 0 after a 1. Let's keep track of the number of zeroes across
// _all_ possible strings (then the number of ones is the number of 
// characters in all strings - the number of zeroes). For each 0, add
// an inversion for each 1.  

using ll = long long;
const ll mod = 1e9 + 7;
int main(){
    string s;
    cin >> s;
    int n = s.size(); 
    ll ans = 0;
    //zero_ct = number of zeroes across all possible strings
    ll zero_ct = 0, possible_strings = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            ans += (possible_strings * i) - zero_ct; // add one for all previous 1s
            zero_ct += possible_strings; // all possible strings have a zero here
            ans %= mod;
            zero_ct %= mod;
        }else if(s[i] == '?'){
            ans *= 2; // every previous inversion appears in two strings;
            // either we set this position to 0 or 1
            ans += (possible_strings * i) - zero_ct; // If we set it to a 0,
            //we create an inversion with every previous 1
            zero_ct *= 2;
            zero_ct += possible_strings;

            possible_strings *= 2;

            ans %= mod;
            zero_ct %= mod;
            possible_strings %= mod;
        }
    }
    cout << ans << endl;
}