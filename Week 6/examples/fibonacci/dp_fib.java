import java.util.*;
import java.io.*;

class Main{
    static long fibonacci(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    static long[] dp = new long[100];
    static long fibonacciDP(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibonacciDP(n - 1) + fibonacciDP(n - 2);
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Arrays.fill(dp, -1);
        long start = System.currentTimeMillis();
        System.out.println(fibonacci(n));
        long end = System.currentTimeMillis();
        System.out.println("It took " + (end - start) + "ms to calculate that!");
        start = System.currentTimeMillis();
        fibonacciDP(n);
        end = System.currentTimeMillis();
        System.out.println("It took " + (end - start) + "ms with dp!");
    }
}