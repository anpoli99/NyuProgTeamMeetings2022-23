#include <bits/stdc++.h>
using namespace std;

// There's some non DP approaches to this problem
// If you wanted to get started w/ a DP approach, I'd recommend something like this:
const int L = 40 + 5, W = 1000 + 5;
bool visited[L][W];
string ans;
bool solve(int i, int j){
    if(i == 0){
        return j == 0;
    }
    if(j < 0) return false;
    if(visited[i][j]){
        // visiting a state twice can't help us! if it returned false the first time,
        // it will return false the second time
        return false;
    }
    visited[i][j] = true;
    for(int k = 1; k <= 26; k++){
        if(solve(i - 1, j - k)){
            ans += (char)('a' + k - 1);
            return true;
        }
    }
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