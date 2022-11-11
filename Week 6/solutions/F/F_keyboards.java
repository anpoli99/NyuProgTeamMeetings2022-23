import java.util.*;
import java.io.*;

class Main{
    static final int INF = (1 << 30) - 1;
    static final int N = (int)1e3 + 5;

    static int[][] dp = new int[N][N];
    static int n, m;
    static HashSet<Integer>[] notes = new HashSet[N];
    static ArrayList<Integer>[] played_by = new ArrayList[N];
    static int[] a = new int[N];
    static int solve(int i, int j){
        // i = idx of current note, j = current instrument
        // if j == 0, we need to switch instruments
        // we can store which instruments play which notes and iterate, and just recursively call again
        if(i == m + 1) return 0;
        int ans = dp[i][j];
        if(ans != -1) return ans;
        if(j == 0){
            ans = INF;
            for(int k : played_by[a[i]]){
                ans = Math.min(ans, solve(i + 1, k));
            }
            ans += 1; // +1 for switching instruments
        }else if(notes[j].contains(a[i])){
            // current instrument can play current note; don't switch
            ans = solve(i + 1, j);
        }else{
            // current instrument doesn't play this note, so we need to switch
            ans = solve(i, 0);
        }
        return dp[i][j] = ans;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= n; i++){
            notes[i] = new HashSet<>();
            st = new StringTokenizer(f.readLine());
            int k = Integer.parseInt(st.nextToken());
            for(; k > 0; k--){
                int x = Integer.parseInt(st.nextToken());
                notes[i].add(x);
                if(played_by[x] == null) played_by[x] = new ArrayList<>();
                played_by[x].add(i);
            }
        }
        st = new StringTokenizer(f.readLine());
        for(int i = 1; i <= m; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < N; i++){
            Arrays.fill(dp[i], -1);
        }
        System.out.println(solve(1, 0) - 1);
    }
}