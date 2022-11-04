#include <bits/stdc++.h>
using namespace std;

vector<pair<string,int>> opensource(vector<string>& lines){
    // Your code to find the number of members per project goes here
    return vector<pair<string,int>>(); // Replace this line with your code
}

int main(){
    string s;
    vector<string> lines;
    while(true){
        getline(cin, s);
        if(s == "1"){
            auto ans = opensource(lines);
            for(auto p : ans){
                cout << p.first << ' ' << p.second << '\n';
            }
            lines.clear();
        }else if(s == "0"){
            break;
        }else{
            lines.push_back(s);
        }
    }
}