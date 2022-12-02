import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!
    static boolean eraseSuccessfully(int n, String s, String t){
        // Your code goes here
        return false; // This is a placeholder
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        String t = br.readLine();
        System.out.print("Deletion ");
        System.out.println(eraseSuccessfully(n, s, t) ? "succeeded" : "failed");
    }

}