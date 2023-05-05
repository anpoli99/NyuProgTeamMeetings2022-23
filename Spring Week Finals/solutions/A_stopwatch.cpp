#include "bits/stdc++.h"
using namespace std;
 
// It's easiest to simulate each button press, keeping
// track of the time of the previous button press and 
// whether the stopwatch is currently running.

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int previous_time = 0;
    bool is_running = false;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(!is_running){
            previous_time = t;
            is_running = true;
        }else{
            ans += t - previous_time;
            is_running = false;
        }
    }
    if(is_running){
        cout << "still running" << endl;
    }else{
        cout << ans << endl;
    }
}