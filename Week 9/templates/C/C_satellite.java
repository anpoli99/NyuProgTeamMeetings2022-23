import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!

    static double communicationsSatellite(int n, int[] x, int[] y, int[] r){
        // Input format: n is the number of satellite dishes
        // x,y,r are arrays of length n describing each satellite dish
        return -1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] x = new int[n];
        int[] y = new int[n];
        int[] r = new int[n];
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            r[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(communicationsSatellite(n, x, y, r));
    }
}