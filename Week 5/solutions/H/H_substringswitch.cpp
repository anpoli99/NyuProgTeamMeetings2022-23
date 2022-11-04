#include <bits/stdc++.h>
using namespace std;

string substringswitcheroo(string& a, string& b){
    // Here's an example of where hashing can be useful:
    // We can hash the number of times each character appears in a substring
    // of a, and then check if the same substring of b has the same hash.
    const int p = 1319; // any prime number > N is fine
                        // if it's less than N we could get collisions
    const int m1 = 1e9 + 7, m2 = 1e9 + 9; // two large primes

    vector<long long> v1(256), v2(256);
    v1[0] = v2[0] = 1;
    for(int i = 1; i < 256; i++){
        v1[i] = (v1[i - 1] * p) % m1;
        v2[i] = (v2[i - 1] * p) % m2;
    }
    int n = a.size();
    unordered_set<long long> hashes;
    for(int i = 0; i < n; i++){
        long long h1 = 0, h2 = 0;
        for(int j = i; j < n; j++){
            h1 = (h1 + v1[b[j]]) % m1;
            h2 = (h2 + v2[b[j]]) % m2;
            hashes.insert((h1 << 32) + h2);
        }
    }
    int idx = 0, len = 0;
    for(int i = 0; i < n; i++){
        long long h1 = 0, h2 = 0;
        for(int j = i; j < n; j++){
            h1 = (h1 + v1[a[j]]) % m1;
            h2 = (h2 + v2[a[j]]) % m2;
            if(hashes.count((h1 << 32) + h2)){
                if(j - i + 1 > len){
                    len = j - i + 1;
                    idx = i;
                }
            }
        }
    }
    if(len == 0) return "NONE";
    return a.substr(idx, len);
}

int main(){
    int qr;
    cin >> qr;
    while(qr--){
        string a, b;
        cin >> a >> b;
        cout << substringswitcheroo(a, b) << '\n';
    }
}