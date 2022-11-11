import java.util.*;
import java.io.*;

class Main{
    static String a,b;
    static int[][] dp = new int[100][100];
    // returns the length of the longest common subsequence of a[0..i] and b[0..j]
    static int longest_common_subsequence(int i, int j){ 
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a.charAt(i) == b.charAt(j)){
            // characters match; greedily add them to the answer
            return dp[i][j] = 1 + longest_common_subsequence(i - 1, j - 1);
        }else{
            // check moving one character in both strings and see which one gives the longer subsequence
            return dp[i][j] = Math.max(longest_common_subsequence(i - 1, j), longest_common_subsequence(i, j - 1));
        }
    }

    // call this after calling longest_common_subsequence to get the actual subsequence
    static String ans = "";
    static void build_lcs(int i, int j){
        if(i < 0 || j < 0) {
            ans = "";
            return;
        }
        if(a.charAt(i) == b.charAt(j)){
            build_lcs(i - 1, j - 1);
            ans += a.charAt(i);
        }else if(i > 0 && dp[i - 1][j] > dp[i][j - 1]){ // move in the direction that gives the longer subsequence
            build_lcs(i - 1, j);
        }else{
            build_lcs(i, j - 1);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = br.readLine();
        b = br.readLine();
        for(int i = 0; i < 100; i++) Arrays.fill(dp[i], -1);
        System.out.println(longest_common_subsequence(a.length() - 1, b.length() - 1));
        build_lcs(a.length() - 1, b.length() - 1);
        System.out.println(ans);
    }
}