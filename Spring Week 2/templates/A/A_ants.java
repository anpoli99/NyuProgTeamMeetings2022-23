import java.io.*;
import java.util.*;

public class Main{
    // Parameters:
    // Input N, L as described in the problem statement
    // positions, an array of length N containing the positions of the ants
    // Output:
    // Array of two integers as described in the problem statement
    public static int[] ants(int N, int L, int[] positions){
        int[] result = new int[2];
        // Your code here
        return result;
    }

    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int Q = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < Q; i++){
            int L = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            int[] positions = new int[N];
            for(int j = 0; j < N; j++){
                positions[j] = Integer.parseInt(st.nextToken());
            }
            int[] result = ants(N, L, positions);
            System.out.println(result[0] + " " + result[1]);
        }
    }
    static int parseInt(StringTokenizer st, BufferedReader br) throws IOException{
        while(!st.hasMoreTokens()){
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
}