import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
    static boolean validate(int n, ArrayList<Integer> a, ArrayList<Integer> b, int heaviestWeight){
        // remove all weights we can; we can always pair these together
        // now we need to check if the weights we can't move are paired
        ArrayList<Integer> remainingA = new ArrayList<Integer>();
        ArrayList<Integer> remainingB = new ArrayList<Integer>();
        for(int i : a){
            if(i > heaviestWeight){
                remainingA.add(i);
            }
        }
        for(int i : b){
            if(i > heaviestWeight){
                remainingB.add(i);
            }
        }
        if(remainingA.size() % 2 == 1) return false; // can't pair an odd number of weights
        if(remainingB.size() % 2 == 1) return false;
        for(int i = 0; i < remainingA.size(); i += 2){ 
            // don't use != on Objects
            if(!remainingA.get(i).equals(remainingA.get(i + 1))) return false; // these elements are unpaired
        }
        for(int i = 0; i < remainingB.size(); i += 2){
            if(!remainingB.get(i).equals(remainingB.get(i + 1))) return false;
        }
        return true;
    }

    static int freeWeights(int n, ArrayList<Integer> a, ArrayList<Integer> b){
        int lo = 0, hi = 1000000015; // 'hi' must be >= the max weight
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(validate(n, a, b, mid)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        
        StringTokenizer st = new StringTokenizer(in.readLine());
        for(int i = 0; i < n; i++){
            a.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i < n; i++){
            b.add(Integer.parseInt(st.nextToken()));
        }
        
        System.out.println(freeWeights(n, a, b));
    }
}