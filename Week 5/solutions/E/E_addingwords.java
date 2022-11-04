import java.util.*;
import java.io.*;

class Main{
    // Make sure you have the class name as Main if you use this template
    
    static final int UNKNOWN = 0x7fffffff;
    // Each entry in lines is a line of the input
    // You can split by the spaces using String.split(" ")
    static ArrayList<String> addingWords(ArrayList<String> lines){
        ArrayList<String> result = new ArrayList<String>();
        HashMap<String, Integer> variables = new HashMap<String, Integer>();
        HashMap<Integer, String> values = new HashMap<Integer, String>();
        for(String line : lines){
            String[] words = line.split(" ");
            if(words[0].equals("clear")){
                variables.clear();
                values.clear();
            }else if(words[0].equals("def")){
                String var = words[1];
                int value = Integer.parseInt(words[2]);
                if(variables.containsKey(var)){
                    values.remove(variables.get(var));
                }
                variables.put(var, value);
                values.put(value, var);
            }else{ // word == "calc"
                String equation = line.substring(5); // It wants the whole equation too, but that's just part of the original line
                boolean sub = false;
                int value = 0;
                for(int i = 1; i < words.length; i += 2){
                    String var = words[i];
                    if(!variables.containsKey(var)){
                        value = UNKNOWN;
                        break;
                    }
                    if(sub){
                        value -= variables.get(var);
                    }else{
                        value += variables.get(var);
                    }
                    sub = words[i + 1].equals("-");
                }
                if(!values.containsKey(value)){
                    value = UNKNOWN;
                }
                if(value == UNKNOWN){
                    result.add(equation + " unknown");
                }else{
                    result.add(equation + " " + values.get(value));
                }
            }
        }
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