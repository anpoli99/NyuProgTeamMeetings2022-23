#include <bits/stdc++.h>
using namespace std;

// Actually the "string" for this problem doesn't matter;
// we only need to know the count of how many times each
// character appears. If there's one or two characters, then
// we're done. Otherwise, remove all but the two most common
// characters. 


int main(){
    string s;
    cin >> s;
    vector<int> counts(256); // Small tip, using the ascii values directly is usually more convenient
    for(char c : s) counts[c]++;
    int max1 = 0, max2 = 0;
    for(int i = 'a'; i <= 'z'; i++){
        if(counts[i] > counts[max1]){
            max2 = max1;
            max1 = i;
        }else if(counts[i] > counts[max2]){
            max2 = i;
        }
    }
    int n = s.size();
    cout << n - counts[max1] - counts[max2] << endl;
}  