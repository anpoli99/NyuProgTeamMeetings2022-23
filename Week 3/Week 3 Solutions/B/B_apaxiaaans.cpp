#include <bits/stdc++.h>
using namespace std;

/*
* You don't need a queue for this problem!
* But since it's data structures week, I'll implement this solution with one.
*/
string apaxiaaans(string& s){
    queue<char> q;
    for(char c : s) q.push(c);
    string ans = "";

    while(!q.empty()){
        char c = q.front();
        q.pop();
        // extract from the front of the queue
        if(q.empty() || c != q.front()){
            // if the next character is the same, skip it
            ans += c;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << apaxiaaans(s) << endl;
}
