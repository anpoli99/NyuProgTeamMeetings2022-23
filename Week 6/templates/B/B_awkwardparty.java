import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!
    static int awkwardParty(int n, int[] a){
        // Your code to find the awkwardness goes here
        return -1;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(f.readLine());
        StringTokenizer st = new StringTokenizer(f.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(awkwardParty(n, a));
    }
}

