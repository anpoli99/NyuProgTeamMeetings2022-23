import java.io.*;
import java.util.*;

class Main{  
    // Make sure the class name is Main if you use this template

    // Input format: x[0],y[0] = start, x[n - 1],y[n - 1] = end
    static boolean kastenlauf(int n, int[] x, int[] y){
        // Your code here
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            int n = Integer.parseInt(br.readLine());
            n += 2; // 0 = begin, n + 1 = end
            int[] x = new int[n];
            int[] y = new int[n];
            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                x[i] = Integer.parseInt(st.nextToken());
                y[i] = Integer.parseInt(st.nextToken());
            }
            System.out.println(kastenlauf(n,x,y) ? "happy" : "sad");
        }
    }
}