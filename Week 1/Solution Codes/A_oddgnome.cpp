#include <bits/stdc++.h>
using namespace std;

int find_missing_gnome(vector<int>& a){
    	int n = a.size();
        for(int i = 1; i < n; i++){
            vector<int> b = a;
            b.erase(b.begin() + i);
            if(is_sorted(b.begin(), b.end())){ 
                cout << i + 1 << nl;
                break;
            }
        }

}
int main(){

    int qr;
    cin >> qr;
    for(int q = 0; q < qr; qr++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
	for(int j = 0; j < n; j++)
    }
}   