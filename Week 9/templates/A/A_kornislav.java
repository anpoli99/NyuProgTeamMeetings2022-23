import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!

    static int kornislav(int[] a){
        // Input format: 'a' is an array of 4 integers
        return -1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int[] a = new int[4];
        for(int i = 0; i < 4; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(kornislav(a));
    }
}