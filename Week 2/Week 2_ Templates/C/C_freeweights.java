import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
    static int freeWeights(int n, ArrayList<Integer> a, ArrayList<Integer> b){
        // Your code to find the minimum weight required goes here
        return -1;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        
        StringTokenizer st = new StringTokenizer(in.readLine());
        for(int i = 0; i < n; i++){
            a.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i < n; i++){
            b.add(Integer.parseInt(st.nextToken()));
        }
        
        System.out.println(freeWeights(n, a, b));
    }
}