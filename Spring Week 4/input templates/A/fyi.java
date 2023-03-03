import java.io.*;
import java.util.*;

class Main{

    static boolean fyi(String s){
        // Your code here
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if(fyi(s)) System.out.println("1");
        else System.out.println("0");
    }
}