import java.io.*;
import java.util.*;

class Main{
    // Make sure your class name is Main when you submit if using this template!
    static BufferedReader br;
    // returns: -1 if the number is correct, 0 if the number is lower, 1 if the number is higher
    static int query(int x) throws IOException{
        System.out.println(x); 
        System.out.flush(); // ALWAYS remember to do this on an interactive problem!
        String s = br.readLine();
        if(s.equals("correct")) return -1;
        if(s.equals("lower")) return 0;
        return 1;
    }
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        int ans = -1; // This is a placeholder
        // Your code here
        System.out.println(ans); // You should still quit early if you find the answer
    }
}
        