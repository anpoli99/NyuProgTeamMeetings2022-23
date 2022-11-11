import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!
    static final int INF = (1 << 30) - 1;
    static final int N = 2000 + 20;
    static int[][] dp = new int[N][N];
    static int[][] visited = new int[N][N];
    static int vis_idx = 1; // this is a helpful way to avoid having to clear the while dp array every test case
    static int[] a = new int[N];
    static int n;
    static int solve(int i, int j){ // i is index of the jump, j is the current height
        if(j < 0) return INF;
        if(i == n) return j != 0 ? INF : 0;
        int res = dp[i][j];
        if(visited[i][j] == vis_idx) return res;
        visited[i][j] = vis_idx;
        res = Math.min(solve(i + 1, j - a[i]), solve(i + 1, j + a[i])); 
        res = Math.max(res, j); // the max height is at least the current height
        return dp[i][j] = res;
    }
    static StringBuilder ans = new StringBuilder();
    static void build(int i, int j){ // after solving, we need to recreate the answer  
        // we can check both possibilities and see which one gives us the correct answer
        // for a given (i,j)
        if(i == n) return;
        int res = solve(i, j);
        if(res == solve(i + 1, j + a[i])){
            ans.append('U');
            build(i + 1, j + a[i]);
        }else{
            ans.append('D');
            build(i + 1, j - a[i]);
        }

    }
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(f.readLine());
        while(qr-- > 0){
            n = Integer.parseInt(f.readLine());
            StringTokenizer st = new StringTokenizer(f.readLine());
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }
            ans.setLength(0);
            int res = solve(0, 0);
            if(res >= INF){
                System.out.println("IMPOSSIBLE");
            }else{             
                build(0, 0);
                System.out.println(ans);
            }
            vis_idx++;
        }
    }
}