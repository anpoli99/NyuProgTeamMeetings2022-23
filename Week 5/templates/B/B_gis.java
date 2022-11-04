import java.io.*;
import java.util.*;

class Main{
    // Make sure you have the class name as Main if you use this template

    static ArrayList<Integer> greedily_increasing_subsequence(int n, ArrayList<Integer> a){
        // Your code to find the greedily increasing subsequence goes here
        // Replace this line with your code
        return new ArrayList<Integer>();
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Faster IO to give your program as much time as possible
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            a.add(Integer.parseInt(st.nextToken()));
        }
        ArrayList<Integer> ans = greedily_increasing_subsequence(n, a);
        System.out.println(ans.size());
        StringBuilder sb = new StringBuilder(); // Faster IO to give your program as much time as possible
        for(int i = 0; i < ans.size(); i++){
            sb.append(ans.get(i));
            sb.append(" ");
        }
        System.out.println(sb);
    }
}