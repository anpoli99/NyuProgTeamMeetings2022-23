import java.io.*;
import java.util.*;

class Main{
  public static void main(String[] args) throws IOException{
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int trials = Integer.parseInt(in.readLine());
      for(int t = 0; t < trials; t++){
         StringTokenizer st = new StringTokenizer(in.readLine());
         int n = Integer.parseInt(st.nextToken());
         int[] gnomes = new int[n];
         for(int i = 0; i < n; i++){
            gnomes[i] = Integer.parseInt(st.nextToken());
         }
         for(int i = 1; i < n - 1; i++){
            int prev = -1;
            boolean sorted = true;
            for(int j = 0; j < n; j++){
              if(i == j) continue;
              sorted = sorted && gnomes[j] >= prev;
              prev = gnomes[j];
            }
            if(sorted){
              System.out.println(i);
            }
         }
      }
  }

}