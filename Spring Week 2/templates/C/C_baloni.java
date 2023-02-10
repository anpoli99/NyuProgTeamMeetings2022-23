import java.io.*;
import java.util.*;

public class Main{
    // Input: N and A, where A is an array of N integers
    // Output: The minimum number of darts to pop all balloons
    public static int baloni(int N, int[] A){
        //Your code here
        return 0;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            A[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(baloni(N,A));
    }
}