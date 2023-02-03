import java.io.*;
import java.util.*;

class Main{
    // Make sure your class name is Main when you submit if using this template!

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int time_solved;
        int score = 0, penalty = 0;
        // Add any auxiliary variables you need here
        while(true){
            st = new StringTokenizer(br.readLine());
            time_solved = Integer.parseInt(st.nextToken());
            if(time_solved == -1) break;
            char problem = st.nextToken().charAt(0);
            String correct = st.nextToken();
            if(correct.equals("right")){
                // Your code here
            }else{
                // Your code here
            }
        }
        System.out.println(score + " " + penalty);
    }
}
