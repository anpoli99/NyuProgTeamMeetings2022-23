#include <bits/stdc++.h>
using namespace std;

// Return the minimum distance to safety, or -1 if there is no safe place
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int fire(int rows, int cols, vector<string>& grid){
    // We can do two bfs's, one from the person and one from each fire source
    // An endpoint is valid iff the person can reach it before the fire does
    vector<vector<int>> dist_to_person(rows, vector<int>(cols, INT_MAX));
    vector<vector<int>> dist_to_fire(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> person_q, fire_q;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == '@'){
                person_q.push({i, j});
                dist_to_person[i][j] = 0;
            }else if(grid[i][j] == '*'){
                fire_q.push({i, j});
                dist_to_fire[i][j] = 0;
            }
        }
    }
    // Note that a better implementation could use a function to do the bfs, to avoid repeating code
    // For the sake of clarity, I've kept them separate
    while(person_q.size()){
        pair<int,int> p = person_q.front();
        person_q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            if(grid[nx][ny] == '#') continue;
            if(dist_to_person[nx][ny] != INT_MAX) continue;
            dist_to_person[nx][ny] = dist_to_person[x][y] + 1;
            person_q.push({nx, ny});
        }
    }
    while(fire_q.size()){
        pair<int,int> p = fire_q.front();
        fire_q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            if(grid[nx][ny] == '#') continue;
            if(dist_to_fire[nx][ny] != INT_MAX) continue;
            dist_to_fire[nx][ny] = dist_to_fire[x][y] + 1;
            fire_q.push({nx, ny});
        }
    }
    int ans = INT_MAX;
    // Check all exits
    for(int i = 0; i < rows; i++){
        if(dist_to_fire[i][0] > dist_to_person[i][0]){
            ans = min(ans, dist_to_person[i][0]);
        }
        if(dist_to_fire[i][cols - 1] > dist_to_person[i][cols - 1]){
            ans = min(ans, dist_to_person[i][cols-1]);
        }
    }
    for(int i = 0; i < cols; i++){
        if(dist_to_fire[0][i] > dist_to_person[0][i]){
            ans = min(ans, dist_to_person[0][i]);
        }
        if(dist_to_fire[rows - 1][i] > dist_to_person[rows - 1][i]){
            ans = min(ans, dist_to_person[rows-1][i]);
        }
    }
    if(ans == INT_MAX) return -1;
    return ans + 1;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int rows, cols;
        cin >> cols >> rows;
        vector<string> grid(rows);
        for(int j = 0; j < rows; j++){
            cin >> grid[j];
        }
        int ans = fire(rows, cols, grid);
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
}