#include<bits/stdc++.h>
using namespace std;


#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION cout << fixed << setprecision(10);

int main(){
    //Suggestion: always leave these two lines at the top of your code 
    // so that you don't have to worry about them 
    FASTIO // Makes cin/cout faster, which is essential on some problems
    PRECISION // Sets the precision of cout to 10 decimal places; 
             // not doing this can cause WA on some problems

    // Inputs in C++ are the most straightforward of all languages
    // Example: Reading 5 integers on a line
    // 1 2 3 4 5
    int a[5];
    for(int i = 0; i < 5; i++){
        cin >> a[i]; // This works for integers, doubles, strings, etc.
    }
    // Example: Reading 5 integers on 5 lines
    // 1
    // 2
    // 3
    // 4
    // 5
    int b[5];
    for(int i = 0; i < 5; i++){
        // We don't need to worry about newlines; all whitespace is the same
        cin >> b[i]; 
    }

    // Sometimes we do care about newlines, though
    // What if we wanted to read an entire line of text?
    // We can use getline() for this
    string s;
    getline(cin, s); // If we used cin before, we need to get rid of the trailing '\n' first

    getline(cin, s); // Now we can read the entire line of text
    // Let's see what's inside s
    // Suppose the input was an integer, followed by an unknown number of strings

    // We can use stringstream to parse the input
    stringstream ss(s);
    int x;
    ss >> x; // x is now the integer we read
    string t;
    while(ss >> t){
        // t is now each string in the line
        // We can do whatever we want with it
    }


    // Now we have our answer and we want to output it
    int ans = 0;
    cout << ans << '\n'; // That's it
    // Use '\n' instead of endl; endl flushes the output buffer, which is slow

    // Let's say I wanted to read to the end of the file
    // Maybe each test case starts with an integer n, the size of the problem
    
    /*
    int n;
    while(cin >> n){
        // Do something with n
    }
    */

    // cin >> n will return false when it reaches the end of the file

}