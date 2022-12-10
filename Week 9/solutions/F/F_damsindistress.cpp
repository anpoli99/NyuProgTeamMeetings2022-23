#include <bits/stdc++.h>
using namespace std;

// In general if you see "river system" in a problem, it's a good idea
// to start thinking about trees. In this case, we're interested in
// the amount of water to break some parent dam. We can use a DFS
// to solve for this. The minimum using a given dam is the minimum of:
// - The cost of breaking the dam + (any extra water needed to break downstream dams)
// - The cost of breaking one of the dam's children
// A potential pitfall is not being careful about overflow. (for C++/Java users)

const int N = 2e5 + 5;
vector<int> e[N];
int parent[N], capacity[N], cur_amt[N];
using ll = long long;
ll solve(int k, ll water_required){ // water_required is for downstream dams
    ll ans = capacity[k] - cur_amt[k];
    if(water_required > capacity[k]){
        ans += water_required - capacity[k];
    }
    ll water_req_root = ans; // this is how much we need to break this dam
    for(int j : e[k]){
        ans = min(ans, solve(j, water_req_root));
    }
    return ans;
}
int main(){
    int n;
    cin >> n >> capacity[0]; 
    for(int i = 1; i <= n; i++){
        cin >> parent[i] >> capacity[i] >> cur_amt[i];
        e[parent[i]].push_back(i);
    }
    cout << solve(0, 0) << '\n';
}   
