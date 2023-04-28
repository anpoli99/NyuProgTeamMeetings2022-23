#include <bits/stdc++.h>
using namespace std;

/*
We can simulate each guess and check if the letter
appears in the target word. Once there are 10 misses,
we know the guesser has lost.
*/


int in_string[256]; 
int main(){
    string target, guess;
    cin >> target >> guess;
    int misses = 0;
    for(char c : target){
        in_string[c]++;
    }
    int correctly_guessed = 0;
    int missed = 0;
    for(char c : guess){
        if(in_string[c] == 0){
            missed++;
            if(missed == 10){
                cout << "LOSE" << endl;
                return 0;
            }
        }else{
            correctly_guessed += in_string[c];
            if(correctly_guessed == target.size()){
                cout << "WIN" << endl;
                return 0;
            }
        }
    }

}