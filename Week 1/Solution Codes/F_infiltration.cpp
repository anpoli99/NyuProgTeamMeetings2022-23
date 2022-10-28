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

const int C = 12;
string common[] = {"be", "our", "rum", "will", "dead", "hook", "ship",
                    "blood", "sable", "avenge", "parrot", "captain"};
const int N = 100 + 5;
int pattern[C]; // representation of each word's letter order (i.e. "will" = "abcc", "hook" = "abbc", etc.)
set<string> matches[C]; //set of strings that match the pattern of originalinal word
string current_match[C]; //current match for each word when searching
int all_letters_mask = 0;
int letter_map[256 + 5];
int ans[256 + 5];
int res = 0;
                // key tells us which words in common have a matching
void solve(int idx, int key){
    if(idx == C){
        int letters_mask = 0;
        int inverse_mask = 0;
        bool already_found = true;
        for(int i = 0; i < C; i++){
            if(key & (1 << i)){
                for(int j = 0; j < common[i].size(); j++){
                    letters_mask |= (1 << (current_match[i][j] - 'a'));
                    inverse_mask |= (1 << (common[i][j] - 'a'));
                    letter_map[current_match[i][j]] = common[i][j];
                    already_found &= letter_map[current_match[i][j]] == ans[current_match[i][j]];
                }
            }
        }
        // not all letters used                                        wrong # of letters on input/output of mappings
        if(letters_mask != all_letters_mask || already_found || __builtin_popcount(inverse_mask) != __builtin_popcount(letters_mask)) {
            return;
        }
        for(int i = 0; i < C; i++){
            if(key & (1 << i)){
                for(int j = 0; j < common[i].size(); j++){
                    // contradiction in mapping
                    if(letter_map[current_match[i][j]] != common[i][j]) return;
                }
            }
        }

        // found a solution
        for(int i = 'a'; i <= 'z'; i++){
            ans[i] = letter_map[i];
        }
        res++;
        return;
    }
    // try not matching this word
    solve(idx + 1, key);
    if(res > 1) return;
    key |= (1 << idx);
    for(string s : matches[idx]){
        current_match[idx] = s;
        solve(idx + 1, key);
        if(res > 1) return;
    }
}
string original[N];
int main(){
    FASTIO
    PRECISION
    for(int i = 0; i < C; i++){
        umap<char, int> u;
        for(char c : common[i]){
            if(!u[c]) u[c] = u.size();
            pattern[i] *= 10;
            pattern[i] += u[c];
        }
    }
    string s;
    getline(cin, s);
    stringstream ss(s);
    int n = 0;
    while(ss >> s){
        original[n++] = s;
        umap<char, int> u;
        int cur = 0;
        for(char c : s){
            if(!u[c]) u[c] = u.size();
            cur = cur * 10 + u[c];
            all_letters_mask |= (1 << (c - 'a'));
        }
        if(s.size() < 8) for(int i = 0; i < C; i++){
            if(cur == pattern[i]){
                matches[i].insert(s);
            }
        }
    }
    solve(0, 0);
    if(res == 1){
        for(int i = 0; i < n; i++){
            for(char c : original[i]) cout << char(ans[c]);
            cout << ' ';
        }
        cout << nl;
    }else{
        cout << "Impossible" << nl;
    }
}   