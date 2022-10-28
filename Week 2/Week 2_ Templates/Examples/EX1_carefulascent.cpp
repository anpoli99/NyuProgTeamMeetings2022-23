#include <bits/stdc++.h>
using namespace std;

// In the actual problem, there are several shields!
// This means actually calculating Mal's final position is sort of tedious
// I'd encourage you to pay more attention to the actual binary search part

/*
This is just to calculate the final position of Mal
*/
struct shield{
    int shield_begin, shield_end; double f;
    bool operator<(const shield& v) const{
        return shield_begin < v.shield_begin;
    }
};
vector<shield> v;
int x,y;
double get_final_position(double initial_x_velocity){
    
    int y_position = 0;
    double x_position = 0;
    for(int i = 0; i < v.size(); i++){
        x_position += (v[i].shield_begin - y_position) * initial_x_velocity;
        x_position += (v[i].shield_end - v[i].shield_begin) * v[i].f * initial_x_velocity;
        y_position = v[i].shield_end;
    }
    x_position += (y - y_position) * initial_x_velocity;
    return x_position;

}
int main(){
    cin >> x >> y;
    bool neg = x < 0;
    if(neg) x = -x; // just work w/ positive x for simplicity
    int n;
    cin >> n;
    v = vector<shield>(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].shield_begin >> v[i].shield_end >> v[i].f;
    }
    sort(v.begin(), v.end());

    double lo = 0, hi = x; 
    for(int i = 0; i < 100; i++){
        double mid = (lo + hi) / 2;
        if(get_final_position(mid) < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    if(neg) lo = -lo;
    cout << lo << '\n';
}   