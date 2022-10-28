import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
    static boolean validate(int Q, int M, int S, int L, int time) {
        for(int i = 0; i < M; i++){
            // greedily add as many long intervals as possible
            int long_intervals = Math.min(L, time / Q); 
            L -= long_intervals;
            
            int remaining_time = time - long_intervals * Q;
            
            // use remaining time to add as many short intervals as possible
            
            // Edge case here; if we don't take the min, we should use longs instead of ints to prevent overflow
            int short_intervals = Math.min(S, remaining_time); 
            S -= short_intervals;
        }
        return L == 0 && S == 0;
    }
    static int smallSchedule(int Q, int M ,int S, int L){
        int lo = 0, hi = (int)1.1e9;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(validate(Q, M, S, L, mid)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int Q = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        System.out.println(smallSchedule(Q, M, S, L));
    }
}