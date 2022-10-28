#include <bits/stdc++.h>
using namespace std;


string integer_lists(string commands, int n, vector<int> a){
    /*
    Your code here; return "error" if one of the commands is invalid
                    otherwise return the final list, formatted according to the problem statement
    */
    return "error"; // this is just a placeholder
}

int main(){
    // Boilerplate for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int trials;
    cin >> trials;
    while(trials-- > 0){
        string commands;
        cin >> commands;
        int n;
        cin >> n;
        vector<int> a(n);
        int ptr = 0;
        string input_list;
        cin >> input_list;
        for(char c : input_list){
            if(c == '[' || c == ']') continue;
            if(c == ','){
                ptr++; // comma marks beginning of next number
            }else{
                a[ptr] = a[ptr] * 10 + (c - '0'); // read numbers one digit at a time
            }
        }
        cout << integer_lists(commands, n, a) << '\n'; // '\n' makes it easier to debug
    }
}
