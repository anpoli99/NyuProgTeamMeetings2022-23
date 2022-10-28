import java.io.*;
import java.util.*;

class Main{
    // The brute force approach here is just to handle each query with a list.
    // We can traverse the whole list, and process the person in the query when we find them
    // This is O(N * Q * |S|) which is fine for this problem
    // (N = # of people, Q = # of queries, |S| = length of each string)
    // If we had harsher constraints, we would need to use the other approach
    
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        ArrayList<String> line = new ArrayList<>();
        for(int i = 0; i < n; i++){
            line.add(in.readLine());
        }
        int q = Integer.parseInt(in.readLine());
        while(q-- > 0){
            StringTokenizer st = new StringTokenizer(in.readLine());
            String command = st.nextToken();
            if(command.equals("cut")){
                String x = st.nextToken(), y = st.nextToken();
                ArrayList<String> nextLine = new ArrayList<>();
                for(String s : line){
                    if(s.equals(x)){
                        nextLine.add(y);
                    }
                    nextLine.add(s);
                }
            }else{ // command.equals("leave")
                String x = st.nextToken();
                line.remove(x); // O(N) operation
            }
        }

        StringBuilder output = new StringBuilder();
        for(String s : line){
            output.append(s);
            output.append('\n');
        }
        System.out.print(output);
    }
}
