#include <bits/stdc++.h>
using namespace std;

// For this problem, we can show that we only need to worry about at most 3 trees
// We'll have two main trees that we connect via their centroids, and all other
// trees can be connected to the centroid of the largest tree.
// (Larger is defined by the diameter of the tree)
// The "centroid" of a tree is the node that minimizes the maximum distance to any other node
// We can find the centroid of a tree using a BFS: we start with the leaves and remove them
// until we're left with the centroid

// The longest path from the main trees is the distance to each centroid + 1
// The longest path from the other trees is the distance to the centroid of the
// smaller tree + 2
// The longest path from any individual tree is the diameter of the tree
// Our answer is the maximum of these three types of paths

const int N = 1e5 + 5;
vector<int> e[N];
int ct[N];
bool vis[N];
queue<int> q; // queue of leaves; we'll use this to find the centroids
void initialize_queue(int i, int p){
    vis[i] = true;
    for(int j : e[i]){
        if(j != p){
            initialize_queue(j, i);
        }
    }
    if(e[i].size() <= 1){
        q.push(i);
    }else{
        ct[i] = e[i].size();
    }
}
int get_centroid(int i){
    initialize_queue(i, -1);
    int k;
    while(q.size()){
        k = q.front(); q.pop();
        for(int j : e[k]){
            ct[j]--;
            if(ct[j] == 1){
                q.push(j);
            }
        }
    }
    return k;
}
int max_leaf_distance2 = 0;
int get_max_leaf_distance(int i, int p){
    int max_leaf_distance1 = 0;
    for(int j : e[i]){
        if(j != p){
            int leaf_distance = 1 + get_max_leaf_distance(j, i);
            if(leaf_distance > max_leaf_distance1){
                if(p == -1){max_leaf_distance2 = max_leaf_distance1;}
                max_leaf_distance1 = leaf_distance;
            }else if(p == -1 && leaf_distance > max_leaf_distance2){
                max_leaf_distance2 = leaf_distance;
            }
        }
    }
    return max_leaf_distance1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int ans = 0;
    int length_to_centroid1 = 0, length_to_centroid2 = 0, length_to_centroid3 = 0;
    int num_trees = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            num_trees++;
            int centroid = get_centroid(i);
            max_leaf_distance2 = 0;
            int max_leaf_distance1 = get_max_leaf_distance(centroid, -1);
            if(max_leaf_distance1 > length_to_centroid1){
                length_to_centroid3 = length_to_centroid2;
                length_to_centroid2 = length_to_centroid1;
                length_to_centroid1 = max_leaf_distance1;
            }else if(max_leaf_distance1 > length_to_centroid2){
                length_to_centroid3 = length_to_centroid2;
                length_to_centroid2 = max_leaf_distance1;
            }else if(max_leaf_distance1 > length_to_centroid3){
                length_to_centroid3 = max_leaf_distance1;
            }
            ans = max(ans, max_leaf_distance1 + max_leaf_distance2);
        }
    }
    if(num_trees > 1){ans = max(ans, length_to_centroid1 + length_to_centroid2 + 1);}
    if(num_trees > 2){ans = max(ans, length_to_centroid2 + length_to_centroid3 + 2);}
    cout << ans << endl;
}
