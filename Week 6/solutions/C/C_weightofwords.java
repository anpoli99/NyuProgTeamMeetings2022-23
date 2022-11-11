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
        if(i == 0){
            return j == 0;
        }
        if(j < 0) return false;
        if(visited[i][j]){
            // visiting a state twice can't help us! if it returned false the first time,
            // it will return false the second time
            return false;
        }
        visited[i][j] = true;
        for(int k = 1; k <= 26; k++){
            if(solve(i - 1, j - k)){
                ans += (char)('a' + k - 1);
                return true;
            }
        }
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