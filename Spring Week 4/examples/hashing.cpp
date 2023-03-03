#include <bits/stdc++.h>
using namespace std;

// We'll be using this rolling hash struct to solve the problem
// https://kattis.com/problems/hashing. It's written to be generic
// so you can copy and paste it into your own code, whenever you 
// need a rolling hash.

using ll = long long;

const int mod = 1e9 + 87; // A prime number
const int p1 = 131, p2 = 499; // Two different primes; greater than size of alphabet (128 for strings)
const int N = 1e6 + 5; // Longer than the longest string

int modpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;

}

ll power1[N], power2[N];
ll invp1[N], invp2[N]; 
// Precomputing hashes is a lot faster; save log(n) time every time we use it.
bool pre_computed = false;
void precompute(){
    power1[0] = power2[0] = 1;
    for(int i = 1; i < N; i++){
        power1[i] = (power1[i - 1] * p1) % mod;
        power2[i] = (power2[i - 1] * p2) % mod;
    }
    invp1[N - 1] = modpow(power1[N - 1], mod - 2); // Modular inverse formula: x^(-1) == x^(m - 2) mod m
    invp2[N - 1] = modpow(power2[N - 1], mod - 2); // (Iff m is prime)
    for(int i = N - 2; i >= 0; i--){ // Compute the largest first, then just multiply by p1/p2 to get lower powers
        invp1[i] = (invp1[i + 1] * p1) % mod;
        invp2[i] = (invp2[i + 1] * p2) % mod;
    }
    pre_computed = true;
 }
 struct rolling_hash{
    string s;
    vector<ll> hash1, hash2;
    rolling_hash(string s): s(s){
        if(!pre_computed) precompute();
        int n = s.size();
        hash1.resize(n + 1);
        hash2.resize(n + 1);
        for(int i = 0; i < n; i++){
            hash1[i + 1] = (hash1[i] + (s[i] - 'a' + 1) * power1[i]) % mod;
            hash2[i + 1] = (hash2[i] + (s[i] - 'a' + 1) * power2[i]) % mod;
        }
    }
    ll hash(int l, int r){ // Hash of the substring [l, r] (0-indexed)
        ll r1 = (hash1[r + 1] - hash1[l] + mod) % mod;
        ll r2 = (hash2[r + 1] - hash2[l] + mod) % mod;
        r1 = (r1 * invp1[l]) % mod;
        r2 = (r2 * invp2[l]) % mod;
        return (r1 << 32) | r2;
    }
 };

 int main(){
    // Solving this problem becomes trivial with our rolling hash struct
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    rolling_hash h(s);
    int qr;
    cin >> qr;
    while(qr-- > 0){
        int l, r;
        cin >> l >> r;
        // r not inclusive
        --r;
        cout << h.hash(l,r) << '\n';
    }
 }