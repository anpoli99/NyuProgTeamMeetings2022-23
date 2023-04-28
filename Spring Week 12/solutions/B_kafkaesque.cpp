#include <bits/stdc++.h>
using namespace std;

/*
This problem requires using a queue, either implicitly
or explicitly (which this implementation does). We can
more-or-less simulate the process described in the problem
statement as long as we have a way to keep track of how
many times we cycle through the queue.
*/

int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        int next;
        cin >> next;
        q.push(next);
    }
    int count = 0;
    while(!q.empty()){
        queue<int> next_round;
        int current_max = -1;
        // Only take the next element in the queue if it
        // is larger than the current element. So we 
        // initialize current_max to -1.

        while(!q.empty()){
            int next = q.front();
            q.pop();
            if(next > current_max){
                current_max = next;
            }else{
                next_round.push(next);
                current_max = 1e9; // The line is held up until we get this signature
            }
        }
        q = next_round;
        ++count;
    }

    cout << count << endl;
}