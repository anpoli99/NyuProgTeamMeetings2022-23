import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!

    // Input: 'a' is 2d array of size [n][2]
    // Output: boolean array of size n; true if the sock can be put in the drawer, false otherwise
    static boolean[] ladice(int n, int l, int[][] a){
        // Your code goes here
        return new boolean[n]; // This is a placeholder
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        int[][] a = new int[n][2];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            a[i][0] = Integer.parseInt(st.nextToken());
            a[i][1] = Integer.parseInt(st.nextToken());
        }
        boolean[] ans = ladice(n, l, a);
        StringBuilder sb = new StringBuilder(); // Fast io to give your program more time
        for(int i = 0; i < n; i++){
            if(ans[i]) sb.append("LADICA\n");
            else sb.append("SMECE\n");
        }
        System.out.print(sb);
    }
}