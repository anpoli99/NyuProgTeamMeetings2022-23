#include<bits/stdc++.h>
using namespace std;

/*
For this problem, we can allocate 'm' extra spaces. For each
query where we remove an element an put it on top, we'll add
it to the next available space. We can then use a segement
tree to count how many elements are ahead of any other.
*/

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
    int qr;
    for(cin >> qr; qr; qr--){
        int n, m;
        cin >> n >> m;
        Tree t(1, n + m);
        vector<int> current_position(n + 1);
        for(int i = 1; i <= n; i++) {
            t.update(i + m, 1);
            current_position[i] = i + m;
        }
        for(int i = 1; i <= m; i++){
            int k;
            cin >> k;
            t.update(current_position[k], -1);
            cout << t.qry(1, current_position[k]) << " ";
            current_position[k] = m - i + 1;
            t.update(current_position[k], 1);
        }
        cout << '\n';
    }
}  