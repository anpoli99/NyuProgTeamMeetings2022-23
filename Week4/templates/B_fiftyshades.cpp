#include <bits/stdc++.h>
using namespace std;

bool fiftyshades(string& s){

    for(char& c : s){
        c = tolower(c); // std is helpful!
        // can also do:
        // if(c >= 'A' && 'c' <= 'Z') c += 'a' - 'A';
        // or something like that
    }
    if(s.find("rose") != string::npos) return true;
    if(s.find("pink") != string::npos) return true;
    // More useful stdlib :)

    // We could also do something like: 
    /*
    for(int i = 0; i + 4 <= s.size(); i++){
        if(s.substr(i, 4) == "rose") return true;
        if(s.substr(i, 4) == "pink") return true;
    }
    */
    return false;
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