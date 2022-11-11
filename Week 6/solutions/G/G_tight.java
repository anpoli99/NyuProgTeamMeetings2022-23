import java.util.*;
import java.io.*;

class Main{
    static final int N = (int)1e2 + 5;
    static double[][] dp = new double[N][N];
    static boolean[][] vis = new boolean[N][N];
    static int n, k;
    static double solve(int i, int j){
        // There's only (at most) 2 neighbors that satisfy the "tight" condition
        // We can try both of them and take their sum
        // The proportion of lists that take any given number as the next element is 
        // 1 / (k + 1)
        if(i == n) return 1;
        double ans = dp[i][j];
        if(vis[i][j]) return ans;
        vis[i][j] = true;
        ans = solve(i + 1, j) / (k + 1);
        if(j > 0) ans += solve(i + 1, j - 1) / (k + 1);
        if(j < k) ans += solve(i + 1, j + 1) / (k + 1);
        return dp[i][j] = ans;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        while(f.ready()){
            StringTokenizer st = new StringTokenizer(f.readLine());
            k = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            for(int i = 0; i < N; i++){
                Arrays.fill(vis[i], false);
            }
            double ans = 0;
            for(int i = 0; i <= k; i++){
                ans += solve(1, i) / (k + 1);
            }
            System.out.println(ans * 100);
        }
    }
}