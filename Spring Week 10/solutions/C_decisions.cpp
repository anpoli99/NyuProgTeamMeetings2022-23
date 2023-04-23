#include <bits/stdc++.h>
using namespace std;

// This problem was probably too hard to be in position 'C', so that's
// my mistake. The solution is to use an implicit tree construction, choosing
// one bit at a time. If any subtree has the same value for all leaves,
// we can condense it into one node. Repeating this tells us the minimum
// number of nodes we need to represent the tree.

const int N = (1 << 18) + 5;
int a[N];
int n; // how many bits
// Return 0 if tree is all 0, 1 if tree is all 1, -1 otherwise
int removable_nodes = 0; // Count the number of nodes we can remove
int dfs(int bit_position, int current_bitstring){
    if(bit_position == n){
        return a[current_bitstring];
    }
    int left = dfs(bit_position + 1, current_bitstring);
    int right = dfs(bit_position + 1, current_bitstring | (1 << bit_position));
    if(left == right && left != -1){
        removable_nodes += 2; // We don't need either of the children
        return left;
    }else{
        return -1;
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        cin >> a[i];
    }
    dfs(0, 0);
    // 2^n * 2 - 1 = size of the tree originally
    cout << (1 << n) * 2 - 1 - removable_nodes << endl;
}  