#include <bits/stdc++.h>
using namespace std;

string sim(string line){
    // Your code here
    return ""; // Replace this line
}

int main(){
    ios_base::sync_with_stdio(false); // Just for speeding up I/O
    cin.tie(NULL);

    int cases;
    cin >> cases;
    cin.ignore();
    for(int _ = 0; _ < cases; _++){
        string line;
        getline(cin, line);
        while(line.back() < 32) line.pop_back(); // Remove trailing whitespace
        cout << sim(line) << '\n';
    }
}