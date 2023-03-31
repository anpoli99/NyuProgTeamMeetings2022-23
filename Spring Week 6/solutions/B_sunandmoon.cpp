#include <bits/stdc++.h>
using namespace std;

// The inclusion that there will be an eclipse within
// 5000 years from the problem statement makes the 
// implementation of this problem much simplier; we 
// can just keep iterating the moon's and sun's 
// positions until they are aligned, and count how
// many steps that takes

int main(){
    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;
    int ct = 0;
    while(ds != 0 || dm != 0){
        ds = (ds + 1) % ys;
        dm = (dm + 1) % ym;
        ++ct;
    }
    cout << ct << endl;
}  