#include <bits/stdc++.h>
using namespace std;

// Input: N and A, where A is a vector of N integers
// Output: True if the vector is Jolly, False otherwise
bool jollyjumpers(int N, vector<int> A){
    //Your code here
    return true;
}

int main(){
    int N;
    while(cin >> N){
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        cout << (jollyjumpers(N,A) ? "Jolly" : "Not jolly") << endl;
    }
}