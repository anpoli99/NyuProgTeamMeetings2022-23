#include <bits/stdc++.h> 
using namespace std;

int free_weights(int N, vector<int>& a, vector<int>& b){
    // Your code to find heaviest weight required goes here
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << free_weights(n, a, b) << endl;
}   