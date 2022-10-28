#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;


#include <bits/extc++.h> 
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll>   pl;
typedef pair<ld, ld>   pd;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef vector<ld>  vd;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
#define DBPRECISION std::cout << std::fixed << std::setprecision(4);
#define iter(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define _f first
#define _s second
const char nl   = '\n';
const int  INF  = (1 << 30) - 1;
const ll   LINF = 1e18;
const ld   PI   = 3.14159265358979323846L;
const ld   E    = 2.71828182845904523536L;
const ld   eps  = 1e-7;
#define dbx(x) cout << x << endl;
#define dbn(x) cout << x << nl;
#define dba(x) cout << x << " ";

pi grid[10][10];
int rkey[10], ckey[10], bkey[10];
inline int get_box(int x, int y){
    return (x / 2) * 3 + (y / 3);
}
void toggle(int x, int y, int digit){ 
    rkey[x] ^= (1 << digit);
    ckey[y] ^= (1 << digit);
    bkey[get_box(x, y)] ^= (1 << digit);
}
bool validate(int x, int y, int digit){
    if(rkey[x] & (1 << digit)) return false;
    if(ckey[y] & (1 << digit)) return false;
    if(bkey[get_box(x, y)] & (1 << digit)) return false;
    return true;
}
bool solve(int x, int y, bool first_digit){
    if(x == 6) return 1;
    if(y == 6) return solve(x + 1, 0, 1);
    if(grid[x][y]._s >= 0 && !first_digit) return solve(x, y + 1, 1);
    if(grid[x][y]._f >= 0 &&  first_digit) return solve(x, y, 0);
    for(int d = 1; d <= 9; d++){
        if(validate(x,y,d)){
            toggle(x,y,d);
            if(first_digit){
                grid[x][y]._f = d;
                if(d < grid[x][y]._s || grid[x][y]._s <= 0){
                    if(solve(x, y, 0)) return 1;
                }
                grid[x][y]._f = -1;
            } else{
                grid[x][y]._s = d;
                if(d > grid[x][y]._f){
                    if(solve(x, y + 1, 1)) return 1;
                }
                grid[x][y]._s = -1;
            }
            toggle(x,y,d);
        }
    }
    return 0;
}
int main(){
    FASTIO
    PRECISION
    memset(grid, -1, sizeof(grid));
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            string s;
            cin >> s;
            if(s[0] != '-'){
                grid[i][j]._f = s[0] - '0';
                toggle(i, j, grid[i][j]._f);
            }
            if(s.size() == 1){
                grid[i][j]._s = 0;
            }else if(s[2] != '-'){
                grid[i][j]._s = s[2] - '0';
                toggle(i, j, grid[i][j]._s);
            }
        }
    }
    solve(0, 0, 1);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << grid[i][j]._f;
            if(grid[i][j]._s != 0){
                cout << "/" << grid[i][j]._s;
            }
            cout << " ";
        }
        cout << nl;
    }
}   