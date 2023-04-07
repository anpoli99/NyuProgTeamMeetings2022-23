#include<bits/stdc++.h>
using namespace std;

// For this problem, we can scan through the list
// and update the launch day if we find a new minimum.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); // Fast IO

    int n;
    cin >> n;
    int min_space_junk = 1e9 + 5;
    int best_day = -1;
    for(int i = 0; i < n; i++){
        int space_junk;
        cin >> space_junk;
        if(space_junk < min_space_junk){
            min_space_junk = space_junk;
            best_day = i;
        }
    }
    cout << best_day << '\n';
}