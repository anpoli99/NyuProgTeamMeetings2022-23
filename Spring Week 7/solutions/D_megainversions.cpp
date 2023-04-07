#include<bits/stdc++.h>
using namespace std;

/*
For this problem, for all 'i' we can count
how many 'j' there are such that 'j' > 'i' and
a[j] < a[i]. Then we can repeat to find how many
j < i and a[i] > a[j]. The product of these values
is the number of "mega-inversions" at index i, so
summing over all i gives the answer.
*/

using ll = long long;
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> lower(n + 1), upper(n + 1);
    Tree t(1, n);
    for(int i = 1; i <= n; i++){
        upper[i] = t.qry(a[i] + 1, n);
        t.update(a[i], 1);
    }
    t = Tree(1, n);
    for(int i = n; i >= 1; i--){
        lower[i] = t.qry(1, a[i] - 1);
        t.update(a[i], 1);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1LL * lower[i] * upper[i];
    }
    cout << ans << '\n';
}  