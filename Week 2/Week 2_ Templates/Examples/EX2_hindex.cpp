#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
bool is_valid_h_index(int n, int h){
    int ct = 0;
    for(int i = 1; i <= n; i++){
        ct += (h <= a[i]);
    }
    return ct >= h;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(is_valid_h_index(n, mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo << '\n';

}   