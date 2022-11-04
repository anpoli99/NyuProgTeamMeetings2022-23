#include <bits/stdc++.h>
using namespace std;


vector<int> greedily_increasing_subsequence(int n, vector<int>& a){
    // Your code to find the greedily increasing subsequence goes here
    return vector<int>(); // Replace this line with your code
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans = greedily_increasing_subsequence(n, a);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}