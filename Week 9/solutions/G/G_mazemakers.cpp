#include <bits/stdc++.h>
using namespace std;

// An observation we can make that might simplify the problem:
// mazes are trees! We can just about check if the maze is a tree
// and call it done. The only thing we need to add is to check
// if there's No Solution first. This is true if the exits are
// not in the same connected component.

const int N = 50 + 5;
int root[N * N];
int find(int x){
    if(root[x] == -1) return x;
    return root[x] = find(root[x]);
}
int idx[N][N]; // Used to keep track of what component each cell is in
int main(){
    int r,c;
    while(cin >> r >> c && r){
        vector<string> s(r);
        for(int i = 0; i < r; i++) cin >> s[i];

        // initialize union-find
        int ptr = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                idx[i][j] = ++ptr;
                root[ptr] = -1;
            }
        }


        int edge_ct = 0; // If there aren't n - 1 edges, then it's not a tree
        vector<pair<int,int>> exits; // We'll check that these are in the same component
        int components = r * c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int hexv = s[i][j] - '0';
                if(s[i][j] > '9' || s[i][j] < '0'){
                    hexv = s[i][j] - 'A' + 10;
                }
                auto process_adjacent = [&](int x, int y){
                    if(x < 0 || x >= r || y < 0 || y >= c) {
                        exits.push_back({i, j});
                    }else{
                        int u = find(idx[i][j]);
                        int v = find(idx[x][y]);
                        if(u != v){
                            root[u] = v;
                            components--;
                        }
                        edge_ct++;
                    }
                }; // helper function to avoid repeating code

                if(!(hexv & 8)){
                    //go up
                    process_adjacent(i - 1, j);
                }
                if(!(hexv & 4)){
                    //go right
                    process_adjacent(i, j + 1);
                }
                if(!(hexv & 2)){
                    //go down
                    process_adjacent(i + 1, j);
                }
                if(!(hexv & 1)){
                    //go left
                    process_adjacent(i, j - 1);
                }
            }
        }
        // is a tree if and only if n - 1 edges, no cycles
        edge_ct /= 2; // we counted each edge twice
        bool exits_in_same_component = find(idx[exits[0].first][exits[0].second]) == find(idx[exits[1].first][exits[1].second]);
        if(!exits_in_same_component){
            cout << "NO SOLUTION\n";
        }else if(components != 1){
            cout << "UNREACHABLE CELL\n";
        }else if(edge_ct != r * c - 1){
            cout << "MULTIPLE PATHS\n";
        }else{
            cout << "MAZE OK\n";
        }
        
    }
}   