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


// See: https://open.kattis.com/problems/draughts
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1}; // useful to keep moves in array, so we don't have out each one individually
string s[15]; // the input is given as a string; i'll just leave it like that 
inline int in_bounds(int x, int y){ 
    return (x >= 0 && x < 10 && y >= 0 && y < 10);
}
int search(int x, int y){
    int ans = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i]; //adjacent square
        int nx2 = x + 2 * dx[i], ny2 = y + 2 * dy[i]; //destination square
        if(in_bounds(nx2,ny2) && s[nx][ny] == 'B' && s[nx2][ny2] == '#'){
            s[nx][ny] = '#';  // prevent us from taking the same piece twice
            ans = max(ans, 1 + search(nx2, ny2));
            s[nx][ny] = 'B';
        }
    }
    return ans;
}
int main(){
    FASTIO
    PRECISION
    int n;
    cin >> n;
    while(n--){
        for(int i = 0; i < 10; i++){
            cin >> s[i];
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(s[i][j] == 'W'){
                    s[i][j] = '#';
                    ans = max(ans, search(i, j));
                    s[i][j] = 'W';
                }
            }
        }
        cout << ans << nl;
    }
}   