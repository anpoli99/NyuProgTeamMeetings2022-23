#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9 + 5;

int main(){
    // There are a lot of approaches to this problem; the constraints are small enough
    // that you can iterate over all the palindromes to find the smallest. But it becomes
    // simpler to write if we just precompute them, and use a set to find the smallest
    set<int> all_palindromes;
    for(int i = 100; i <= 999; i++){ // No leading zeroes; start at 100
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        s += t;
        all_palindromes.insert(stoi(s));
    }
    int qr;
    cin >> qr;
    while(qr--){
        int k;
        cin >> k;
        auto it = all_palindromes.upper_bound(k);
        int best = INF, best_palindrome = -1;
        if(it != all_palindromes.end()){ // Check palindrome greater than k
            best = *it - k;
            best_palindrome = *it;
        }
        if(it != all_palindromes.begin()){ // Check palindrome less than/equal to k
            it--;
            if(k - *it <= best){
                best = k - *it;
                best_palindrome = *it;
            }
        }
        cout << best_palindrome << '\n';
    }
}