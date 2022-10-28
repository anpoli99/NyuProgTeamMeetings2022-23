#include <bits/stdc++.h>
using namespace std;


vector<int> reverse_list(vector<int>& a){
    /*
    * Your code here; you should return a vector that contains the list 'a' in reverse order.
    */
    return {}; // this is just a placeholder
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
