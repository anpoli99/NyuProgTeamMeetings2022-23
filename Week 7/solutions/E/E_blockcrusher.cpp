#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int N = 100 + 5;
char grid[N][N];
struct ctnr{ // We can use our own container class for priority_queue to 
    //store the distance + any other information we need
    int x,y; // x = row, y = col
    int dist;
    bool operator<(const ctnr& other) const{
        return dist > other.dist; // reversed for priority queue; smaller dist first
    }
};
pair<int, int> prv[N][N];
bool fracture[N][N];
int best_dist[N][N];
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1}; // useful when we want to iterate over all 8 directions
int main(){
    int r,c;
    bool first = true;
    while(cin >> r >> c){
        if(!r) break;
        if(!first) cout << '\n';
        first = false;
        
        // The main idea here is to use Dijkastra's algorithm to find the shortest path from
        // the top row to the bottom. In  this sense, all elements in the top row are considered
        // to be the sources.
        priority_queue<ctnr> pq;
        for(int i = 0; i < r; i++){
            cin >> grid[i];
            for(int j = 0; j < c; j++){
                fracture[i][j] = false;
                if(i != 0){
                    best_dist[i][j] = INF;
                }else{
                    best_dist[i][j] = grid[i][j] - '0';
                    pq.push({i,j,best_dist[i][j]});
                }
            }
        }

        pair<int, int> ans;
        while(pq.size()){
            ctnr cur = pq.top();
            pq.pop();
            if(best_dist[cur.x][cur.y] < cur.dist) continue;
            if(cur.x == r - 1){
                ans = {cur.x, cur.y};
                break;
            }
            for(int i = 0; i < 8; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                int new_dist = cur.dist + grid[nx][ny] - '0';
                if(new_dist < best_dist[nx][ny]){
                    best_dist[nx][ny] = new_dist;
                    prv[nx][ny] = {cur.x, cur.y};
                    pq.push({nx, ny, new_dist});
                }
            }
        }
        fracture[ans.first][ans.second] = true; // recreate path to find fracture points
        while(ans.first != 0){
            ans = prv[ans.first][ans.second];
            fracture[ans.first][ans.second] = true;
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(fracture[i][j]){
                    cout << ' ';
                }else{
                    cout << grid[i][j];
                }
            }
            cout << '\n';
        }
        
    }
}   