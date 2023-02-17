#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};
// Input format: c = Your location
// n = # of enemy spies
// cen[i] = Location of enemy spy i
// rad[i] = Radius of enemy spy i
// Output: Return maximum communication range as specified in the problem statement
int solve(point c, int n, vector<point> cen, vector<int> rad){
    return -1; // This is a placeholder
}

int main(){
    point c;
    int n;
    cin >> c.x >> c.y >> n;
    vector<point> cen(n);
    vector<int> rad(n);
    for(int i = 0; i < n; i++){
        cin >> cen[i].x >> cen[i].y >> rad[i];
    }
    cout << solve(c,n,cen,rad) << endl;
}