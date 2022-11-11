#include <bits/stdc++.h>
using namespace std;

int awkward_party(int n, vector<int>& a){
    // This is a callback to last week :) we can use a hash map to solve it
    unordered_map<int, int> prev;
    int ans = n; // base case according to problem statement
    for(int i = 0; i < n; i++){
        if(prev.count(a[i])){
            ans = min(ans, i - prev[a[i]]);
        }
        prev[a[i]] = i;
    }
    return ans;
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