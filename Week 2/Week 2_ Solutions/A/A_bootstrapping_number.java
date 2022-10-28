import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
    static double solve(long n){
        double lo = 0, hi = 40;
        for(int i = 0; i < 100; i++){
            double mid = (lo + hi) / 2;
            if(Math.pow(mid, mid) > n){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return lo;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(in.readLine());
        System.out.println(solve(n));
    }
}