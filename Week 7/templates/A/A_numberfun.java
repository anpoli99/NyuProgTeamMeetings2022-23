import java.io.*;
import java.util.*;

class Main{  
    // Make sure the class name is Main if you use this template

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            // Your code to check if a valid equation exists goes here
        }
    }
    
}