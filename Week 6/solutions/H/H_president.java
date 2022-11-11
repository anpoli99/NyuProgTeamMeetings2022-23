import java.util.*;
import java.io.*;

class Main{

    static final int INF = (1 << 30) - 1;
    static final int N = 2000 + 20;
    static int[][] dp = new int[N][N];
    static int[] delegates = new int[N], cost = new int[N];
    static int solve(int i, int j){
        // i is the index of the current region
        // delegates[i] is the number of delegates gained for winning region i
        // cost[i] is the number of voters we need to persuade to win region i
        // cost[i] is precalculated below
        if(j < 0) return 0;
        if(!i) return j == 0 ? 0 : INF;
        int res = dp[i][j];
        if(res != -1) return res;
        // try either winning region i or not
        res = Math.min(solve(i - 1, j), solve(i - 1, j - delegates[i]) + cost[i]);
        res = Math.min(res, INF); // no overflow
        return dp[i][j] = res;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        int sum = 0;
        for(int i = 1; i <= n; i++){
            StringTokenizer st = new StringTokenizer(f.readLine());
            delegates[i] = Integer.parseInt(st.nextToken());
            sum += delegates[i];
            int c = Integer.parseInt(st.nextToken());
            int f = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());
            if(c + u <= f){
                // can't win this region; cost is INF
                cost[i] = INF;
            }else{
                if(f > c){
                    // we're losing in this region, so we need at least (f - c) votes to win
                    cost[i] += f - c;
                    u -= f - c;
                    cost[i] += u / 2 + 1; // strict majority of the remaining votes
                }else{
                    u -= c - f;
                    if(u >= 0) cost[i] += u / 2 + 1; // strict majority of the remaining votes
                    // (but if it's negative, we'll win this region no matter what, so cost[i] = 0)
                }
            }
        }
        for(int i = 0; i < N; i++){
            Arrays.fill(dp[i], -1);
        }
        int ans = solve(n, sum / 2 + 1); // strict majority of delegates
        if(ans >= INF) System.out.println("impossible");
        else System.out.println(ans);
    }
}