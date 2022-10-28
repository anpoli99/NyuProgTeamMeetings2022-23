
#include <bits/stdc++.h>
using namespace std;

//input format: related has a list of indices adjacent to each given index
//return the integer that has the highest horror index
int horrorlist(int n, vector<int>& horror_movies, vector<vector<int>>& related){
    vector<int> horror_index(n, INT_MAX);
    queue<int> q;
    for(int i : horror_movies){
        horror_index[i] = 0;
        q.push(i);
    }   
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : related[u]){
            if(horror_index[v] == INT_MAX){
                horror_index[v] = horror_index[u] + 1;
                q.push(v);
            }
        }
    }
    int best = -1, best_index = -1;
    for(int i = 0; i < n; i++){
        if(horror_index[i] > best){
            best = horror_index[i];
            best_index = i;
        }
    }
    return best_index;
}
int main(){
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> horror_movies(h);
    for(int i = 0; i < h; i++){
        cin >> horror_movies[i];
    }
    vector<vector<int>> related(n);
    for(int i = 0; i < l; i++){
        int u, v;
        cin >> u >> v;
        related[u].push_back(v);
        related[v].push_back(u);
    }
    cout << horrorlist(n, horror_movies, related) << endl;
}