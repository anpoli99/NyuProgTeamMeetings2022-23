#include <bits/stdc++.h>
using namespace std;


int main(){
    // With a queue of all people, this problem becomes solvable in linear time
    // We can keep a queue of the people in front of a given person representing each cut
    // It's not necessary to traverse the entire list when a cut happens;
    // We can just check when the person who was cut is in the front of the queue
    // I'll implement with a deque so we can simulate a cut by adding a person to the front

    int n;
    cin >> n;
    deque<string> line;
    
    //A tricky part here is we're given people as strings instead of integers
    //A map let's us index a person by their name

    //A better approach would be to map each string to an integer, and then run
    //the program using the integers as indices. This would mean we don't have
    //to keep calling the map, which takes time. I think the version here is
    //more readable though.
    map<string, queue<string>> cuts; 
    set<string> deleted;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        line.push_back(s);
    }
    int q;
    cin >> q;
    while(q-- > 0){
        string command;
        cin >> command;
        if(command == "cut"){
            string x,y;
            cin >> x >> y;
            cuts[y].push(x);
        }else{  // command == "leave"
            string x;
            cin >> x;
            deleted.insert(x);
        }
    }
    while(line.size() > 0){
        string s = line.front();
        if(cuts[s].size() > 0){
            // This person was cut, so we need to add the person in front of them
            line.push_front(cuts[s].front());
            cuts[s].pop();
        }else{
            if(deleted.count(s) == 0){ // Deleted doesn't contain this person
                cout << s << '\n';
            }
            line.pop_front();
        }

    }
}
