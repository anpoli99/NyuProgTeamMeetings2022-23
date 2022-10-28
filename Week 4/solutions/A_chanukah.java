import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    static int chanukah(int n, int k){
        // There's also a formula for this: n * (n + 1) / 2 + n
        // But constraints are small enough that we can just count the answer
        int candles = 0;
        for(int i = 1; i <= n; i++){
            candles += i + 1; // + 1 for the shammas candle
        }
        return candles;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(in.readLine());
        for(int t = 1; t <= q; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int k = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            System.out.println(t + " " + chanukah(n, k));
        }
    }
}