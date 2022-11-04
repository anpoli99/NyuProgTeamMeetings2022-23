import java.util.*;
import java.io.*;


class Main{
    // Make sure you have the class name as Main if you use this template

    static int downtime(int n, int k, ArrayList<Integer> a){
        // Your code to find the minimum number of servers goes here
        // Replace this line with your code
        return -1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Faster IO to give your program as much time as possible
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            a.add(Integer.parseInt(br.readLine()));
        }
        System.out.println(downtime(n, k, a));
    }
}