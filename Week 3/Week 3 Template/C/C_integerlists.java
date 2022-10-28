import java.io.*;
import java.util.*;

class Main{
   
    static String intergerLists(String commands, ArrayList<Integer> a){
        // Your code here; You should return "error" if the commands are invalid.
        //  Otherwise return the resulting output values formatted according to the problem statement.
        return "error"; // This is just a placeholder.
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
