#include <bits/stdc++.h>
using namespace std;

// The structure of these 'ordinals' means that
// Ord(k) is equal to "{Ord(0), Ord(1), ... Ord(k-1)}"

// This leads to a recursive construction of these ordinal

void ordinal(int k){
    if(k == 0) cout << "{}"
    else {
        cout << "{";
        for(int i = 0; i < k; i++){
            ordinal(i);
            if(i != k - 1) cout << ",";
        }
        cout << "}";
    }
}

int main(){
}