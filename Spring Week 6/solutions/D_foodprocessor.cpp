#include <bits/stdc++.h>
using namespace std;

// A greedy solution is sufficient; we always want to use
// the best possible blade for a given size, so as we
// go from largest to smallest blade, take the one with the
// smallest time to reduce the mass by half.

const double LINF = 1e18;
using pi = pair<int, int>;
const char nl = '\n';
int main(){
    int start, target, n;
    cin >> start >> target >> n;
    vector<pi> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    // Store each blade as pair (max_size, time_required) and sort
    // with largest maximum sizes first
    sort(v.begin(), v.end(), greater<pi>()); 
    if(v[0].first < start){
        // No blade has a small enough 'maximum size' to cut anything;
        // only case where it is impossible
        cout << -1 << nl;
        return 0;
    }
    double rate = LINF; // any large constant is fine
    double prev_size = start;
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i].first < target){ 
            // No other blades can matter; we've reached the target
            break;
        }
        if(v[i].second > rate) continue; // If new rate is worse, ignore it; no reason to use this blade

        if(v[i].first < prev_size){ 
            // Only case where this line matters:
            // if the blade is larger than the starting size,
            // we don't want to update our answer (or the previous size)
            double diff = v[i].first / prev_size;  
            double time = rate * -log(diff) / log(2); // If 'rate' is the time it takes to half the current size,
                                        // log(1 / diff) / log(2) is the time it takes to reduce it by 'diff'
            ans += time;
            prev_size = v[i].first;
        }
        rate = v[i].second;
    }
    double diff = target / prev_size;
    double time = rate * -log(diff) / log(2);
    ans += time;
    cout << ans  << nl;
}  