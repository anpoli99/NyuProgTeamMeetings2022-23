import java.io.*;
import java.util.*;

class Main{

    // For this problem, I'm only including the Fast I/O methods for the template.
    // The time limit is pretty tight for this problem; 
    // You will probably TLE if you don't use them.
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // Read each line one at at a time and split w/ StringTokenizer
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
        /*
        Feel free to put any preprocessing you want here
        */
        StringBuilder output = new StringBuilder();
        // You should be calling output.append(x) for each output line.
        while(q-- > 0){ 
            // Answer each query here
        }
        // Then we can just print the output at the end
        System.out.print(output); 

    }
}
