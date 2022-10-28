#include <bits/stdc++.h>
using namespace std;


int main(){
    // The brute force approach here is just to handle each query with a list.
    // We can traverse the whole list, and process the person in the query when we find them
    // This is O(N * Q * |S|) which is fine for this problem
    // (N = # of people, Q = # of queries, |S| = length of each string)
    // If we had harsher constraints, we would need to use the other approach
    
    int n;
    cin >> n;
    vector<string> line(n);
    for(int i = 0; i < n; i++){
        cin >> line[i];
    }
    int q;
    cin >> q;
    while(q-- > 0){
        string command;
        cin >> command;
        if(command == "cut"){
            string x,y;
            cin >> x >> y;
            vector<string> next_line;
            for(string s : line){
                if(s == y){
                    next_line.push_back(x);
                    next_line.push_back(y);
                }else{
                    next_line.push_back(s);
                }
            }
            line = next_line;
        }else{  // command == "leave"
            string x;
            cin >> x;
            line.erase(find(line.begin(), line.end(), x)); // Remove the person from the line; O(N) operation
                                                          
        }
    }
    for(string s : line){
        cout << s << '\n';
    }
}
