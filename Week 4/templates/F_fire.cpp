#include <bits/stdc++.h>
using namespace std;

// Return the minimum distance to safety, or -1 if there is no safe place
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; // You may want to use these arrays in your implementation
int fire(int rows, int cols, vector<string>& grid){
    return -1; // This is a placeholder
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