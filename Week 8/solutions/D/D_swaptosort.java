import java.io.*;
import java.util.*;

class Main{
    // Make sure class name is Main if you submit with this template!

    // Input: 'a' is 2d array of size [k][2] representing the k swaps
    // Output: True if a descending list of size n can be sorted with the swaps, false otherwise
    static int[] root;
    static int find(int x){
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }
    static boolean swapToSort(int n, int k, int[][] a){
        root = new int[n + 1]; // 1-indexed
        Arrays.fill(root, -1);
        // We can always sort the descending list if "mirrored" elements are in the same component
        // when looking at the swaps. "Mirrored" elements are elements that should be in each other's
        // positions if the list is sorted. (i.e. 1 and n, 2 and n - 1, etc.)
        for(int i = 0; i < k; i++){
            int x = a[i][0];
            int y = a[i][1];
            int rx = find(x);
            int ry = find(y);
            if(rx == ry) continue;
            root[rx] = ry;
        }
        for(int i = 1; i <= n / 2; i++){
            if(find(i) != find(n - i + 1)) return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] a = new int[k][2];
        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());
            a[i][0] = Integer.parseInt(st.nextToken());
            a[i][1] = Integer.parseInt(st.nextToken());
        }
        System.out.print(swapToSort(n, k, a) ? "Yes" : "No");
    }
}