#include <bits/stdc++.h>
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



/*
I've changed the problem to be simpler than the original from IOI
In that one, you'd use a similar idea, but the implementation becomes a bit more complicated
*/

/*
Input: On first line, K, the number of lamps, N, the maximum number of buttons pressed
       On the next line, a binary string of length K, where 1 means the lamp is initially on, and 0 means it's off 
*/
/*
Output: "POSSIBLE" or "IMPOSSIBLE", depending on whether all K lamps can be turned off
*/

const int K = 100 + 5;
bool original_state[K];
bool current_state[K];

int add[] = {2,2,3};
int initial_value[] = {1,2,1}; //I'm representing each button with these parameters, just for convenience
void toggle_switch(int i, int k){
    int v = initial_value[i];
    while(v <= k){
        current_state[v] ^= 1;
        v += add[i];
    }
}
int main() {
    FASTIO
    PRECISION
    int k, n;
    cin >> k >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= k; i++){
        original_state[i] = s[i - 1] == '1';
    }
    for(int i = 0; i < (1 << 3); i++){
        //Careful! We can't hit more buttons than N
        //__builtin_popcount(i) returns the number of 1s in the binary representation of i
        if(__builtin_popcount(i) > n) continue;

        memset(current_state, 0, sizeof(current_state)); // fast way to set all elements to 0
        for(int j = 0; j < 3; j++){
            //equivalent to if(i & (1 << j)) 
            //or            if(((i >> j) & 1) == 1) (C++ casts any non-zero value to true)
            if((i >> j) & 1){
                toggle_switch(j, k);
            }
        }
        // Now we can check if that turns all the lamps off
        bool all_match = true;
        for(int j = 1; j <= k; j++){
            if(original_state[j] != current_state[j]){
                all_match = false;
                break;
            }
        }
        if(all_match){
            cout << "POSSIBLE\n";
            return 0;
        }   
    }
    cout << "IMPOSSIBLE\n";
}   