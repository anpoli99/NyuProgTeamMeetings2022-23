import java.util.*;
import java.io.*;

public class Main{
    // Input format: h,r,da,dw as specified in the problem statement
    // Return: the optimal height of water in the bottle
    static double solve(int h, int r, int da, int dw){
        return -1; // This is a placeholder
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int da = Integer.parseInt(st.nextToken());
        int dw = Integer.parseInt(st.nextToken());
        System.out.println(String.format("%.10f", solve(h,r,da,dw)));
    }
}