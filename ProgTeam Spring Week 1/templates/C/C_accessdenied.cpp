#include <bits/stdc++.h>
using namespace std;

// The judge returns in the format: "ACCESS DENIED (time ms)"
// This function should extract the time from the string
int extract_time(string s){
    // I left this implementation to you
    // A recommendation: I'd advise testing it on its own first then solving the problem
    return -1;
}

// Call this function to query the judge
// Returns the time it took to check the password or 0 if the password is correct
int query(string q){
    cout << q << endl; // ALWAYS use endl or (<< flush) to flush the output on an interactive problem!
    string response;
    getline(cin, response);
    while(response.back() <= 32 || response.back() >= 127) response.pop_back(); // Remove trailing whitespace
    if(response == "ACCESS GRANTED") return 0;
    return extract_time(response);
}
int main(){
    // add any auxilary variables you need here
    while(true){
        string guess;
        // Your code here to generate a guess
        int time = query(guess);
        if(!time) break; // You found the password!
        // Your code here to update the parameters of the next guess
    }
}