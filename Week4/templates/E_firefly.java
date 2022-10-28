import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    
    // input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
    // return a pair with the optimal # of obstacles and the # of levels where that is possible
    // return this pair as an int[] of length 2

    // note that the firefly cannot fly at a height of 0
    static int[] firefly(int n, int h, ArrayList<Integer> a, ArrayList<Integer> b){
        // note that initially, n = a.size() + b.size()
        return new int[]{-1, -1}; // This is a placeholder
    }

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            int x = Integer.parseInt(in.readLine());
            if(i % 2 == 0) a.add(x);
            else b.add(x);
        }
        int[] ans = firefly(n, h, a, b);
        System.out.println(ans[0] + " " + ans[1]);
    }
}