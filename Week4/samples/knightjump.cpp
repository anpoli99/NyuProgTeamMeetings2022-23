#include <bits/stdc++.h>
using namespace std;

// open.kattis.com/problems/knightjump
// This is an implicit graph; for a graph with defined edges, the idea is very similar
// We'd want to still initialize a distance array to infinity and use a queue
// The only difference is we'd want to iterate over all of a vertex's neighbors instead of
// all of the possible moves.

int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    pair<int,int> start;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'K'){
                start = {i,j};
                dist[i][j] = 0;
            }
        }
    }
    // bfs starts here
    queue<pair<int,int>> q;
    q.push(start);
    while(q.size()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){ // this lets us try all neighbors
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // out of bounds
            if (s[nx][ny] == '#') continue; // blocked
            if (dist[nx][ny] != INT_MAX) continue; // already visited
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
    if(dist[0][0] == INT_MAX) dist[0][0] = -1;
    cout << dist[0][0] << endl;
}