import java.io.*;
import java.util.*;

class Main{
    // format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
    // 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
    static String joinStrings(int n, String[] s, int[] a, int[] b){
        /*
        Your code here; You should return the final concatenated string.
        */
        return ""; // This is just a placeholder.
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String[] s = new String[n + 1];
        for(int i = 1; i <= n; i++){
            s[i] = in.readLine();
        }
        int[] a = new int[n], b = new int[n];
        for(int i = 1; i < n; i++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(joinStrings(n, s, a, b));
    }
}
