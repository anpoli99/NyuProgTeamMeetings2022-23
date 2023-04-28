#include<bits/stdc++.h>
using namespace std;
/*
There's a couple of ways to solve this problem,
but the simplest is to just try all possible sums. 
We know that the consecutive numbers are between 1
and 100, so we can just try all possible sums and see
if any are even or odd. 
*/

int main(){
    int n;
    cin >> n;
    bool can_be_odd = false;
    bool can_be_even = false;
    for(int i = 1; i + n - 1 <= 100; i++){ 
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += i + j;
        }
        if(sum % 2 == 0){
            can_be_even = true;
        }else{
            can_be_odd = true;
        }
    }
    if(can_be_even && can_be_odd){
        cout << "Either" << endl;
    }else if(can_be_even){
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }


    /*
    An alternate solution:
    if(n % 4 == 0){
        cout << "Even" << endl;
    }else if(n % 2 == 0){
        cout << "Odd" << endl;
    }else{
        cout << "Either" << endl;
    }
    I'll leave the proof as an exercise to the reader ;)
    */
    
}