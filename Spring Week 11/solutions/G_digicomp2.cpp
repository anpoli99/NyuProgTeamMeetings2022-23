#include <bits/stdc++.h>
using namespace std;

// Definitely the hardest problem of the contest; 
// We need to keep track of how many times the ball hits
// each peg to determine the final parity. So this is a 
// topological sort problem, but we need to be careful
// with the order of the edges.

using ll = long long;
const int N = 5e5 + 5;
bool starting_left[N];
int left_side[N], right_side[N];
ll a[N];
int parent[N];
int main(){
    ll k;
    cin >> k;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if(c == 'L') starting_left[i] = true;
        else starting_left[i] = false;
        cin >> left_side[i] >> right_side[i];
        parent[left_side[i]]++;
        parent[right_side[i]]++;
    }
    a[1] = k;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(parent[i] == 0) q.push(i); // Edge case! There can still be "dead" parents besides 1
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(a[u] % 2 == 0){
            a[left_side[u]] += a[u] / 2;
            a[right_side[u]] += a[u] / 2;
        }else{
            if(starting_left[u]){
                a[left_side[u]] += a[u] / 2 + 1;
                a[right_side[u]] += a[u] / 2;
            }else{
                a[left_side[u]] += a[u] / 2;
                a[right_side[u]] += a[u] / 2 + 1;
            }
        }
        parent[left_side[u]]--;
        if(parent[left_side[u]] == 0) q.push(left_side[u]); // Edge case! This must go before the next line, in case left == right
        parent[right_side[u]]--;
        if(parent[right_side[u]] == 0) q.push(right_side[u]);
    }
    for(int i = 1; i <= n; i++){
        if((a[i] & 1) ^ starting_left[i]){
            cout << "L";
        }else{
            cout << "R";
        }
    }
    cout << endl;


}
