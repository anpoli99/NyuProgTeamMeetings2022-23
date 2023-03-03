import java.io.*;
import java.util.*;

class Main{

    static boolean phonelist(int n, String[] s){
        // Your code here
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qrys = Integer.parseInt(br.readLine());
        for(int tc = 0; tc < qrys; tc++){
            int n = Integer.parseInt(br.readLine());
            String[] s = new String[n];
            for(int i = 0; i < n; i++) {
                s[i] = br.readLine();
            }
            if(phonelist(n, s)) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}