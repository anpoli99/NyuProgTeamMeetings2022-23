import java.util.*;
import java.io.*;

class Main{
    static int N = (int)2e5 + 5;
    static ArrayList<Integer>[] adj = new ArrayList[N];
    // if we need weights, we can use:
    class Point{
        int x, y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    // static ArrayList<Point>[] adj = new ArrayList[N]; 
    static void howManyVertices(int root, int parent){ // how many vertices in subtree?
        int ans = 1;
        for(int child : adj[root]){
            if(child == parent) continue;
            ans += howManyVertices(child, root);
        }
        return ans;
    }
    
    static int diameter = 0;
    // The diameter is the longest path between two vertices in a tree.
    // We can find it by finding the two longest paths from a given vertex
    // to the leaves of the tree. The longest path through this vertex (without
    // its parent) is the sum of these two paths. The diameter will be one of
    // these such paths.
    static int findLargestPathToLeaves(int root, int parent){
        int max1 = 0, max2 = 0;
        for(int child : adj[root]){
            if(child == parent) continue;
            int path = findLargestPathToLeaves(child, root) + 1; // +1 for current edge
            if(path > max1){ 
                max2 = max1; // we know max1 >= max2
                max1 = path; 
            }else if(path > max2){
                max2 = path;
            }
        }
        diameter = Math.max(diameter, max1 + max2);
        return max1;
    }
    static int[] root = new int[N]; // union-find for Kruskal's algorithm; see last week's meeting for more details
    static int find(int k){
        if(root[k] < 0) return k;
        return root[k] = find(root[k]);
    }
    static class edge implements Comparable<edge>{
        // In Java, we can use a class to represent an edge
        int u, v, w;
        public int compareTo(edge other){
            return w - other.w;
        }
    }
    static int kruskals_mst(ArrayList<edge> edges, int n){
        Collections.sort(edges); // lowest weight to highest weight
        Arrays.fill(root, -1);
        int ans = 0;
        for(edge e : edges){
            int u = find(e.u), v = find(e.v);
            if(u != v){
                root[u] = v;
                ans += e.w; // add edge to MST
            }
        }
        return ans;
    }
    static int[] dist = new int[N];
    static int[] parent = new int[N]; // useful for reconstructing the MST
    static boolean[] vis = new boolean[N];
    static ArrayList<Point>[] neighbors = new ArrayList[N];
    static int prims_mst_n_squared(int n){
        int root = 1; // start at any vertex
        Arrays.fill(dist, (int)1e9 + 5);
        Arrays.fill(vis, false);
        dist[root] = 0;
        int ans = 0;
        parent[root] = -1;
        for(int i = 1; i < n; i++){ // Tree has n - 1 edges
            int best_dist = (int)1e9 + 5, next = -1;
            for(int j = 1; j <= n; j++){
                if(!vis[j] && dist[j] < best_dist){
                    best_dist = dist[j];
                    next = j;
                }
            }
            // if(next == -1) return -1; // graph is not connected
            vis[next] = true;
            ans += best_dist;
            // add edge (parent[next], next) to MST
            for(Point p : neighbors[next]){
                int child = p.x, weight = p.y;
                if(!vis[child] && weight < dist[child]){
                    dist[child] = weight;
                    parent[child] = next;
                }
            }
        }
        return ans;
    }

    static int prims_mst(int n){
        // use a priority queue to make algorithm O(E log V)
        PriorityQueue<Point> pq = new PriorityQueue<>((a, b) -> a.y - b.y);
        int root = 1; // start at any vertex
        Arrays.fill(dist, (int)1e9 + 5);
        Arrays.fill(vis, false);
        dist[root] = 0;
        int ans = 0;
        parent[root] = -1;
        pq.add(new Point(root, 0));
        while(!pq.isEmpty()){
            Point p = pq.poll();
            int next = p.x;
            if(vis[next]) continue;
            vis[next] = true;
            ans += p.y;
            // add edge (parent[next], next) to MST
            for(Point p : neighbors[next]){
                int child = p.x, weight = p.y;
                if(!vis[child] && weight < dist[child]){
                    dist[child] = weight;
                    parent[child] = next;
                    pq.add(new Point(child, weight));
                }
            }
        }
        return ans;
    }

}