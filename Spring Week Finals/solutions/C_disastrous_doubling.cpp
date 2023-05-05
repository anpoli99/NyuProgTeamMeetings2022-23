#include "bits/stdc++.h"
using namespace std;
 
// This is a harder problem, because of an apparent "contradiction",
// which is easy to not notice. We need to print the answer modulo
// 10^9 + 7, but if we take the mod early, we may hit zero when
// subtracting sooner than we should. Instead, we keep track of the 
// answer without taking the mod, and check if it gets sufficiently
// large. 

// Since we're only doubling at each step, once out answer is above
// 2^61, we've "escaped", and will always have enough to subtract
// 2^60.

const int mod = 1e9 + 7;
using ll = long long;
int main(){
    int n;
    cin >> n;
    ll x = 1;
    bool escaped = false;
    for(int i = 0; i < n; i++){
        ll b;
        cin >> b;
        x *= 2;
        x -= b;
        if(x > (1ll << 61)){
            escaped = true;
        }
        if(escaped){
            x %= mod;
        }else if(x < 0){
            cout << "error\n";
            return 0;
        }
    }
    x %= mod;
    if(x < 0){
        x += mod;
    }
    cout << x << endl;
}