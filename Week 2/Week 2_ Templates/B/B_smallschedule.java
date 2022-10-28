import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{

    static int smallSchedule(int Q, int M ,int S, int L){
        // Your code here: calculate the minimum time
        return -1;
    }
                                        // if you write your own, make sure to have 'throws IOException' in the method signature
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