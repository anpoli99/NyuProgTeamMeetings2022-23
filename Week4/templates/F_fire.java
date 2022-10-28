import java.io.*;
import java.util.*;
import java.awt.Point;

class Main{
    // Make sure when you submit, the class name is Main

    // input format: grid[i][j] is the value of the cell at row i, column j
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1}; // You may want to use these arrays in your implementation
                                    // You may also want to use java.awt.Point

    // return the minimum number of steps to escape the fire, or -1 if it's impossible
    static int fire(int rows, int cols, char[][] grid){
        // Your code to solve the problem goes here
        return -1; // This is a placeholder 
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(in.readLine());
        for(int t = 1; t <= q; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int cols = Integer.parseInt(st.nextToken()), rows = Integer.parseInt(st.nextToken());
            char[][] grid = new char[rows][cols];
            for(int i = 0; i < rows; i++){
                grid[i] = in.readLine().toCharArray();
            }
            int ans = fire(rows, cols, grid);
            if(ans == -1){
                System.out.println("IMPOSSIBLE");
            }else{
                System.out.println(ans);
            }
        }
    }
}