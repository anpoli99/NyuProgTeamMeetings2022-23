import java.io.*;
import java.util.*;

class Main{
    // If you submit with this template, make sure the class name is Main!

    // helper function to format the output
    static String formatOutput(Deque<Integer> dq){
        // Don't use += for strings! It's O(n^2) and will TLE on this problem.
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        while(!dq.isEmpty()){
            sb.append(dq.pollFirst());
            if(!dq.isEmpty()){
                sb.append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }
    static String intergerLists(String commands, ArrayList<Integer> a){
        //  The basic idea here is we'll use a boolean to track if the list is reversed
        // We'll store the data in a deque, and if the list is reversed, we can remove from the back instead

        Deque<Integer> dq = new ArrayDeque<Integer>();
        for(int i = 0; i < a.size(); i++){
            dq.addLast(a.get(i));
        }
        boolean reversed = false;
        for(char c : commands.toCharArray()){
            if(c == 'R'){
                reversed = !reversed;
            }else{
                if(dq.isEmpty()){
                    return "error";
                }
                if(reversed){
                    dq.pollLast();
                }else{
                    dq.pollFirst();
                }
            }
        }
        if(reversed){
            // We need to reverse the deque
            Deque<Integer> temp = new ArrayDeque<Integer>();
            while(!dq.isEmpty()){
                temp.addFirst(dq.pollFirst());
            }
            dq = temp;
        }
        return formatOutput(dq);
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int trials = Integer.parseInt(in.readLine());
        while(trials-- > 0){
            String commands = in.readLine();
            int n = Integer.parseInt(in.readLine());
            String inputValues = in.readLine();
            inputValues = inputValues.substring(1, inputValues.length() - 1); // remove the brackets
            String[] input = inputValues.split(",");
            ArrayList<Integer> a = new ArrayList<Integer>();
            for(int i = 0; i < n; i++){
                a.add(Integer.parseInt(input[i]));
            }
            System.out.println(intergerLists(commands, a)); 
        }
    }
}
