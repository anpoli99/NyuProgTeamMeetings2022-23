#include <bits/stdc++.h>
using namespace std;

int doublepassword(string s, string t){
    // The input is small enough that we can use brute force
    int ans = 0;
    for(int i = 0; i < 10000; i++){
        string p = to_string(i);
        while(p.size() < 4) p = "0" + p;
        bool okay = true;
        for(int j = 0; j < 4; j++){
            if(s[j] != p[j] && t[j] != p[j]) okay = false;
        }
        if(okay) ans++;
    }
    return ans;
    // alternate solution
    // int ct = 0;
    // for(int i = 0; i < 4; i++) ct += (s[i] != t[i]);
    // return (1 << ct); // 2^{mismatched digits}
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << doublepassword(s, t) << endl;
}