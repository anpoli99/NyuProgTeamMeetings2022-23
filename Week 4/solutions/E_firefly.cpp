#include <bits/stdc++.h>
using namespace std;

// input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
// return a pair with the optimal # of obstacles and the # of levels where that is possible
// note that the firefly cannot fly at a height of 0
pair<int,int> firefly(int n, int h, vector<int>& a, vector<int>& b){
    // Note that n = a.size() + b.size(); 
    n /= 2;

    // We can keep track of where each stalagmite ends and each stalactite begins
    // To do this, it's easier if we have the height of where the stalagtite begins instead of its length
    for(int& i : b){
        i = h - i;
    }

    int min_obstacles = INT_MAX;
    int num_levels = 0;
    int cur = n;

    // We can use a sliding window to find the minimum number of stalagmites that need to be removed
    // At each height, we'll advance the pointer as it passes the beginning/end of obstacles
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int a_index = 0, b_index = 0;
    for(int i = 1; i <= h; i++){
        while(a_index < n && a[a_index] <= i){
            a_index++;
            cur--;
        }
        while(b_index < n && b[b_index] <= i){
            b_index++;
            cur++;
        }
        if(cur < min_obstacles){
            min_obstacles = cur;
            num_levels = 1;
        }else if(cur == min_obstacles){
            num_levels++;
        }
    }
    return make_pair(min_obstacles, num_levels);
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