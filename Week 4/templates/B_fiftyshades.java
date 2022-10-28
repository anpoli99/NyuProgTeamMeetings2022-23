import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    static boolean fiftyShades(String s){
        // Your code to check if the string is valid goes here
        return false; // This is a placeholder
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(in.readLine());
        int total = 0;
        for(int i = 0; i < q; i++){
            if(fiftyShades(in.readLine())){
                total++;
            }
        }
        if(total == 0){
            System.out.println("I must watch Star Wars with my daughter");
        }else{
            System.out.println(total);
        }
    }
}