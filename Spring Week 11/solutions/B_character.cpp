#include <bits/stdc++.h>
using namespace std;

// There are 2^N possible subsets of a set of size N.
// N of those have a size of 1 element.
// 1 of those is empty.
// So our answer is 2^n - n - 1

int main(){
    int n;
    cin >> n;
    cout << (1 << n) - n - 1 << endl; // Left shift = fast power of 2
}