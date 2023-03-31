#include <bits/stdc++.h>
using namespace std;

// This problem is fairly tricky. It's not _too_
// challenging to come up with a set of greedy rules
// that find the maximum value (although even implementing
// just that can become complicated), but this is made much
// more complicated with the requirement that it be 
// the lexicographical _minimum_. Notice that the score
// of a vertex is directly tied to the number of circles
// that surround it that we haven't taken. We can come up 
// with a formula for this value:

// Val(x) = a * floor(ancestors(x) / 2) + b * floor((ancestors(x + 1)) / 2)

// (the + 1 and floor here represent the switch from even and odd states).

// We can denote a vertex as "ready" if two conditions are met:

// 1) Removing any parents cannot increase the score
//  - So if there are an even number of parents, but b_i is negative, this 
//    condition is not satisfied for i
// 2) No descendants of i are also ready _and have a current state that is non-zero_
//  - For example, if j is a descendant of i, and j has an even number of ancestors,
//     (Assuming a_i is positive:)
//     if b_i is negative, j is not ready
//     if b_i is positive, i is not ready
//     if b_i is zero, _both i and j are ready_

// Using these rules, we can traverse every vertex to see which 
// which ready vertex is lexicographically earliest. Doing this
// is very difficult without passing information from a descendant
// to an ancestor, so I think using a DFS on a tree is the easiest
// approach, although you could also use a bottom-up approach.

const int INF = 1e9 + 5;
const int N = 2e3 + 5;
int a[N], b[N];
int x[N], y[N], r[N];
int count_ancestors[N];
bool used[N];
int get_score(int i){
    // Function to find the maximum possible score of a vertex
    int res = a[i] * ((count_ancestors[i] + 1) / 2);
    if(a[i] < 0 && (count_ancestors[i] & 1)){
        res -= a[i];
    }
    res += b[i] * (count_ancestors[i] / 2);
    if(b[i] < 0 && !(count_ancestors[i] & 1) && count_ancestors[i] > 0){
        res -= b[i];
    }
    if(a[i] + b[i] <= 0){
        if(a[i] > 0 && count_ancestors[i] > 0) res = a[i]; // Important edge case; we don't have to use b_i
        else res = 0;
    }
    return res;
}
inline int get_cur(int i){
    // Helper function to get current value
    return a[i] * ((count_ancestors[i] + 1) / 2) + b[i] * (count_ancestors[i] / 2);
}
vector<int> e[N];
pair<int, bool> dfs(int k){
    int res = INF; // We'll store the lexicographically smallest value here
    bool valid = true;
    for(int j : e[k]){
        auto [tmp, child_ok] = dfs(j);
        valid &= child_ok; // Vertex is invalid if any of its descendants are
        res = min(res, tmp);
    }
    if(!used[k] && valid && get_score(k) == get_cur(k)){
        res = min(res, k);
        valid &= get_score(k) == 0 
                || ((count_ancestors[k] & 1) && a[k] == 0) 
                || (!(count_ancestors[k] & 1) && b[k] == 0) 
                || (a[k] + b[k] == 0 && count_ancestors[k] > 1);
        // If the score is not zero, the value that would be removed is not zero and a_k + b_k is not zero,
        // removing any parents will decrease the potential value extracted from this vertex
    }
    return {res, valid};
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> r[i] >> a[i] >> b[i];
    }
    // Build a tree: assign each circle a "parent", 
    // which is the smallest circle that the i-th circle is inside
    // (i is a root if the parent doesn't exist)
    vector<int> roots;
    for(int i = 0; i < n; i++){
        int smallest_rad = INF;
        int p = -1;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            if(dx * dx + dy * dy <= r[j] * r[j] && r[i] < r[j]){ // i is inside j
                if(r[j] < smallest_rad){
                    smallest_rad = r[j];
                    p = j;
                }
                count_ancestors[i]++;
            }
        }
        if(p == -1){
            roots.push_back(i);
        }else{
            e[p].push_back(i);
        }
    }
    vector<int> ans;
    int ttl = 0;
    for(int i = 0; i < n; i++){
        int best = INF;
        for(int j : roots){
            best = min(best, dfs(j).first);
        }
        ans.push_back(best + 1);
        used[best] = true;
        // After finding the next vertex, update the ancestor counts
        for(int k = 0; k < n; k++){
            if(used[k]) continue;
            long long dx = x[best] - x[k];
            long long dy = y[best] - y[k];
            if(dx * dx + dy * dy <= r[best] * r[best] && r[k] < r[best]){
                count_ancestors[k]--;
            }
        }
        ttl += get_score(best);
    }
    cout << ttl << endl;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}  