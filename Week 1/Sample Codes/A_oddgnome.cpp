#include <bits/stdc++.h>
using namespace std;


int main(){
    int trials;
    cin >> trials;
    for(int t = 0; t < trials; t++){
        int n;
        cin >> n;
        vector<int> gnomes(n);
        for(int i = 0; i < n; i++){
            cin >> gnomes[i];
        }
        for(int i = 1; i < n - 1; i++){ //i = candidate for the king
            int prev = -1;
            bool sorted = true;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(gnomes[j] < prev){
                    sorted = false;
                }
                prev = gnomes[j];
            }
            if(sorted){
                cout << i << endl;
            }
        }
    }
}   