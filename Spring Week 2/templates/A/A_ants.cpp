#include <bits/stdc++.h>
using namespace std;

// Parameters:
// Input N,L as described in the problem statement
// positions: vector of length N containing the positions of the ants
// Output: pair<int,int> as described in the problem statement
pair<int,int> ants(int N, int L, vector<int> positions) {
    pair<int,int> ans;

    return ans;
}
int main(){
    int Q;
    cin >> Q;
    while(Q-- > 0){
        int N,L;    
        cin >> L >> N;
        vector<int> positions(N);
        for(int i = 0; i < N; i++){
            cin >> positions[i];
        }
        pair<int,int> ans = ants(N,L,positions);
        cout << ans.first << " " << ans.second << endl;
    }
}