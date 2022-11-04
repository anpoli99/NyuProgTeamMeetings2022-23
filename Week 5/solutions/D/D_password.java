import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is Main if you use this template
    public static void main(String[] args) throws Exception{

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(in.readLine());
        
        // There are a lot of approaches to this problem; the constraints are small enough
        // that you can iterate over all the palindromes to find the smallest. But it becomes
        // simpler to write if we just precompute them, and use a set to find the smallest
        TreeSet<Integer> all_palindromes = new TreeSet<Integer>();
        for(int i = 100; i <= 999; i++){
            String s = Integer.toString(i);
            String t = new StringBuilder(s).reverse().toString();
            s += t;
            all_palindromes.add(Integer.parseInt(s));
        }
        while(qr-- > 0){
            int k = Integer.parseInt(in.readLine());
            int best = Integer.MAX_VALUE;
            int best_palindrome = -1;
            Integer it = all_palindromes.ceiling(k);
            if(it != null){
                best = it - k;
                best_palindrome = it;
            }
            it = all_palindromes.floor(k);
            if(it != null && k - it <= best){
                best = k - it;
                best_palindrome = it;
            }
            System.out.println(best_palindrome);
        }
    }
}