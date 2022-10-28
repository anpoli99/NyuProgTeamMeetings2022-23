#include <bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 5;
int a, d; // note; this template just keeps these variables global
int ascent_distance[N], descent_distance[N];
int ascent_time[N], descent_time[N];
double travelling_monk(){
    // Your code to calculate when the times are the same goes here.
    return -1;
}


int main(){
    cout << fixed << setprecision(10); // this is boilerplate; prints all doubles with 10 decimal places; without this line, you could get W.A.
    cin >> a >> d;
    
    for(int i = 0; i < a; i++){
        cin >> ascent_distance[i] >> ascent_time[i];
    }

    for(int i = 0; i < d; i++){
        cin >> descent_distance[i] >> descent_time[i];
    }

    cout << travelling_monk() << endl;
}   