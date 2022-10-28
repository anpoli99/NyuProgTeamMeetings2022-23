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

// I'll use bitmasks to represent each set, and some bit manipulations to make most operations O(1)
// An unordered_set could pass, but it's closer to TLE
const int N = 100 + 5, M = 40 + 5;
ll neighbors[M];
ll cost[M];
//mask = set of vertices we haven't considered yet
//no_neighbors_mask = set of vertices to process at the end
ll solve(ll mask, ll no_neighbors_mask, ll current_set, int k){
    if(k < 0) return LINF;
    if(mask == 0){
        vl costs;
        ll tmp = no_neighbors_mask;
        while(tmp){
            int i = __builtin_ctzll(tmp);
            costs.push_back(cost[i]);
            tmp ^= (1ll << i);
        }
        sort(iter(costs));
        ll ans = 0;
        for(int i = 0; i < min(k, (int)costs.size()); i++){
            ans += costs[i];
        }
        return ans;
    }
    int next = __builtin_ctzll(mask);
    //don't add next vertex; need all of it's neighbors instead
    ll add = neighbors[next] & ~current_set; // don't add neighbors already in current_set
    if(add == 0){
        //this vertex has no more neighbors; handle at end
        return solve(mask ^ (1ll << next), no_neighbors_mask | (1ll << next), current_set, k);
    }
    ll tmp = solve((mask ^ (1ll << next)) & ~add, no_neighbors_mask, current_set | add, k - __builtin_popcountll(add));
    while(add){
        int next_neighbor = __builtin_ctzll(add);
        tmp += cost[next_neighbor];
        add ^= (1ll << next_neighbor);
    }
    //try addding next vertex
    ll ans = solve(mask ^ (1ll << next), no_neighbors_mask, current_set | (1ll << next), k - 1);
    ans += cost[next];
    ans = min(ans, LINF);
    return min(ans, tmp);
}
int main(){
    FASTIO
    PRECISION
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    ll current_set = 0;
    for(int i = 0; i < n; i++){
        int a,p,b,q;
        cin >> a >> p >> b >> q;
        --a; --b;
        if(a == b){
            ans += min(p, q);
            current_set |= (1ll << a);
            continue;
        }
        ans += max(p, q);
        neighbors[a] |= (1ll << b);
        neighbors[b] |= (1ll << a);
        if(p < q) {
            cost[a] += p - q;   
        }else{
            cost[b] += q - p;
        }
    }
    ll mask = (1ll << m) - 1;
    mask &= ~current_set;
    ans += solve(mask, 0, current_set, k - __builtin_popcountll(current_set));
    while(current_set){
        int i = __builtin_ctzll(current_set);
        ans += cost[i];
        current_set ^= (1ll << i);
    }
    if(ans >= INF) ans = -1; 
    cout << ans << nl;
}   