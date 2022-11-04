import java.util.*;
import java.io.*;

class Main{
    // Make sure the class name is Main if you use this template
    static String substringswitcheroo(String a, String b){
        // Here's an example of where hashing can be useful:
        // We can hash the number of times each character appears in a substring
        // of a, and then check if the same substring of b has the same hash.
        final int p = 1319; // any prime number > N is fine
                            // if it's less than N we could get collisions
        final int m1 = (int)1e9 + 7, m2 = (int)1e9 + 9; // two large primes

        long[] v1 = new long[256], v2 = new long[256];
        v1[0] = v2[0] = 1;
        for(int i = 1; i < 256; i++){
            v1[i] = (v1[i - 1] * p) % m1;
            v2[i] = (v2[i - 1] * p) % m2;
        }
        int n = a.length();
        HashSet<Long> hashes = new HashSet<>();
        for(int i = 0; i < n; i++){
            long h1 = 0, h2 = 0;
            for(int j = i; j < n; j++){
                h1 = (h1 + v1[b.charAt(j)]) % m1;
                h2 = (h2 + v2[b.charAt(j)]) % m2;
                hashes.add((h1 << 32) + h2);
            }
        }
        int idx = 0, len = 0;
        for(int i = 0; i < n; i++){
            long h1 = 0, h2 = 0;
            for(int j = i; j < n; j++){
                h1 = (h1 + v1[a.charAt(j)]) % m1;
                h2 = (h2 + v2[a.charAt(j)]) % m2;
                if(hashes.contains((h1 << 32) + h2)){
                    if(j - i + 1 > len){
                        len = j - i + 1;
                        idx = i;
                    }
                }
            }
        }
        if(len == 0) return "NONE";
        return a.substring(idx, idx + len);
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            String a = br.readLine(), b = br.readLine();
            System.out.println(substringswitcheroo(a, b));
        }
    }
}