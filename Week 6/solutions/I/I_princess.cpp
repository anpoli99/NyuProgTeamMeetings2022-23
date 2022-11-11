#include <bits/stdc++.h>
using namespace std;

// I'll only write this one in C++ because I'm lazy, but if you want it in another
// language, dm me on discord

// The basic idea here is that the longest common subsequence where all elements are unique
// is the same as the longest increasing subsequence of an array, after we replace each element
// with its index in the original array

int lis(vector<int>& a){
    vector<int> pos(a.size() + 2, INT_MAX);
    pos[0] = INT_MIN;
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        int lo = 0, hi = a.size() + 1;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(pos[mid] < a[i]){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        pos[lo + 1] = a[i];
        ans = max(ans, lo + 1);
    }
    return ans;
}
int main(){
    int qr;
    cin >> qr;
    for(int tc = 1; tc <= qr; tc++){
        int n, p, q;
        cin >> n >> p >> q;
        vector<int> b = {0};
        map<int, int> pos;
        for(int i = 0; i <= p; i++){
            int x;
            cin >> x;
            pos[x] = i;
        }
        for(int i = 0; i <= q; i++){
            int x;
            cin >> x;
            if(pos.count(x)){
                b.push_back(pos[x]);
            }
        }
        cout << "Case " << tc << ": " << lis(b) << '\n';

    }
}