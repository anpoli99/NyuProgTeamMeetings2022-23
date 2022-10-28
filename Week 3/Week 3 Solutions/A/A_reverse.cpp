#include <bits/stdc++.h>
using namespace std;

/*
* You don't need a stack for this problem!
* But since it's data structures week, I'll implement this solution with one.
*/
vector<int> reverse_list(vector<int>& a){
    vector<int> ans;
    stack<int> s;
    for(int i : a) {
        s.push(i);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = reverse_list(a);
    for(int i : ans){
        cout << i << endl;
    }

}
