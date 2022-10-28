#include <bits/stdc++.h>
using namespace std;

// format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
// 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
string join_strings(int n, vector<string>& s, vector<int>& a, vector<int>& b){
    // First we'll find the order of the indices in the final string, then we can concatenate them at the end
    // To do this, notice that when we concatenate two strings (i)(j), it becomes one string
    // beginning with 'i' and ending with 'j'
    // So the only thing we need to know to join two strings is which original string was 
    // first and which was last.

    vector<int> next(n + 1, -1); // next[i] will store the index of the next string (the one that gets concatenated to the back of 'i')
    vector<int> last(n + 1); // last[i] will store the last string concatenated to 'i'
                            // for example, if (1 2) was concatenated to (3 4), then next[1] = 2 and last[1] = 4

    for(int i = 1; i <= n; i++) last[i] = i; // originally last[i] = i, because each string is its own last string

    vector<bool> is_beginning(n + 1, true); // is_beginning[i] will store whether or not 'i' is the beginning of a string
                                            // we'll remove each one that isn't when we append it to another string
    
    for(int i = 0; i < n - 1; i++){
        int x = a[i], y = b[i];
        next[last[x]] = y; // append 'y' to the end of 'x'
        last[x] = last[y]; // 'x' now ends with the same string that 'y' ends with
        is_beginning[y] = false; // 'y' is no longer the beginning of a string
    }
    int curr = 1;
    // find the beginning of the first string
    while(!is_beginning[curr]) curr++;
    // now we'll build the final string
    string ans = "";
    for(int i = 1; i <= n - 1; i++) {
        ans += s[curr];
        curr = next[curr];
    }
    return ans;
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
