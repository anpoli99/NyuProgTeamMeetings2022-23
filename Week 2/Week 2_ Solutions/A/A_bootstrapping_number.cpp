#include <bits/stdc++.h> 
using namespace std;

double bootstrappingnumber(long long x){
    double lo = 0, hi = 1e9;
    for(int i = 0; i < 100; i++){
        double mid = (lo + hi) / 2;
        if(pow(mid, mid) < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return lo;
}

int main(){
    cout << fixed << setprecision(10); // boilerplate; set precision to 10 decimal places; w/o this you might get WA
    long long n;
    cin >> n;

    cout << bootstrappingnumber(n) << endl;
}   