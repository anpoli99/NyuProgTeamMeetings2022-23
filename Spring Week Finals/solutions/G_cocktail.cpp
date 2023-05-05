#include "bits/stdc++.h"
using namespace std;
 
// It's clearly optimal to drink the shortest-lasting
// potion last, so let's sort the potions, and keep track
// of when they will expire. If one of them runs out before
// we drink them all, we can't get this achievement. 


int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int last_time = 1e9 + 5;
    bool okay = true;
    int time = 0;
    for(int i = 0; i < n; i++){
        last_time = min(last_time, time + a[i] + t);
        if(time + t >= last_time){
            okay = false;
            break;
        }
        time += t;
    }
    if(okay) cout << "YES\n";
    else cout << "NO\n";
}