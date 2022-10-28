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

const int N = 25;
int keys[N + 5];
int val[(1 << N) + 5];
int main(){
    FASTIO
    PRECISION
    int n;
    cin >> n;
    int final_key = (1 << 26) - 1; // every letter in the alphabet
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(char c : s){
            c -= 'a';
            keys[i] |= (1 << c);
        }
    }
    int ans = 0;
    for(int i = 1; i < (1 << n); i++){
        int k = __builtin_ctz(i); // bit hack: index of the least significant bit
         /*
         equiv to:
            int k = 0;
            while(((i >> k) & 1) == 0) k++;
         */
        
        val[i] = val[i ^ (1 << k)] | keys[k]; // i ^ (1 << k) < i
        if(val[i] == final_key){
            ans++;
        }
    }
    cout << ans << nl;
}   