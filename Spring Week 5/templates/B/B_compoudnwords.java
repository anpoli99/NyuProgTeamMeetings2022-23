import java.io.*;
import java.util.*;

public class Main {
    
    static ArrayList<String> compoundWords(ArrayList<String> words){
        // Your code here
        return new ArrayList<String>();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        ArrayList<String> inputList = new ArrayList<String>();
        while (in.ready()) {
            String s = in.readLine();
            if(s.equals("###") ) break; // I find it helpful to have a line like this when debugging from the terminal
            st = new StringTokenizer(s);
            while (st.hasMoreTokens()) {
                inputList.add(st.nextToken());
            }
        }
        ArrayList<String> outputList = compoundWords(inputList);
        StringBuilder sb = new StringBuilder();
        for (String s : outputList) {
            sb.append(s);
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }
}