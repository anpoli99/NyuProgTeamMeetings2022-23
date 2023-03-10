import java.io.*;
import java.util.*;

public class Main {
    
    static String sim(String line){
        // Your code here
        return "";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            String line = in.readLine();
            System.out.println(sim(line));
        }
    }
}