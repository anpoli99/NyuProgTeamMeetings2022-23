#include <bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 5;
int a, d; // note; this template just keeps these variables global
int ascent_distance[N], descent_distance[N];
int ascent_time[N], descent_time[N];
                // let's us just write this function once by taking pointers
double calculate_distance(int* distances, int* times, int n, double time){
    // this function tells us how far we can travel in a given time
    double current_distance = 0;
    double current_time = 0;
    for(int i = 0; i < n && current_time < time; i++){
        double next_time = current_time + times[i];
        if(next_time > time){
            double remaining_time = time - current_time;
            return current_distance + remaining_time * (distances[i] / (double)times[i]);
        }
        current_distance += distances[i];
        current_time = next_time;
    }
    return current_distance;
}
double travelling_monk(){
    double total_time = 0, total_distance = 0;
    for(int i = 0; i < a; i++){
        total_time += ascent_time[i];
        total_distance += ascent_distance[i];
    }
    double lo = 0, hi = total_time;
    for(int i = 0; i < 100; i++){
        double mid = (lo + hi) / 2;
        double dist_ascent = calculate_distance(ascent_distance, ascent_time, a, mid);
        double dist_descent = calculate_distance(descent_distance, descent_time, d, mid);

        if(dist_ascent < total_distance - dist_descent){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return lo;
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