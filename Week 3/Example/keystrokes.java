import java.io.*;
import java.util.*;

class Main{

    static int[] prev, next;
    static char[] symbol;
    static void remove(int k){
        next[prev[k]] = next[k];
        prev[next[k]] = prev[k];
    }
    static void insert(int k, int x){
        next[x] = next[k];
        prev[next[k]] = x;
        next[k] = x;
        prev[x] = k;
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        prev = new int[s.length() + 1];
        next = new int[s.length() + 1];
        symbol = new char[s.length() + 1];
        int cursor = 0;
        int nextPointer = 1;
        Arrays.fill(next, -1);
        Arrays.fill(prev, -1);

        // We need to be careful not to give a negative index, so we'll have a node representing the back of the list too
        next[0] = s.length();
        prev[s.length()] = 0;

        for(char c : s.toCharArray()){
            if(c == 'L'){
                if(prev[cursor] != -1) {
                    cursor = prev[cursor];
                }
            }else if(c == 'R'){
                if(next[cursor] != -1) {
                    cursor = next[cursor];
                }
            }else if(c == 'B'){
                if(prev[cursor] != -1){
                    remove(prev[cursor]);
                    cursor = prev[cursor];
                }
            }else{
                insert(cursor, nextPointer);
                symbol[nextPointer] = c;
                cursor = nextPointer;
                nextPointer++;
            }
        }
        StringBuilder output = new StringBuilder();
        cursor = next[0];
        while(cursor != -1){
            output.append(symbol[cursor]);
            cursor = next[cursor];
        }
        System.out.println(output);
        
    }
}
