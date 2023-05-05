#include "bits/stdc++.h"
using namespace std;
 
// One way to think of this problem is that the numbers
// form a "functional" graph (each number points to another
// number). Every path in this graph ends in some cycle, and 
// if that cycle contains one, then it is a "happy" number. 

// The numbers are small enough that we can check each cycle
// independently
// (10000 numbers, so a linear search is at most 10000 * 10000
// steps;
// Except we know it won't take that long, because 
// 9999 -> 81 * 4 = 324, and 9999 leads to the highest number
// So really it's at most 10000 * 324 steps, which is fast enough
// with a fairly slow implementation)

bool is_happy(int n){
    set<int> seen;
    while(n != 1){
        if(seen.count(n)){
            return false;
        }
        seen.insert(n);
        int next = 0;
        while(n){
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        n = next;
    }
    return true;
}
bool is_prime(int n){
    if(n == 1) return false; // Edge case; 1 is not prime (problem statement)
    // A sqrt(n) prime check is fast enough for this problem
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int qrys;
    cin >> qrys;
    while(qrys--){
        int tc, n;
        cin >> tc >> n;
        cout << tc << " " << n << " ";
        if(is_happy(n) && is_prime(n)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}