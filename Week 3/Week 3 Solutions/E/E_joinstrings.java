import java.io.*;
import java.util.*;

class Main{
    // format: 's' contains all 'n' strings; 1 indexed (because 'a'/'b' are 1-indexed in the original input)
    // 'a'/'b' contain (n - 1) strings, 1 indexed for consistency, representing the strings that are joined  
    static String joinStrings(int n, String[] s, int[] a, int[] b){
         // First we'll find the order of the indices in the final string, then we can concatenate them at the end
        // To do this, notice that when we concatenate two strings (i)(j), it becomes one string
        // beginning with 'i' and ending with 'j'
        // So the only thing we need to know to join two strings is which original string was 
        // first and which was last.

        int[] next = new int[n + 1]; // next[i] will store the index of the next string (the one that gets concatenated to the back of 'i')
        int[] last = new int[n + 1]; // last[i] will store the last string concatenated to 'i'
                                     // for example, if (1 2) was concatenated to (3 4), then next[1] = 2 and last[1] = 4

        boolean[] is_beginning = new boolean[n + 1]; // is_beginning[i] will store whether or not 'i' is the beginning of a string
                                                   // we'll remove each one that isn't when we append it to another string
        for(int i = 1; i <= n; i++){
            last[i] = i; // initially, each string is its own last string
            is_beginning[i] = true; // initially, each string is its own beginning
        }
        for(int i = 1; i < n; i++){
            int x = a[i], y = b[i];
            next[last[x]] = y;  // append 'y' to the end of 'x'
            last[x] = last[y];  // last[y] is now the last string concatenated to 'x'
            is_beginning[y] = false; // 'y' is no longer the beginning of a string
        }

        // Now we can find the beginning of the final string
        int curr = 1;
        while(!is_beginning[curr]){
            ++curr;
        }

        // Build the answer
        StringBuilder ans = new StringBuilder();
        while(curr != 0){
            ans.append(s[curr]);
            curr = next[curr];
        }
        return ans.toString();
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String[] s = new String[n + 1];
        for(int i = 1; i <= n; i++){
            s[i] = in.readLine();
        }
        int[] a = new int[n], b = new int[n];
        for(int i = 1; i < n; i++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(joinStrings(n, s, a, b));
    }
}
