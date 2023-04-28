#include<bits/stdc++.h>
using namespace std;

/*
The hardest of the non-FFT problems;

The first step is to observe that since we're not
getting any feedback, the solution is going to be
to select some set of problems and just try to solve
those.

Clearly if p[i] > p[j], it's always better to take
problem i over problem j. So let's sort the problems
and take the 'm' best ones. 

What's our probability of passing if we take exactly
m problems? This is a DP question: The probability of 
getting 'x' points is equal to the probability of
getting x - 1 points (without problem m) times p[i]    // <- Getting the problem right
+ the probability of x + 1 points times (1 - p[m]).   // <- Getting the problem wrong


This is an O(n^2) DP, which is fast enough.
*/


const int N = 5e3 + 5;
double p[N];
double dp[2 * N], new_dp[2 * N];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n, greater<double>());
    // Trick for indexing negative indices:
    // add a constant offset to all indices
    // just to make sure they're positive.
    const int off = N;
    dp[off] = 1; // Probability of getting 0 points
                // with zero problems is 1. 
    double best = 0;
    for(int i = 0; i < n; i++){
        for(int j = -i; j <= i; j++){
            new_dp[j + off + 1] += dp[j + off] * p[i];
            new_dp[j + off - 1] += dp[j + off] * (1 - p[i]);
        }
        // Unrolling the DP means we can use these very fast
        // C functions to manipulate memory.
        // (This probably isn't necessary for AC though)
        memcpy(dp, new_dp, sizeof(dp));
        memset(new_dp, 0, sizeof(new_dp));
        double sum = 0;
        for(int j = k; j <= i + 1; j++){
            // If the final score is in this range, we pass
            sum += dp[j + off];
        }
        best = max(best, sum);
    }
    cout << fixed << setprecision(10); // Make sure output has enough precision
    cout << best << endl;
}   