#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
ll dp[100];
ll fibonacci_dp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2);
}

int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    auto start = chrono::high_resolution_clock::now();
    cout << fibonacci(n) << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "It took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms to calculate that!" << endl;
   
    start = chrono::high_resolution_clock::now();
    fibonacci_dp(n);
    end = chrono::high_resolution_clock::now();
    cout << "It took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() <<  "ms with dp!" << endl;
}