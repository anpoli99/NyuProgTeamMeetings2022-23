import java.util.*;
import java.io.*;

class Main{
    // If you use this template, make sure the class name is Main
    static int cd(int n, int m, int[] a, int[] b){
        // Your code to find the maximum number of cds that can be bought goes here
        return -1; // Replace this line with your code
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        while(n != 0 || m != 0){
            int[] a = new int[n];
            int[] b = new int[m];
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(in.readLine());
            }
            for(int i = 0; i < m; i++){
                b[i] = Integer.parseInt(in.readLine());
            }
            System.out.println(cd(n, m, a, b));
            st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
        }
    }
}