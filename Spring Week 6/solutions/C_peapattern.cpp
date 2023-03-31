#include <bits/stdc++.h>
using namespace std;

// Similar to sun and moon, a sequence with less than 100
// numbers is small enough that we can iterate the entire
// sequence and look for a pattern. By keeping track of 
// the string's we've already seen, we can detect if we 
// fall into a cycle. Otherwise we need to check if we hit 
// the tartget string.

string next_string(string s){
    int ct[10] = {0}; // Keep track of how many of each character there are here
    for(char c : s) ct[c - '0']++;
    string r = "";
    for(int i = 0; i < 10; i++){
        if(ct[i]) r += to_string(ct[i]) + (char)(i + '0');
    }
    return r;
}
int main(){
    string s, t;
    cin >> s >> t;
    unordered_set<string> visited = {s};

    if(s == t){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 2; i <= 100; i++){
        s = next_string(s);
        if(visited.count(s)){
            cout << "Does not appear\n";
            return 0; //exit early
        }
        visited.insert(s);
        if(s == t){
            cout << i << endl;
            return 0; // exit early
        }
    }
    cout << "I'm bored\n";
}  