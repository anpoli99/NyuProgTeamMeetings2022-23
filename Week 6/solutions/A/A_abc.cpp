#include <bits/stdc++.h>
using namespace std;

// input format: 'a' is a vector of length 3, the 3 numbers in the first line
// return the answer as a vector of 3 numbers
vector<int> abc(vector<int> a, string s){
    vector<int> b;
    sort(a.begin(), a.end());   
    for(char c : s){
        b.push_back(a[c - 'A']);
    }
    return b;
}

int main(){
    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> b = abc(a, s);
    for(int i = 0; i < 3; i++){
        cout << b[i] << " ";
    }
    cout << '\n';
}