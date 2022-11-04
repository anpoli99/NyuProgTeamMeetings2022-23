#include <bits/stdc++.h>
using namespace std;

int r2(int r1, int s){
    int diff = s - r1;
    return s + diff;
}

int main(){
    int r1, s;
    cin >> r1 >> s;
    cout << r2(r1, s) << '\n';
}