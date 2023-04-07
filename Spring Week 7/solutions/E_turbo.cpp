#include <bits/stdc++.h>
using namespace std;

// For this problem, if we let p[i] denote the
// position of i in the permutation, then we can 
// simulate the process in reverse. For each i in order
// (n / 2 + 1, n / 2, n / 2 + 2....n, 1)
// we can query in the direction of where i should go to
// count how many swaps we need to put it in its position.


struct Tree{
    int a, b, m;
    Tree *left = nullptr, *right = nullptr;
    int ct = 0;
    Tree(int _a, int _b){
        a = _a; b = _b;
        m = (a + b) / 2;
        if(a != b){
            left = new Tree(a, m);
            right = new Tree(m + 1, b);
        }
    }
    void update(int k, int v){
        if(a == b){
            ct += v;
            return;
        }
        if(k <= m) left->update(k, v);
        else right->update(k, v);
        ct = left->ct + right->ct;
    }
    int qry(int l, int r){
        if(l <= a && r >= b) return ct;
        if(l > b || r < a) return 0;
        return left->qry(l, r) + right->qry(l, r);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); // Fast IO
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    Tree t(1, n);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<int> ans(n + 1);
    for(int i = (n + 2) / 2; i <= n; i++){
        t.update(p[i], 1);
        ans[i] = t.qry(p[i] + 1, n);
        int j = n - i + 1; // element that comes right after i
                            // (except in edge case where they are equal)
        if(j != i){ 
            t.update(p[j], 1);
            ans[j] = t.qry(1, p[j] - 1);
        }
    }
    for(int i = 1; i * 2 <= n + 1; i++) {
        int j = n - i + 1;
        cout << ans[i] << '\n';
        if(j != i) cout << ans[j] << '\n';
    }
}  