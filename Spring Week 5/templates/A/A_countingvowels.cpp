#include <bits/stdc++.h>
using namespace std;

int counting_vowels(string line){
    // Your code here
    return -1; // Replace this line
}

int main(){
    ios_base::sync_with_stdio(false); // Just for speeding up I/O
    cin.tie(NULL);

    string s;
    getline(cin, s);
    while(s.back() < 32) s.pop_back(); // Remove trailing whitespace
    cout << counting_vowels(s) << '\n';
}