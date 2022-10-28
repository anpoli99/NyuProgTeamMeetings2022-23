import java.io.*;
import java.util.*;

class Main{
    // Make sure when you submit, the class name is Main

    // Input format: related.get(i) is a list of all the movies that are related to movie i
    static int horrorlist(int n, ArrayList<Integer> horrorMovies, ArrayList<ArrayList<Integer>> related){
        ArrayList<Integer> horrorIndex = new ArrayList<Integer>();
        while(horrorIndex.size() < n) horrorIndex.add(Integer.MAX_VALUE);
        
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i : horrorMovies){
            horrorIndex.set(i, 0);
            q.add(i);
        }

        while(!q.isEmpty()){
            int i = q.poll();
            for(int j : related.get(i)){
                if(horrorIndex.get(j) > horrorIndex.get(i) + 1){
                    horrorIndex.set(j, horrorIndex.get(i) + 1);
                    q.add(j);
                }
            }
        }

        int highestScore = -1, bestIndex = -1;
        for(int i = 0; i < n; i++){
            if(horrorIndex.get(i) > highestScore){
                highestScore = horrorIndex.get(i);
                bestIndex = i;
            }
        }
        return bestIndex;

    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
        
        ArrayList<Integer> horrorMovies = new ArrayList<Integer>();
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i < h; i++){
            horrorMovies.add(Integer.parseInt(st.nextToken()));
        }

        ArrayList<ArrayList<Integer>> related = new ArrayList<ArrayList<Integer>>();
        while(related.size() < n) related.add(new ArrayList<Integer>());
        for(int i = 0; i < l; i++){
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            related.get(a).add(b);
            related.get(b).add(a);
        }
        System.out.println(horrorlist(n, horrorMovies, related));
    }
}