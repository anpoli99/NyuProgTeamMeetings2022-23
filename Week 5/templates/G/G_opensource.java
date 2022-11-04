import java.util.*;
import java.io.*;


class Main{
    // Make sure you have the class name as Main if you use this template
	static class Pair{
		String s; int k;
		Pair(String _s, int _k){
			s = _s;
			k = _k;
		}
	}
    static ArrayList<Pair> opensource(ArrayList<String> lines){
        // Your code to find the number of members per project goes here
        return new ArrayList<Pair>();
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        ArrayList<String> lines = new ArrayList<String>();
        while(true){
            s = br.readLine();
            if(s.equals("1")){
                ArrayList<Pair> ans = opensource(lines);
                for(Pair p : ans){
                    System.out.println(p.s + " " + p.k);
                }
                lines.clear();
            }else if(s.equals("0")){
                break;
            }else{
                lines.add(s);
            }
        }
    }
}