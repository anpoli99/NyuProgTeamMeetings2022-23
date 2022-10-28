import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main
    
    // input format: given a list of heights of both stalagmites and stalactites as 'a' and 'b'
    // return a pair with the optimal # of obstacles and the # of levels where that is possible
    // return this pair as an int[] of length 2

    // note that the firefly cannot fly at a height of 0
    static int[] firefly(int n, int h, ArrayList<Integer> a, ArrayList<Integer> b){
        // note that initially, n = a.size() + b.size()
        n /= 2;

        // We can keep track of where each stalagmite ends and each stalactite begins
        // To do this, it's easier if we have the height of where the stalagtite begins instead of its length
        for(int i = 0; i < b.size(); i++){
            b.set(i, h - b.get(i));
        }

        int minObstacles = Integer.MAX_VALUE;
        int numLevels = 0;
        int cur = n;

        // We can use a sliding window to find the minimum number of stalagmites that need to be removed
        // At each height, we'll advance the pointer as it passes the beginning/end of obstacles
        Collections.sort(a);
        Collections.sort(b);
        int aPtr = 0, bPtr = 0;
        for(int i = 1; i <= h; i++){
            while(aPtr < a.size() && a.get(aPtr) < i) {
                aPtr++;
                cur--;
            }
            while(bPtr < b.size() && b.get(bPtr) < i) {
                bPtr++;
                cur++;
            }
            if(cur < minObstacles){
                minObstacles = cur;
                numLevels = 1;
            }else if(cur == minObstacles){
                numLevels++;
            }
        }
        return new int[]{minObstacles, numLevels};
    }

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            int x = Integer.parseInt(in.readLine());
            if(i % 2 == 0) a.add(x);
            else b.add(x);
        }
        int[] ans = firefly(n, h, a, b);
        System.out.println(ans[0] + " " + ans[1]);
    }
}