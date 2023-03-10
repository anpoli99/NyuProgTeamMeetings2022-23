#include <bits/stdc++.h>
using namespace std;

vector<string> compound_words(vector<string>& words){
    // Your code here
    return {}; // Replace this line
}

int main(){
    ios_base::sync_with_stdio(false); // Just for speeding up I/O
    cin.tie(NULL);

    string s;
    vector<string> words;
    while(cin >> s){
        if(s == "###") break; // I find it helpful to have a line like this for reading from the terminal
        words.push_back(s);
    }
    auto res = compound_words(words);
    for(string& s : res) cout << s << '\n';
}