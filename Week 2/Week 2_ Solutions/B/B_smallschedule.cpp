#include <bits/stdc++.h> 
using namespace std;

bool validate(int Q, int M, int S, int L, int time){
        for(int i = 0; i < M; i++){
        // greedily add as many long intervals as possible
        int long_intervals = min(L, time / Q); 
        L -= long_intervals;
        
        int remaining_time = time - long_intervals * Q;
        
        // use remaining time to add as many short intervals as possible
        
        // Edge case here; if we don't take the min, we should use long long (__int64) instead of int to prevent overflow
        int short_intervals = min(S, remaining_time); 
        S -= short_intervals;
    }
    return L == 0 && S == 0;
}
int small_schedule(int Q, int M ,int S, int L){
    int lo = 0, hi = 1.1e9;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(validate(Q, M, S, L, mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    int Q, M, S, L;
    cin >> Q >> M >> S >> L;
    cout << small_schedule(Q, M, S, L) << endl;
}   