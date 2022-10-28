#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int nxt[N];
int prv[N];
char symbol[N];
void insert(int k, int v){
    nxt[v] = nxt[k];
    if(nxt[k] != -1){
        prv[nxt[k]] = v;
    }
    nxt[k] = v;
    prv[v] = k;
}
void remove(int k){
    nxt[prv[k]] = nxt[k];
    if(nxt[k] != -1){
        prv[nxt[k]] = prv[k];
    }
}
int main(){
    string s;
    cin >> s;
    memset(nxt, -1, sizeof nxt);
    memset(prv, -1, sizeof prv);
    nxt[0] = 1;
    prv[1] = 0;
    int cursor = 0;
    int next_pointer = 2;
    for(char c : s){
        if(c == 'L'){
            if(prv[cursor] != -1) cursor = prv[cursor];
        }else if(c == 'R'){
            if(nxt[cursor] != -1) cursor = nxt[cursor];
        }else if(c == 'B'){
            if(cursor != 0){
                remove(cursor);
                cursor = prv[cursor];
            }
        }else{
            insert(cursor, next_pointer);
            cursor = next_pointer;
            symbol[next_pointer] = c;
            next_pointer++;
        }
    }
    int idx = nxt[0];
    while(idx != -1){
        cout << symbol[idx];
        idx = nxt[idx];
    }
    cout << endl;
}
