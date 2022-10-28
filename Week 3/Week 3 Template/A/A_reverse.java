import java.io.*;
import java.util.*;

class Main{
    // If you submit with this template, make sure the class name is Main!

    static int[] reverse(int[] a){
        /*
        Your code to reverse the array a goes here.
        */
        return new int[0]; // This is just a placeholder.
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(in.readLine());
        }
        int[] b = reverse(a);

        StringBuilder sb = new StringBuilder(); // I'm using fast I/O methods just to give your solution as much time as possible.
        for(int i = 0; i < n; i++){
            sb.append(b[i]); // This is significantly faster because we don't flush the buffer every time.
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
