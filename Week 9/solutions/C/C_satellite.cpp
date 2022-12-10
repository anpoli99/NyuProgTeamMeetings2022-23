#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int x[N], y[N], r[N];
double dist[N];
bool visited[N];
int main(){
    // The structure being described is example a minimum spanning tree.
    // The length of titanium rod needed between satellite dishes (i,j) is their
    // distance minus the radius of each dish.
    // Since N is small we can use Prim's algorithm and not worry about
    // any other data structures.
    int n;
    cin >> n;
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> r[i];
        // 0 is the root; initialize dist[i] using index 0
        double dx = x[i] - x[0];
        double dy = y[i] - y[0];
        double cost = sqrt(dx * dx + dy * dy) - r[i] - r[0];
        dist[i] = max(double(0), cost);
    }
    double ans = 0;
    for(int i = 0; i < n - 1; i++){
        double best_dist = 1e9;
        int next = -1;
        for(int j = 1; j < n; j++){ // 0 is the root
            if(!visited[j] && dist[j] < best_dist){
                best_dist = dist[j];
                next = j;
            }
        }
        visited[next] = true;
        ans += best_dist;
        for(int j = 0; j < n; j++){
            if(!visited[j]){
                double dx = x[j] - x[next];
                double dy = y[j] - y[next];
                double cost = sqrt(dx * dx + dy * dy) - r[j] - r[next];
                dist[j] = min(dist[j], max(double(0), cost));
            }
        }
    }
    cout << fixed << setprecision(10) << ans << '\n'; 
    //In C++ use setprecision(10) to avoid rounding errors
}