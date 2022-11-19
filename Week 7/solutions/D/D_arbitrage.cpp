#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;
double dist[N][N];
int main(){
    int n;
    while(cin >> n){
        if(!n) break;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            mp[s] = i;
            for(int j = 0; j < n; j++){
                dist[i][j] = 0;
            }
            dist[i][i] = 1;
        }
        // We can modify Floyd-Warshall to be converting between currencies
        // by multiplying the exchange rate instead of adding. Then we want
        // to look for a cycle where the product of the exchange rates is
        // greater than 1. This is analogous to looking for a negative cycle
        // in the shortest path problem.

        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            string a, b, c;
            cin >> a >> b >> c;
            for(char& x : c) if(x == ':') x = ' ';
            stringstream ss(c);
            int x,y;
            ss >> x >> y;
            dist[mp[a]][mp[b]] = y / double(x);
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(dist[i][i] > 1){
                ok = false;
                break;
            }
        }
        cout << (ok ? "Ok\n" : "Arbitrage\n");
    }

}   