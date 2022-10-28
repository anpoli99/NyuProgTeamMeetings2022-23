#include <bits/stdc++.h> 
using namespace std;
                                                // heaviest weight we can carry
bool validate(int n, vector<int>& a, vector<int>& b, int heaviest_weight){
    // remove all weights we can; we can always pair these together
    // now we need to check if the weights we can't move are paired
    vector<int> remaining_a, remaining_b;
    for(int i = 0; i < n; i++){
        if(a[i] > heaviest_weight){
            remaining_a.push_back(a[i]);
        }
        if(b[i] > heaviest_weight){
            remaining_b.push_back(b[i]);
        }
    }
    if(remaining_a.size() % 2 == 1) return false; // can't pair an odd number of weights
    if(remaining_b.size() % 2 == 1) return false;
    for(int i = 0; i < remaining_a.size(); i += 2){
        if(remaining_a[i] != remaining_a[i + 1]) return false; // these weights aren't paired
    }
    for(int i = 0; i < remaining_b.size(); i += 2){
        if(remaining_b[i] != remaining_b[i + 1]) return false;
    }
    return true;
}
int free_weights(int N, vector<int>& a, vector<int>& b){
    int lo = 0, hi = 1e9 + 5; // 'hi' must be greater/equal than the maximum weight
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(validate(N, a, b, mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;  
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << free_weights(n, a, b) << endl;
}   