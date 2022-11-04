import java.util.*;
import java.io.*;


class Main{
	static class Pair{
		String s; int k;
		Pair(String _s, int _k){
			s = _s;
			k = _k;
		}
	}
    // Make sure you have the class name as Main if you use this template
    static ArrayList<Pair> opensource(ArrayList<String> lines){
        ArrayList<Pair> ans = new ArrayList<Pair>();
        // We'll use this to store the users for each projects:
        HashMap<String, HashSet<String>> members = new HashMap<String, HashSet<String>>();
        // We'll use this to store how many projects each user is in:
        HashMap<String, Integer> userProjects = new HashMap<String, Integer>();

        ArrayList<String> projects = new ArrayList<String>();
        String current = lines.get(0);
        projects.add(current);
        members.put(current, new HashSet<String>());
        for(int i = 1; i < lines.size(); i++){
            boolean isNewProject = false;
            for(char c : lines.get(i).toCharArray()){
                isNewProject |= Character.isUpperCase(c);
            }
            if(isNewProject){
                current = lines.get(i);
                projects.add(current);
                members.put(current,  new HashSet<String>());
            }else if(!members.get(current).contains(lines.get(i))){
                members.get(current).add(lines.get(i));
                userProjects.put(lines.get(i), userProjects.getOrDefault(lines.get(i), 0) + 1);
            }
        }
        for(String s : projects){
            int ct = 0;
            for(String t : members.get(s)){
                ct += userProjects.get(t) == 1 ? 1 : 0;
            }
            ans.add(new Pair(s, ct));
        }
        Collections.sort(ans, new Comparator<Pair>(){
            public int compare(Pair a, Pair b){
                if(a.k == b.k){
                    return a.s.compareTo(b.s);
                }
                return b.k - a.k;
            }
        });
        return ans;
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