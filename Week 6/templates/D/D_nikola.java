
import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!
    static final int INF = (1 << 30) - 1;
    static final int N = 2000 + 20;
    static int[] a = new int[N]; // Just for convenience I'm leaving 'a' and 'n' global
                    //Note that I'm indexing 'a' starting from 1
    static int n;

    // AFAIK for this problem you need DP
    // Here's a template to get started on that
    static int[][] dp = new int[N][N];
    static int solve(int i, int j){
        // TODO: implement this function
        // (What are i and j?)
        return -1;
    }

    static int nikola(){
        for(int i = 0; i < N; i++){
            Arrays.fill(dp[i], -1);
        }
        return -1; // return solve(?, ?);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(f.readLine());
        for(int i = 1; i <= n; i++){
            a[i] = Integer.parseInt(f.readLine());
        }
        System.out.println(nikola());
    }
}

