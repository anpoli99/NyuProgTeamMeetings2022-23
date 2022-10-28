import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    static boolean fiftyShades(String s){
        s = s.toLowerCase();
        if(s.contains("pink") || s.contains("rose")){
            return true;
        }
        return false;
        // It's helpful to know standard libraries :)
        // We could also do this manually:
        /*
        char[] c = s.toCharArray(); // easier to manipulate a char array
        for(int i = 0; i < c.length; i++){
            if(c[i] >= 'A' && c[i] <= 'Z'){
                c[i] += 'a' - 'A'; // convert to lowercase
            }
        }
        s = new String(c); // convert back to a string
        for(int i = 0; i + 4 <= s.length(); i++){
            if(s.substring(i, i + 4).equals("pink") || s.substring(i, i + 4).equals("rose")){
                return true;
            }
        }
        return false;
        */
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