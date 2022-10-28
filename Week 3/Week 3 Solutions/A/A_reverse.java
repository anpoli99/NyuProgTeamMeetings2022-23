import java.io.*;
import java.util.*;

class Main{
    // If you submit with this template, make sure the class name is Main!

    // You don't need a Stack to solve this problem!
    // But since it's data structures week, I'll use one anyway.
    static int[] reverse(int[] a){
        int[] b = new int[a.length];
        Stack<Integer> s = new Stack<Integer>();
        for(int i = 0; i < a.length; i++){
            s.push(a[i]);
        }
        for(int i = 0; i < a.length; i++){
            b[i] = s.pop();
        }
        return b;
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
