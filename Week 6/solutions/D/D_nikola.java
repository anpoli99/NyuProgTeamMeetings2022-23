
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
        if(i == n) return a[i];
        if(i > n || i < 1) return INF;
        if(dp[i][j] != -1) return dp[i][j];
        // jump forward 'j' increasing the jump size, or jump back 'j - 1' leaving the jump size the same
        dp[i][j] = Math.min(solve(i + j, j + 1), solve(i - j + 1, j)) + a[i];
        return dp[i][j];
    }

    static int nikola(){
        for(int i = 0; i < N; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(2, 2); // first jump must be from 1 to 2, so we start at 2
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

