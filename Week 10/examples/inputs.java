import java.io.*;
import java.util.*;


class Main{
    public static void main(String args[]) throws IOException{
        In in = new In();
        // I wrote this In class to make it easier to read input in Java
        // Scanner isn't great because it's slower
        // BufferedReader + StringTokenizer is fastest, but gets messy
        // With this class, you can read everything very quickly without making a mess
        // I'd highly recommend using this class for competitive programming


        // Read an integer
        int x = in.pint(); // pint() stands for "parse int"
        // similarly, pdbl() for "parse double", plng() for "parse long", etc.
        // you can change the concise names if you don't like them

        // Read 5 integers on the same line
        in.split(); // Split the line into tokens (separated by spaces)
                    // If you don't do this, it will read the whole line as one token
                    // and if you try to parse it as an int, it will throw an error.
        int[] arr = new int[5];
        for(int i = 0; i < 5; i++) arr[i] = in.pint();

        // Read 5 integers on 5 different lines
        for(int i = 0; i < 5; i++) arr[i] = in.pint(); // No need to split

        // Read a double
        double y = in.pdbl();

        // Read a whole line
        String line = in.readLine();

        // Read 5 strings on one line
        in.split();
        String[] strs = new String[5];
        for(int i = 0; i < 5; i++) strs[i] = in.pstr();

        // Read a character (destroys the rest of the string)
        char c = in.pchr();

        // Let's say we have our output ready
        // We can just use System.out.println() to print it
        for(int i = 0; i < 5; i++) System.out.print(arr[i] + " "); // just print() if you don't want a newline
        System.out.println(); // print a newline

        // If we need to print a lot of stuff, we can use StringBuilder
        // It's much faster than System.out.println()
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 5; i++) {
            sb.append(arr[i]);
            sb.append(" ");
        }
        System.out.println(sb.toString()); // print the StringBuilder

        // Let's say I wanted to read until the end of the file
        // I can use in.ready() to check if there's more input

        /*
        while(in.ready()) {
            // Read a line
            String s = in.readLine();
            // Do something with s
        }
        */
    }
}
// If we just keep the In class at the bottom, we don't have to worry about it.
// As long as our main class is set to Main, we can just run the entire file
// and it will work.
class In{
    BufferedReader in;
    StringTokenizer st = new StringTokenizer("");
    public In(){
        in = new BufferedReader(new InputStreamReader(System.in));
    }
    
    int pint() throws IOException{
        if(st.hasMoreTokens()) {return Integer.parseInt(st.nextToken());}
        else {return Integer.parseInt(in.readLine());}
    }
    double pdbl() throws IOException{
        if(st.hasMoreTokens()) {return Double.parseDouble(st.nextToken());}
        else {return Double.parseDouble(in.readLine());}
    }
    long plng() throws IOException{
        if(st.hasMoreTokens()) {return Long.parseLong(st.nextToken());}
        else {return Long.parseLong(in.readLine());}
    }
    char pchr() throws IOException{
        if(st.hasMoreTokens()) {return st.nextToken().charAt(0);}
        else {return in.readLine().charAt(0);}
    }
    String pstr() throws IOException{
        if(st.hasMoreTokens()) {return st.nextToken();}
        else {return in.readLine();}
    }
    String readLine() throws IOException{
        return in.readLine();
    }
    boolean ready() throws IOException {return in.ready();} 
    boolean readyN() throws IOException{return in.ready() || st.hasMoreTokens();}
    boolean tokens() {return st.hasMoreTokens();}
    void split() throws IOException{st = new StringTokenizer(in.readLine());}
    void skip() throws IOException{in.readLine();}
}