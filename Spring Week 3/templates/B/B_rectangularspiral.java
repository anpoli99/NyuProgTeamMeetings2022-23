import java.util.*;
import java.io.*;

public class Main{
    // Input format: x,y = queried point
    // Return: ArrayList of ints of the shortest path from (0,0) to (x,y)
    //         return empty ArrayList if no path exists
    static ArrayList<Integer> solve(int x, int y){
        return new ArrayList<Integer>(); // This is a placeholder
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= qr; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            tc = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            System.out.print(tc + " ");
            ArrayList<Integer> ans = solve(x,y);
            if(ans.size() == 0){
                System.out.println("NO PATH");
            }else{
                System.out.print(ans.size() + " ");
                for(int i = 0; i < ans.size(); i++){
                    System.out.print(ans.get(i) + " ");
                }
                System.out.println();
            }
        }
    }
}