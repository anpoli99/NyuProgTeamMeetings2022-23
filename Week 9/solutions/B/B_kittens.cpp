#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
int parent[N];
int main(){
    // This problem's input describes all the parent-child relationships we need to know
    // to find the path to the root from a given node. We can store the parent of each node
    // and then walk up the parent chain until we reach the root.
    int k;
    cin >> k;
    memset(parent, -1, sizeof(parent)); // we know we're at the root if parent[i] == -1
    string s;
    getline(cin, s); // read the '\n' from the previous line
    while(true){
        getline(cin, s);
        if(s == "-1") break;
        stringstream ss(s);
        int p;
        ss >> p;
        int child;
        while(ss >> child){
            parent[child] = p;
        }
    }
    while(k != -1){
        cout << k << ' ';
        k = parent[k];
    }
    cout << '\n';
}