import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    static int chanukah(int n, int k){
        // Your code to count the candles goes here
        return -1; // This is a placeholder
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