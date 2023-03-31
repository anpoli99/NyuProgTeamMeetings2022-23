#include <bits/stdc++.h>
using namespace std;

// returns: -1 if the number is correct, 0 if the number is lower, 1 if the number is higher
int query(int x){
    cout << x << endl; // ALWAYS use endl or (<< flush) to flush the output on an interactive problem!
    string s;
    cin >> s;
    if(s == "correct") return -1;
    if(s == "lower") return 0;
    return 1;
}
int main(){
    int ans = -1; // This is a placeholder
    // Your code here
    cout << ans << endl; // You should still quit early if you found the answer
}

