#include <bits/stdc++.h>
using namespace std;

//input format: related[i] is a list of all indices related to i
//return the integer that has the highest horror index
int horrorlist(int n, vector<int>& horror_movies, vector<vector<int>>& related){
    // Your code goes here
    return -1; // This is a placeholder
}
int main(){
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> horror_movies(h);
    for(int i = 0; i < h; i++){
        cin >> horror_movies[i];
    }
    vector<vector<int>> edges(n);
    for(int i = 0; i < l; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << horrorlist(n, horror_movies, edges) << endl;
}