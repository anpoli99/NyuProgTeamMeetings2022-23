#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[4];
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }
    // We need our rectangle be bounded in both directions;
    // the smallest number will be bounded by the second smallest
    // and the third smallest number will be bounded by the largest.
    // We can't do any better without leaving a hole in one of the sides.
    sort(a, a + 4); 
    cout << a[0] * a[2] << '\n';
}