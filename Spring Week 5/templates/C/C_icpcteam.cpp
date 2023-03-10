#include <bits/stdc++.h>
using namespace std;

int icpcteam(int n, vector<int>& students){
    // Your code here
    return -1; // Replace this line
}

int main(){
    ios_base::sync_with_stdio(false); // Just for speeding up I/O
    cin.tie(NULL);

    int qr;
    cin >> qr;
    for(int tc = 1; tc <= qr; tc++){
        int n;
        cin >> n;
        vector<int> students(n);
        for(int i = 0; i < n; i++) cin >> students[i];
        cout << icpcteam(n, students) << '\n';
    }
}