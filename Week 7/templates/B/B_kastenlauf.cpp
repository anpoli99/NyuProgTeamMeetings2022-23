#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
// Input format: x[0],y[0] = start, x[n - 1],y[n - 1] = end
bool kastenlauf(int n, vector<int> x, vector<int> y){
    // Your code here
}
int main(){
    int qr;
    cin >> qr;
    while(qr--){
        int n;
        cin >> n;
        n += 2; // 0 = begin, n + 1 = end
        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        cout << (kastenlauf(n,x,y) ? "happy" : "sad") << '\n';
    }
}   