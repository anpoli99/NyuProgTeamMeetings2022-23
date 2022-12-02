import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!

    // Input: 2d array of size [n][2], where s[i][0] and s[i][1] are the names of friends
    // Output: 1d array of size n; the size of the friend group after each update
    static int[] root; // You may want to use this union-find template
    static int find(int x){
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }
    static void join(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry) root[rx] = ry;
    }
    static int[] virtualFriends(int n, String[][] s){
        // Initialize union-find
        root = new int[2 * n]; // (why 2 * n?)
        Arrays.fill(root, -1);

        // Your code goes here
        return new int[n]; // This is a placeholder
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qrys = Integer.parseInt(br.readLine());
        while(qrys-- > 0){
            int n = Integer.parseInt(br.readLine());
            String[][] s = new String[n][2];
            for(int i = 0; i < n; i++){
                String[] temp = br.readLine().split(" ");
                s[i][0] = temp[0];
                s[i][1] = temp[1];
            }
            int[] ans = virtualFriends(n, s);
            for(int i = 0; i < n; i++){
                System.out.println(ans[i]);
            }
        }
    }

}