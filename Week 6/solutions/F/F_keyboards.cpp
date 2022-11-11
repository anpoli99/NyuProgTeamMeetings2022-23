#include <bits/stdc++.h>
using namespace std;

#define uset unordered_set // I like this because I am extremely lazy

const int INF = (1 << 30) - 1;
const int N = 1e3 + 5;

int dp[N][N];
int n, m;
uset<int> notes[N]; // for instrument i
vector<int> played_by[N]; // for note i
int a[N];
int solve(int i, int j){
    // i = idx of current note, j = current instrument
    // if j == 0, we need to switch instruments
    // we can store which instruments play which notes and iterate, and just recursively call again
    if(i == m + 1) return 0;
    int& ans = dp[i][j];
    if(ans != -1) return ans;
    if(j == 0){
        ans = INF;
        for(int k : played_by[a[i]]){
            ans = min(ans, solve(i + 1, k));
        }
        ans += 1; // +1 for switching instruments
    }else if(notes[j].count(a[i])){
        // current instrument can play current note; don't switch
        ans = solve(i + 1, j);
    }else{
        // current instrument doesn't play this note, so we need to switch
        ans = solve(i, 0);
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(; k--; ){
            int x;
            cin >> x;
            notes[i].insert(x);
            played_by[x].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0) - 1 << '\n';
}
