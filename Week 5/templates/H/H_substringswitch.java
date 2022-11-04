import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is Main if you use this template
    static String substringswitcheroo(String a, String b){
        // Your code to find the largest possible substring goes here
        return "NONE"; // Replace this line with your code
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            String a = br.readLine(), b = br.readLine();
            System.out.println(substringswitcheroo(a, b));
        }
    }
}