import java.io.*;
import java.util.*;


// I made a mistake in choosing this problem; it passed with doubles in C++ but not Java.
// I kinda assumed both languages would handle doubles the same (to be honest I'm not sure
// why they don't). This problem's still solvable in Java, but we need a trick where we add 
// the log of the exchange rates instead of multiplying them. (This is a good way to increase
// the precision of floating point numbers in general where you could have an exponentially 
// large/small component.)
class Main{
    static final int N = 200 + 5;
    static final double dist[][] = new double[N][N];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while(n != 0){
            HashMap<String, Integer> mp = new HashMap<String, Integer>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++){
                String s = st.nextToken();
                mp.put(s, i);
                for(int j = 0; j < n; j++){
                    dist[i][j] = Math.log(0);
                }
                dist[i][i] = Math.log(1);
            }
            // We can modify Floyd-Warshall to be converting between currencies
            // by multiplying the exchange rate instead of adding. Then we want
            // to look for a cycle where the product of the exchange rates is
            // greater than 1. This is analogous to looking for a negative cycle
            // in the shortest path problem.

            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                String c = st.nextToken();
                String[] cs = c.split(":");
                double x = Double.parseDouble(cs[0]), y = Double.parseDouble(cs[1]);
                int u = mp.get(a), v = mp.get(b);
                dist[u][v] = Math.log(y) - Math.log(x);
            }
            for(int k = 0; k < n; k++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        dist[i][j] = Math.max(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            boolean ok = true;
            for(int i = 0; i < n; i++){
                if(dist[i][i] > 0){
                    ok = false;
                    break;
                }
            }
            System.out.println(ok ? "Ok" : "Arbitrage");
            n = Integer.parseInt(br.readLine()); // Next test case
        }
    }
}