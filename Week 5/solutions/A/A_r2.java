import java.io.*;
import java.util.*;

class Main{
    // Make sure you have the class name as Main if you use this template
    static int r2(int r1, int s){
        int diff = s - r1;
        return s + diff;
    }

    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r1 = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        System.out.println(r2(r1, s));
    }

}