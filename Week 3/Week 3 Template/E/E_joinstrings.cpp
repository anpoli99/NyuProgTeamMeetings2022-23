#include <bits/stdc++.h>
using namespace std;

// format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
// 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
string join_strings(int n, vector<string>& s, vector<int>& a, vector<int>& b){
    /*
    Your code here; You should return the final concatenated string.
    */
    return ""; // This is just a placeholder.
}

int main(){
    // Boilerplate for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> s(n + 1);
    vector<int> a(n), b(n);
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n - 1; i++) {
        cin >> a[i] >> b[i];
    }

    cout << join_strings(n, s, a, b) << '\n';
    
}
