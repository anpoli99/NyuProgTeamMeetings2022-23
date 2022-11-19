import java.io.*;
import java.util.*;

public class Main{  
    static boolean validate(int x, int y, int z){
        if(x + y == z || x * y == z) return true;
        return false;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int qr = Integer.parseInt(br.readLine());
        while(qr-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            // Division (x / y = z) is really the same as multiplication (x = y * z)
            // The numbers are so small it probably won't matter, but we can avoid
            // precision by only checking addition/multiplication, skipping subtraction/division
            boolean ok = validate(x,y,z) || validate(x,z,y) || validate(y,z,x);
            // a small bonus: multiplication is commutative, so we only have to check 3 cases
            if(ok) System.out.println("Possible");
            else System.out.println("Impossible");
        }
    }
    
}