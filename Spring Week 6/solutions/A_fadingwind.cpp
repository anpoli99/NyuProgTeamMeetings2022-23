#include <bits/stdc++.h>
using namespace std;

// There are some tricky edge cases, but this problem
// ultimately wants you to implement the rules that it 
// lays out in the problem statement.

int main(){
    int h, k, v, s;
    cin >> h >> k >> v >> s;
    int ans = 0;
    while(h > 0){
        v += s;
        v -= max(1, v / 10);
        if(v >= k){
            h++;
        }else if(v > 0) {
            h--; 
            if(h == 0) v = 0;
        }else{ // v == 0
            h = 0;
            v = 0;
        }
        ans += v;
        if(s != 0) s--;
    }
    cout << ans << endl;
}  