import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
	
    // Input format: adj.get(i) is a list of all the neighbors of node i
    //               is_single.get(i).get(j) tells whether the edge from i to adj.get(i).get(j) is a single-lane bridge
    //               adj.get(i).size() == is_single.get(i).size() for all i
    // The input is 1-indexed
    static int bridges(int n, ArrayList<ArrayList<Integer>> adj, ArrayList<ArrayList<Boolean>> is_single){
        ArrayList<Integer> dist = new ArrayList<Integer>();
        while(dist.size() < n + 1) dist.add(Integer.MAX_VALUE);
        Deque<Integer> dq = new ArrayDeque<Integer>(); // The trick to this problem is to use a deque instead of a queue
                                                        // If a vertex isn't a bridge, we can push it to the front of the deque instead

        dq.addLast(1);
        dist.set(1, 0);
        while(dq.size() > 0){
            int u = dq.pollFirst();
            for(int i = 0; i < adj.get(u).size(); i++){
                int v = adj.get(u).get(i);
                int new_dist = dist.get(u) + (is_single.get(u).get(i) ? 1 : 0);
                if(new_dist < dist.get(v)){
                    dist.set(v, new_dist);
                    if(new_dist == dist.get(u)){
                        dq.addFirst(v);
                    }else{
                        // It's fine if we push a vertex 2 times; the algorithm still takes O(n) time.
                        // Because we can show each vertex won't be pushed more than twice, 
                        // we don't need to do any processing to make sure we don't push the same vertices.
                        dq.addLast(v);
                    }
                }
            }
        }
        return dist.get(n);
    }

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Boolean>> is_single = new ArrayList<ArrayList<Boolean>>();
        while(adj.size() < n + 1) {
            adj.add(new ArrayList<Integer>());
            is_single.add(new ArrayList<Boolean>());
        }
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken()), z = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            is_single.get(u).add(z == 1);
            adj.get(v).add(u);
            is_single.get(v).add(z == 1);
        }
        System.out.println(bridges(n, adj, is_single));
    }
}