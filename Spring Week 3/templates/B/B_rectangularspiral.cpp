#include <bits/stdc++.h>
using namespace std;

// Input format: x,y = queried point
// Return: vector of ints of the shortest path from (0,0) to (x,y)
//         return empty vector if no path exists
vector<int> solve(int x, int y){
    return {}; // This is a placeholder
}

int main(){
    int qr;
    cin >> qr;
    for(int tc = 1; tc <= qr; tc++){
        int x,y;
        cin >> tc >> x >> y;
        cout << tc << " ";
        vector<int> ans = solve(x,y);
        if(!ans.size()){
            cout << "NO PATH\n";
        }else{
            cout << ans.size() << " ";
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}