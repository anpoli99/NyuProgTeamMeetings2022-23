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
int letter_ct[256]; // use ascii value
string s[N + 5];
// if we don't use masks, we need to prune the search
// to compensate for the loop over all letters in each word
int search(int idx, int count){
    if(count == 26){
        return (1 << (idx + 1)); // all remaining subsets are valid
    }
    if(idx == -1){
        return count == 26;
    }
    for(char c : s[idx]){
        if(letter_ct[c] == 0){
            count++;
        }
        letter_ct[c]++;
    }
    int ans = search(idx - 1, count);
    for(char c : s[idx]){
        letter_ct[c]--;
        if(letter_ct[c] == 0){
            count--;
        }
    }
    if(ans == 0) return 0; // if couldn't find every letter w/ this word, 
                            // we definitely can't without it
    return ans + search(idx - 1, count);
}
int main(){
    FASTIO
    PRECISION
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << search(n - 1, 0) << nl;
}   