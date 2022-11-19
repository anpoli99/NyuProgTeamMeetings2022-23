#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int N = 500 + 5;
int dist[N][N];
int path_recov[N][N];
string name[N];
int main(){
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++){
        cin >> name[i];
        mp[name[i]] = i;
        for(int j = 0; j < n; j++){
            dist[i][j] = INF;
        }
    }
    string s;
    getline(cin, s); // clear previous line
    for(int j = 0; j < n; j++){
        int k;
        cin >> s >> k;
        int i = mp[s];
        getline(cin, s); // clear previous line
        for(int t = 0; t < k; t++){
            getline(cin, s);
            stringstream ss(s);
            string x;
            ss >> x;
            while(ss >> x){
                if(x.back() == ',') x.pop_back();
                dist[i][mp[x]] = 1;
                path_recov[i][mp[x]] = mp[x];
            }
        }
    }
    // The main idea here is we'll try to use path recovery to build a cycle
    // If we only care about finding the length of the cycle, this is the
    // same as the distance from a vertex to itself in Floyd-Warshall. In normal
    // Floyd-Warshall the distance from a vertex to itself is 0, but here we initialize
    // it to INF. After finding the shortest cycle, we can use path recovery to
    // build the cycle.
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path_recov[i][j] = path_recov[i][k];
                }
            }
        }
    }
    pair<int, int> best = {INF, -1};
    for(int i = 0; i < n; i++){
        if(dist[i][i] != INF){
            best = min(best, {dist[i][i], i});
        }
    }
    if(best.first == INF){
        // no cycles here
        cout << "SHIP IT" << '\n';
    }else{
        // found an optimal cycle; let's step through it one vertex at a time
        // and print the names of the vertices
        int i = best.second;
        do{
            cout << name[i] << " ";
            i = path_recov[i][best.second];
        } while(i != best.second);
        cout << '\n';
    }

}   