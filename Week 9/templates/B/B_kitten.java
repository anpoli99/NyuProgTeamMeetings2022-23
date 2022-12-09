import java.io.*;
import java.util.*;

class Main{
    // Make sure the class name is Main if you use this template!

    static ArrayList<Integer> kitten(ArrayList<ArrayList> a, int k){
        // Input format: k is the kitten's number
        // 'a' is an array of ArrayLists, where each a[i] has a list of branches 
        // described in the problem statement
        return null;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(in.readLine());
        ArrayList<ArrayList> a = new ArrayList<ArrayList>();
        while(true){
            StringTokenizer st = new StringTokenizer(in.readLine());
            ArrayList<Integer> cur = new ArrayList<Integer>();
            cur.add(Integer.parseInt(st.nextToken()));
            if(cur.get(0) == -1) break;
            while(st.hasMoreTokens()){
                cur.add(Integer.parseInt(st.nextToken()));
            }
            a.add(cur);
        }
        System.out.println(kitten(a, k));
        
    }
}