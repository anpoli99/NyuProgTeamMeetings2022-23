
import java.io.*;
import java.util.*;


class Main{  
    // Make sure the class name is Main if you use this template
    static final int N = 200 + 5;
    static final double dist[][] = new double[N][N]; 
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while(n != 0){
            HashMap<String, Integer> mp = new HashMap<String, Integer>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++){
                String s = st.nextToken();
                mp.put(s, i);
                // You may want to put some additional preprocessing code here
            }
            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                String c = st.nextToken();
                String[] cs = c.split(":");
                double x = Double.parseDouble(cs[0]), y = Double.parseDouble(cs[1]);
                int u = mp.get(a), v = mp.get(b);
                // u and v are the indices of the two cities
                // x and y are the exchange rates
                // (Your code here to build the graph)

            }
            // Your code here to determine if any arbitrage exists
            if(/*condition for arbitrage*/ true){
                System.out.println("Arbitrage");
            }else{
                System.out.println("Ok");
            }
            n = Integer.parseInt(br.readLine());
        }
    }
}
