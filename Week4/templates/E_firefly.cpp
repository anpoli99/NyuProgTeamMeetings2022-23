#include <bits/stdc++.h>
using namespace std;

// input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
// return a pair with the optimal # of obstacles and the # of levels where that is possible
// note that the firefly cannot fly at a height of 0
pair<int,int> firefly(int n, int h, vector<int>& a, vector<int>& b){
    // Note that n = a.size() + b.size(); 
    n /= 2;

    // Your code to find the optimal number of obstacles goes here
    return make_pair(-1, -1); // This is a placeholder
}

int main(){
    int n,h;
    cin >> n >> h;
    vector<int> a(n/2), b(n/2);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) cin >> a[i / 2];
        else cin >> b[i / 2];
    }
    auto p = firefly(n, h, a, b);
    cout << p.first << " " << p.second << endl;
}