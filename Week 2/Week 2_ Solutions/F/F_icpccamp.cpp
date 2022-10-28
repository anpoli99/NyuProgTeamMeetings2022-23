#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;
int classical[N], creative[N];
bool validate(int n, int p, int q, int sum, int diff){
    multiset<int> s;
    for(int i = 0; i < p; i++){
        s.insert(classical[i]);
    }

    for(int i = q - 1; i >= 0; i--){
        int x = min(creative[i] + diff, sum - creative[i]);
        auto it = s.upper_bound(x);
        if(it == s.begin()){ // no valid match for 'i'
            continue;
        }
        --it;
        if(*it < creative[i] - diff){
            // match was too low
            continue;
        }
        s.erase(it);
        n--;
    }
    return n <= 0;
}
int main(){

    int n, p, q, s;
    cin >> n >> p >> q >> s;

    for(int i = 0; i < p; i++){
        cin >> classical[i];
    }
    sort(classical, classical + p);

    for(int i = 0; i < q; i++){
        cin >> creative[i];
    }
    sort(creative, creative + q);
    
    if(!validate(n, p, q, s, 1e9)){
        cout << -1 << '\n';
        return 0;
    }
    int lo = 0, hi = s;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(validate(n, p, q, s, mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
}   