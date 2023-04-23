#include <bits/stdc++.h>
using namespace std;

// This is actually a topological sort problem; I'll demonstrate a DFS approach.
// We can treat each dependency (x requires y) as an edge from y to x, so after
// we recompile all the files x depends on, we can recompile x.
// (I actually meant to link a problem that was the same idea of build dependencies,
// but asked you to determine if there was a cycle in the dependency graph, but chose
// the wrong one, oops)

vector<int> ans;
const int N = 1e5 + 5;
string name[N];
vector<int> adj[N];
bool vis[N];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    ans.push_back(u); // This is the DFS topological sort
                      // We know that u will come after all files that depend on 'u' in
                      // 'ans', so we can reverse 'ans' when we're done to get the correct
                      // order.
}
int main(){
    int n;
    cin >> n;
    map<string, int> id; // since we don't know which order we'll see a file name,
                        // using a map let's us assign an id on demand
    for(int i = 0; i < n; i++){
        string cur;
        cin >> cur;
        cur.pop_back(); // remove the colon
        if(!id.count(cur)) { // id does not contain cur
            int idx = id.size();
            id[cur] = idx;
            name[idx] = cur; 
        }
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        while(ss >> s){ // read in the rest of the line
            if(!id.count(s)) { // id does not contain s
                int idx = id.size();
                id[s] = idx;
                name[idx] = s;
            }
            adj[id[s]].push_back(id[cur]); // add an edge from s to cur
        }
    }
    string root;
    cin >> root;
    dfs(id[root]);
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << name[i] << endl;
}  