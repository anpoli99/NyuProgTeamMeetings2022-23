#include <bits/stdc++.h>
using namespace std;

// input format: a and b are vectors of length n/m respectively
int cd(int n, int m, vector<int>& a, vector<int>& b){
    int ans = 0;
    unordered_set<int> s = {a.begin(), a.end()};
    for(int i = 0; i < m; i++){
        if(s.count(b[i])){
            ans++;
        }
    }
    return ans; 
}

int main(){
    // Makes cin and cout faster by removing the synchronization between the C and C++ standard streams.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n >> m){
        if(!n && !m){
            break;
        }
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        cout << cd(n, m, a, b) << '\n';
    }
}