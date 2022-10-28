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

const int N = 256 + 5;
int ct[N];
int main(){
    FASTIO
    PRECISION
    string p;
    cin >> p;
    int n;
    cin >> n;
    vector<string> cand;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        ct[s[0]]++;
        if(s[0] != p.back()) continue;
        cand.push_back(s);
    }
    ct[p.back()]--;
    string ans = "?";
    for(string s : cand){
        if(ct[s.back()] == 0){
            ans = s + "!";
            break;
        }else if(ans == "?"){
            ans = s;
        }
    }
    cout << ans << nl;
}   