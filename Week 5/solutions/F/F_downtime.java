import java.util.*;
import java.io.*;


class Main{
    // Make sure you have the class name as Main if you use this template
    static final int INF = (int)1e9 + 5;
    static class Pair implements Comparable<Pair>{
    	int x,y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
        public int compareTo(Pair p){
            if(this.x == p.x){
                return this.y - p.y;
            }
            return this.x - p.x;
        }
    }
    static int downtime(int n, int k, ArrayList<Integer> a){
        // There's other solutions to this problem, such as using a two-pointer approach.
        // If you implement it fast enough, we could just have an array that has the count of 
        // requests at each time, and then iterate over every subarray of size 1000.
        // I think it's worth noting that the set approach requires almost no code compared to
        // these alternatives and is still pretty fast.

        TreeSet<Pair> s = new TreeSet<Pair>(); 
        for(int i = 0; i < n; i++){
            // A useful trick; we can find the index of a lower bound in a set in O(log n) time
            // by storing it as a pair
            s.add(new Pair(a.get(i), i)); 
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            Pair it = s.ceiling(new Pair(a.get(i) - 1000, INF));
            ans = Math.max(ans, i - it.y + 1);
        }
        ans = (ans + k - 1) / k;
        return ans;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Faster IO to give your program as much time as possible
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            a.add(Integer.parseInt(br.readLine()));
        }
        System.out.println(downtime(n, k, a));
    }
}