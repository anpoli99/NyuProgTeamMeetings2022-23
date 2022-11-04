import java.util.*;
import java.io.*;

class Main{
    // Make sure you have the class name as Main if you use this template
    
    // Each entry in lines is a line of the input
    // You can split by the spaces using String.split(" ")
    static ArrayList<String> addingWords(ArrayList<String> lines){
        ArrayList<String> result = new ArrayList<String>();
        // Your code to process the lines goes here
        return result;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> lines = new ArrayList<String>();
        String line;
        while((line = in.readLine()) != null){
            if(line.equals("#")) break; // This is a useful way to debug
            lines.add(line);
        }
        ArrayList<String> result = addingWords(lines);
        for(String l : result){
            System.out.println(l);
        }
    }
}