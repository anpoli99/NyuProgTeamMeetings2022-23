#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
int cnt[N];
int strength[N];
int c[N];

bool validate(int n, int value){
    // greedily match weakest kayaks with weakest people possible

    int tmp_cnt[N];
    memcpy(tmp_cnt, cnt, sizeof(cnt)); // copy cnt to tmp_cnt


    for(int k = 0; k < n; k++){
        pair<int, int> chosen_people;
        int speed = -1;
        for(int i = 1; i <= 3; i++){ // 1 = beginner, 2 = normal, 3 = expert
            for(int j = 1; j <= 3; j++){
                int tmp = (strength[i] + strength[j]) * c[k];
                if(i == j && tmp_cnt[i] < 2) continue;
                if(tmp_cnt[i] > 0 && tmp_cnt[j] > 0 && tmp >= value){
                    chosen_people = {i, j};
                    speed = tmp;
                    goto breakout; // useful for nested loops
                }
            }
        }
        breakout:
        if(speed < value) return false;
        tmp_cnt[chosen_people.first]--;
        tmp_cnt[chosen_people.second]--;
    }
    return true;
}
int main(){
    cin >> cnt[1] >> cnt[2] >> cnt[3]; // 1 = beginner, 2 = normal, 3 = expert
    cin >> strength[1] >> strength[2] >> strength[3];
    int n = (cnt[1] + cnt[2] + cnt[3]) / 2;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c, c + n); // we need the kayaks to be sorted
    int lo = 0, hi = 2e9 + 5;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(validate(n, mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo << '\n';
}   