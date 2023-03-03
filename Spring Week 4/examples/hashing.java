import java.util.*;    
import java.io.*;

class Main{
    /*
    We'll be using this rolling hash struct to solve the problem
    https://kattis.com/problems/hashing. It's written to be generic
    so you can copy and paste it into your own code, whenever you
    need a rolling hash.
    */
    static final int mod = (int)1e9 + 87; // A prime number
    static final int p1 = 131, p2 = 499; // Two different primes; greater than size of alphabet (128 for strings)
    static final int N = (int)1e6 + 5; // Longer than the longest string
    static int modpow(int a, int b){
        int res = 1;
        while(b > 0){
            if((b & 1) == 1) res = (int)((1L * res * a) % mod);
            a = (int)((1L * a * a) % mod);
            b >>= 1;
        }
        return res;
    }

    static long[] power1, power2;
    static long[] invp1, invp2;
    // Precomputing hashes is a lot faster; save log(n) time every time we use it.
    static boolean pre_computed = false;
    static void precompute(){
        power1 = new long[N];
        power2 = new long[N];
        power1[0] = power2[0] = 1;
        for(int i = 1; i < N; i++){
            power1[i] = (power1[i - 1] * p1) % mod;
            power2[i] = (power2[i - 1] * p2) % mod;
        }
        invp1 = new long[N];
        invp2 = new long[N];
        invp1[N - 1] = modpow((int)power1[N - 1], mod - 2); // Modular inverse formula: x^(-1) == x^(m - 2) mod m
        invp2[N - 1] = modpow((int)power2[N - 1], mod - 2); // (Iff m is prime)
        for(int i = N - 2; i >= 0; i--){ // Compute the largest first, then just multiply by p1/p2 to get lower powers
            invp1[i] = (invp1[i + 1] * p1) % mod;
            invp2[i] = (invp2[i + 1] * p2) % mod;
        }
        pre_computed = true;
    }
    static class rolling_hash{
        long[] hash1, hash2;
        rolling_hash(String s){
            if(!pre_computed) precompute();
            int n = s.length();
            hash1 = new long[n + 1];
            hash2 = new long[n + 1];
            for(int i = 0; i < n; i++){
                hash1[i + 1] = (hash1[i] + (s.charAt(i) - 'a' + 1) * power1[i]) % mod;
                hash2[i + 1] = (hash2[i] + (s.charAt(i) - 'a' + 1) * power2[i]) % mod;
            }
        }
        long hash(int l, int r){ // Hash of the substring [l, r] (0-indexed)
            long r1 = (hash1[r + 1] - hash1[l] + mod) % mod;
            long r2 = (hash2[r + 1] - hash2[l] + mod) % mod;
            r1 = (r1 * invp1[l]) % mod;
            r2 = (r2 * invp2[l]) % mod;
            return (r1 << 32) | r2;
        }
    }

    public static void main(String[] args) throws IOException{
        // Solving this problem becomes trivial with our rolling hash struct
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String s = br.readLine();
        rolling_hash h = new rolling_hash(s);
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            // r not inclusive
            --r;
            pw.println(h.hash(l,r));
        }
        pw.close();
    }

}