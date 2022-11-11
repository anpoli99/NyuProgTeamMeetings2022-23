import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!
    static int awkwardParty(int n, int[] a){
        // This is a callback to last week :) we can use a hash map to solve it
        HashMap<Integer, Integer> prev = new HashMap<>();
        int ans = n; // base case according to problem statement
        for(int i = 0; i < n; i++){
            if(prev.containsKey(a[i])){
                ans = Math.min(ans, i - prev.get(a[i]));
            }
            prev.put(a[i], i);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        StringTokenizer st = new StringTokenizer(f.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(awkwardParty(n, a));
    }
}

