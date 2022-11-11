#include <bits/stdc++.h>
using namespace std;

// There's some non DP approaches to this problem
// If you wanted to get started w/ a DP approach, I'd recommend something like this:
const int L = 40 + 5, W = 1000 + 5;
bool visited[L][W];
string ans;
bool solve(int i, int j){
    // TODO: implement this function
    // Return true if we find a word of length i with weight j
    return false;
}
string weightofwords(int l, int w){
    if(!solve(l, w)){
        return "impossible";
    }
    return ans;
}

int main(){
    int l, w;
    cin >> l >> w;
    cout << weightofwords(l, w) << '\n';
}