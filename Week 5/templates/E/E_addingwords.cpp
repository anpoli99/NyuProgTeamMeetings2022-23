#include <bits/stdc++.h>
using namespace std;

// Each string is a line of input
// You can split the line into strings using the stringstream class:
// stringstream ss(line);
// vector<string> words;
// string word;
// while(ss >> word) words.push_back(word);
vector<string> adding_words(vector<string>& lines){
    vector<string> result;
    // Your code to process the lines goes here
    return result;
}
int main(){
    // Makes cin and cout faster by removing the synchronization between the C and C++ standard streams.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<string> lines;
    while(getline(cin, line)){
        if(line == "#") break; // This is a useful way to debug
        lines.push_back(line);
    }
    vector<string> result = adding_words(lines);
    for(auto line : result){
        cout << line << '\n';
    }
}