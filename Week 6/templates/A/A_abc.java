import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!

    // input format: 'a' is an array of length 3, the 3 numbers in the first line
    // return the answer as an array of 3 numbers
    static int[] abc(int[] a, String s){
       // your code here
       return new int[]{0, 0, 0};
    }

    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int[] a = new int[3];
        for(int i = 0; i < 3; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        String s = f.readLine();
        int[] b = abc(a, s);
        for(int i = 0; i < 3; i++){
            System.out.print(b[i] + " ");
        }
        System.out.println();
    }
    
}