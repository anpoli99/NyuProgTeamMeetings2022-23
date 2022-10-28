import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
      
    // note: for convenience this template keeps these input variables global
    static final int MAXN = 5000 + 5;
    static int[] ascendingTime = new int[MAXN], descendingTime = new int[MAXN];
    static int[] ascendingDistance = new int[MAXN], descendingDistance = new int[MAXN];
    int a, d;
    static double travellingMonk(){
        // Your code to find the time when the heights are the same goes here
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        a = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        for(int i = 0; i < a; i++){
            st = new StringTokenizer(in.readLine());
            ascendingDistance[i] = Integer.parseInt(st.nextToken());
            ascendingTime[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < d; i++){
            st = new StringTokenizer(in.readLine());
            descendingDistance[i] = Integer.parseInt(st.nextToken());
            descendingTime[i] = Integer.parseInt(st.nextToken());
        }
    }
}