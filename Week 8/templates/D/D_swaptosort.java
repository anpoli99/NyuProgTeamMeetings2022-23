import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!

    // Input: 'a' is 2d array of size [k][2] representing the k swaps
    // Output: True if a descending list of size n can be sorted with the swaps, false otherwise
    static boolean swapToSort(int n, int k, int[][] a){
        // Your code goes here
        return false; // This is a placeholder
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] a = new int[k][2];
        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());
            a[i][0] = Integer.parseInt(st.nextToken());
            a[i][1] = Integer.parseInt(st.nextToken());
        }
        System.out.print(swapToSort(n, k, a) ? "Yes" : "No");
    }
}