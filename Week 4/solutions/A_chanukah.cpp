#include <bits/stdc++.h>
using namespace std;

int chanukah(int k, int n){
    // There's also a formula: n(n + 1) / 2 + n
    // But constraints are small enough that we can just count the answer
    int candles = 0;
    for(int i = 1; i <= n; i++){
        candles += i + 1; // + 1 for the shammas candle
    }
    return candles;
}
int main(){
    int qr;
    cin >> qr;
    for(int t = 1; t <= qr; t++){
        int k, n;
        cin >> k >> n;
        cout << t << " " << chanukah(k, n) << endl;
    }
}