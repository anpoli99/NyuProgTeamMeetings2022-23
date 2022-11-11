#include <bits/stdc++.h>
using namespace std;

string a,b;
int dp[100][100];
// returns the length of the longest common subsequence of a[0..i] and b[0..j]
int longest_common_subsequence(int i, int j){ 
    if(i < 0 || j < 0) return 0;
    int& ans = dp[i][j]; // nice trick to avoid having to look up the position in the dp table every time
    if(ans != -1) return ans;
    if(a[i] == b[j]){
        // characters match; greedily add them to the answer
        ans = 1 + longest_common_subsequence(i - 1, j - 1);
    }else{
        // check moving one character in both strings and see which one gives the longer subsequence
        ans = max(longest_common_subsequence(i - 1, j), longest_common_subsequence(i, j - 1));
    }
    return ans;
}

// call this after calling longest_common_subsequence to get the actual subsequence
string ans;
void build_lcs(int i, int j){
    if(i < 0 || j < 0) {
        ans = "";
        return;
    }
    if(a[i] == b[j]){
        build_lcs(i - 1, j - 1);
        ans += a[i];
    }else if(i > 0 && dp[i - 1][j] > dp[i][j - 1]){ // move in the direction that gives the longer subsequence
        build_lcs(i - 1, j);
    }else{
        build_lcs(i, j - 1);
    }
}

int main(){
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << longest_common_subsequence(a.size() - 1, b.size() - 1) << endl;
    build_lcs(a.size() - 1, b.size() - 1);
    cout << ans << endl;
}