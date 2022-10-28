import java.io.*;
import java.util.*;

class Main{
    // If you submit with this template, make sure the class name is Main!

    // You don't need a queue to solve this problem!
    // But since it's data structures week, I'll use one anyway.
    static String apaxiaaans(String s){
        Queue<Character> q = new LinkedList<>();
        for(char c : s.toCharArray()){
            q.add(c);
        }
        // It doesn't matter for this problem, but '+=' is very slow for Strings.
        // It's good form to use StringBuilder; some problems will require it.
        StringBuilder answer = new StringBuilder();
        while(!q.isEmpty()){
            char c = q.remove();
            if(q.isEmpty() || c != q.peek()){
                answer.append(c);
            }
        }
        return answer.toString();
    }
    public static void main(String[] args) throws IOException{
    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        System.out.println(apaxiaaans(s));
    }
}
