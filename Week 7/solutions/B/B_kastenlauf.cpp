#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int x[N], y[N];
bool vis[N];
int main(){
    int qr;
    cin >> qr;
    while(qr--){
        int n;
        cin >> n;
        // You could also use Floyd-Warshall or Dijkstra's with 'n' this small
        // I think BFS is the easiest to implement, and it's also the fastest.
        // Usually using Dijkstra's when you could use a BFS won't actually
        // matter in practice, but there could be a case where Dijkstra's is too
        // slow. Either way, recognizing when you can just BFS is a useful skill.

        n += 2; // 0 = begin, n + 1 = end
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
            vis[i] = 0;
        }
        vis[0] = 1;
        queue<int> q({0});
        while(q.size()){
            int k = q.front();
            q.pop();
            for(int i = 0; i < n; i++){
                if(vis[i]) continue;
                // One bottle every 50 meters; 20 bottles in a box
                // They can travel 1000 meters, so if the next store is 
                // at least that close, they can get there
                int dx = abs(x[i] - x[k]);
                int dy = abs(y[i] - y[k]);
                if(dx + dy <= 1000){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        cout << (vis[n - 1] ? "happy" : "sad") << '\n';
    }
}   