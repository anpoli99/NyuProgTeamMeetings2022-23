import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!
    static int doublepassword(String s, String t){
        // The input is small enough that we can just brute force it
        int ans = 0;
        for(int i = 0; i < 10000; i++){
            String p = Integer.toString(i);
            while(p.length() < 4) p = "0" + p;
            boolean okay = true;
            for(int j = 0; j < 4; j++){
                char x = p.charAt(j);
                if(s.charAt(j) != x && t.charAt(j) != x) okay = false;
            } 
            if(okay) ans++;
        }
        return ans;
        // alternate solution
        // int ct = 0;
        // for(int i = 0; i < 4; i++) ct += (s[i] != t[i]);
        // return (1 << ct); // 2^{mismatched digits}
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        System.out.println(doublepassword(s, t));
    }
}