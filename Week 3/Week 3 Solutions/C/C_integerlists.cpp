#include <bits/stdc++.h>
using namespace std;

string format_output(vector<int> a){
    //helper function to format the output
    string ans = "[";
    for(int i = 0; i < a.size(); i++){
        ans += to_string(a[i]);
        if(i != a.size() - 1) ans += ",";
    }
    ans += "]";
    return ans;
}
string integer_lists(string commands, int n, vector<int> a){
    // The basic idea here is we'll use a boolean to track if the list is reversed
    // We'll store the data in a deque, and if the list is reversed, we can remove from the back instead
    const string ERROR = "error";
    deque<int> dq = {a.begin(), a.end()}; // Faster way to initialize than adding one by one
    bool reversed = false;
    for(char c : commands){
        if(c == 'D'){
            // Try dropping
            if(dq.empty()) return ERROR;
            if(reversed) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        }else{
            // Reverse the list
            reversed = !reversed;
        }
    }
    if(reversed){
        reverse(dq.begin(), dq.end());
    }
    return format_output(vector<int>(dq.begin(), dq.end()));
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
