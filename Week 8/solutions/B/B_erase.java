import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!
    static boolean eraseSuccessfully(int n, String s, String t){
        // Key idea: 'erasing' twice is the same as not erasing at all
        n &= 1; // n = n % 2
        if(n == 0){
            return s.equals(t);
        }else{
            for(int i = 0; i < s.length(); i++){
                if(s.charAt(i) == t.charAt(i)){
                    return false;
                }
            }
            return true;
        }
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