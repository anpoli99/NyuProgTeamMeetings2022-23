import java.util.*;
import java.io.*;

public class Main{
    static class Point{
        int x,y;
        Point(){x = y = 0;}
        Point(int x, int y){this.x = x; this.y = y;}
    }
    // Input format: c = Your location
    // n = # of enemy spies
    // cen[i] = Location of enemy spy i
    // rad[i] = Radius of enemy spy i
    // Output: Return maximum communication range as specified in the problem statement
    static int solve(Point c, int n, Point[] cen, int[] rad){
        return -1; // This is a placeholder
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Point c = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        int n = Integer.parseInt(st.nextToken());
        Point[] cen = new Point[n];
        int[] rad = new int[n];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            cen[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            rad[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(solve(c,n,cen,rad));
    }
}