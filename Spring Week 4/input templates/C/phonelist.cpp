#include <bits/stdc++.h>
using namespace std;

bool phonelist(int n, vector<string> s){
    // Your code goes here
    return false;
}

int main(){
    int qrys;
    cin >> qrys;
    while(qrys--){
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i = 0; i < n; i++) cin >> s[i];

        cout << (phonelist(n, s) ? "YES" : "NO") << endl;
    }
}