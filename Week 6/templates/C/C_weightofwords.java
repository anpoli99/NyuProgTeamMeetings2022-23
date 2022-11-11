import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is set to main if you use this template!    
    

    // There's some non DP approaches to this problem
    // If you wanted to get started w/ a DP approach, I'd recommend something like this:
    static final int L = 40 + 5, W = 1000 + 5;
    static boolean[][] visited = new boolean[L][W];
    static String ans = "";
    static boolean solve(int i, int j){
        // TODO: implement this function
        // Return true if we find a word of length i with weight j
        return false;
    }
    static String weightofwords(int l, int w){
        if(!solve(l, w)){
            return "impossible";
        }
        return ans;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int l = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        System.out.println(weightofwords(l, w));
    }
}