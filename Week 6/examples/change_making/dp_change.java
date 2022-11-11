import java.util.*;
import java.io.*;

class Main{
    static int[] coins = {1, 5, 10, 25, 50}; // You can change this, and we will always get the right answer
    static int[] dp = new int[400];
    static int minCoins(int n){
        if(dp[n] != -1) return dp[n];
        int ans = Integer.MAX_VALUE;
        for(int c : coins){
            // try using each coin
            if(n - c >= 0){
                ans = Math.min(ans, 1 + minCoins(n - c));
            }
        }
        return dp[n] = ans;
    }
    static ArrayList<Integer> ans = new ArrayList<>();
    // call this after calling minCoins to get the actual coins
    static void getCoins(int n){
        if(n == 0) return;
        for(int c : coins){
            if(n - c >= 0 && dp[n] == 1 + dp[n - c]){
                ans.add(c);
                getCoins(n - c);
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Arrays.fill(dp, -1);
        dp[0] = 0; // base case; 0 coins are needed to make 0
        System.out.println(minCoins(n));
        getCoins(n);
        for(int i : ans) System.out.print(i + " ");
        System.out.println();
    }
}