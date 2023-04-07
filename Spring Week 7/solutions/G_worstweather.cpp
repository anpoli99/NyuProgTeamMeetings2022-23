#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Tree{
    int a, b, m;
    Tree *left = nullptr, *right = nullptr;
    int max_val = -INF;
    int min_val = INF;
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
            max_val = min_val = v;
            return;
        }
        if(k <= m) left->update(k, v);
        else right->update(k, v);
        max_val = max(left->max_val, right->max_val);
        min_val = min(left->min_val, right->min_val);
    }
    int qrymax(int l, int r){
        if(l <= a && r >= b) return max_val;
        if(l > b || r < a) return -INF;
        return max(left->qrymax(l, r), right->qrymax(l, r));
    }
    int qrymin(int l, int r){
        if(l <= a && r >= b) return min_val;
        if(l > b || r < a) return INF;
        return min(left->qrymin(l, r), right->qrymin(l, r));
    }
};


#define YEAR first
#define RAIN second
int main(){
    ios::sync_with_stdio(0); cin.tie(0); // Fast IO
    int n = -1;
    while(true){
        if(n != -1) cout << '\n';
        cin >> n;
        if(n == 0) {
            cin >> n;
            break;
        }
        Tree t(0, n - 1);
        vector<pair<int,int>> a(n);
        set<pair<int,int>> idx;
        for(int i = 0; i < n; i++){
            cin >> a[i].YEAR >> a[i].RAIN;
            idx.insert({a[i].YEAR, i});
            t.update(i, a[i].RAIN);
        }
        int qr;
        cin >> qr;
        while(qr--){
            int l, r;
            cin >> l >> r;
            auto itl = idx.lower_bound({l, -INF}); // First year > l
            auto itr = idx.lower_bound({r, -INF});
            int i, j;
            if(itl == idx.end() || itl->YEAR > r){
                // no known years in range
                cout << "maybe\n";
                continue;
            }
            int l_rain = -1, r_rain = -1; // -1 = unknown 
            if(itl->YEAR == l){
                l_rain = a[itl->second].RAIN;
                i = itl->second + 1;
            }else{
                i = itl->second;
            }
            if(itr == idx.end() || itr->YEAR > r){
                j = (--itr)->second;
            }else{
                j = itr->second - 1;
                r_rain = a[itr->second].RAIN;
            }
            bool ok = true;
            if(l_rain != -1 && r_rain != -1){
                ok &= l_rain >= r_rain; // Condition 2 in problem statement
            }
            if(l_rain != -1){
                // Logical conclusion of conditions 2 and 3 (unspecified directly)
                ok &= t.qrymax(i,j) < l_rain; 
            }
            if(r_rain != -1){
                ok &= t.qrymax(i,j) < r_rain; // Condition 3 in problem statement
            }

            if(!ok){
                // wasn't maximum; claim is false
                cout << "false\n";
            }else if(l_rain != -1 && r_rain != -1 && (j - i) == (r - 1) - (l + 1)){
                // we know rain for all years; claim is true
                cout << "true\n";
            }else{
                // claim could be true, but we're missing some years
                cout << "maybe\n";
            }
        }
    }
}  