#include <bits/stdc++.h>
using namespace std;

int downtime(int n, int k, vector<int>& a){
    // Your code to find the minimum number of servers goes here
    return -1; // Replace this line with your code
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << downtime(n, k, a) << '\n';
}