import java.io.*;
import java.util.*;

class Main{
    // Make sure your class name is Main when you submit if using this template!
    static BufferedReader br;
    // Call this function to query the judge
    // Returns the time it took to check the password or 0 if the password is correct
    static int query(String q) throws IOException{
        System.out.println(q); 
        System.out.flush(); // ALWAYS remember to do this on an interactive problem!
        String response = br.readLine();
        if(response.equals("ACCESS GRANTED")) return 0;
        return extract_time(response);
    }
    // The judge returns in the format: "ACCESS DENIED (time ms)"
    // This function should extract the time from the string
    static int extract_time(String s){
        // I left this implementation to you
        // A recommendation: I'd advise testing it on its own first then solving the problem
        return -1;
    }
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        // add any auxilary variables you need here
        while(true){
            String guess;
            // Your code here to generate a guess
            int time = query(guess);
            if(time == 0) 
                break; // You found the password!
            // Your code here to update parameters of the next guess
        }
    }
}