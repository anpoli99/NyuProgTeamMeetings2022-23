#include <bits/stdc++.h>
using namespace std;

int awkward_party(int n, vector<int>& a){
    // Your code to find the awkwardness goes here
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << awkward_party(n, a) << '\n';
}