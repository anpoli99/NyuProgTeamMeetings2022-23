
#include <bits/stdc++.h>
using namespace std;

bool fiftyshades(string& s){
    // Your code to check if the string is valid goes here
    return false; // This is a placeholder
}

int main(){
    int q;
    cin >> q;
    int total = 0;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        if(fiftyshades(s)) total++;
    }
    if(total == 0) cout << "I must watch Star Wars with my daughter" << endl;
    else cout << total << endl;
}