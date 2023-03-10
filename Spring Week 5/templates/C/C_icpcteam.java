import java.io.*;
import java.util.*;

public class Main {
    
    static int icpcteam(int n, int[] students){
        // Your code here
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            int n = Integer.parseInt(in.readLine());
            int[] students = new int[n];
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < n; j++) {
                students[j] = Integer.parseInt(st.nextToken());
            }
            System.out.println(icpcteam(n, students));
        }
    }
}