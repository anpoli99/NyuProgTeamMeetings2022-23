#include <bits/stdc++.h>
using namespace std;

// There are two key observations to this problem:
// First let's try to solve the problem in the case where there is exactly one ocelot
//  O    Z    Z     Z     Z
//  Z -> O -> O  -> Z  -> Z
//  Z    O    Z     O     Z
// See the pattern? After removing an ocelot, we're simply counting in binary. So in
// the case with one ocelot, it will take 2^k steps, if k is the position of the ocelot.
//
// The second observation is that changing any ocelots below won't affect the ocelots
// above. So the answer is just the sum of the number of steps for each ocelot:
// This is the same as converting the string into a binary number. 
//
// An alternate way of getting to the same answer using the second observation, that's
// more formal:
// The number of steps for an ocelot in the k-th position is equal to:
// f(k) = sum[j=0...k - 1] f(j) + 1
// f(0) = 1 (trivially)
// f(1) = 1 + 1 = 2
// f(2) = 1 + (1 + 2) = 4
// etc.
// We can use induction to show that f(k) = 2^k

using ll = long long;
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'O'){
            ans += (1LL << (n - i - 1));
        }
    }
    cout << ans << endl;
}  