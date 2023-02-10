#include <bits/stdc++.h>
using namespace std;

// Input: N and A, where A is a vector of N integers
// Output: True if the vector is Jolly, False otherwise
bool jollyjumpers(int N, vector<int> A){
    //Your code here
    return true;
}

int main(){
    int N;
    while(cin >> N){
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        cout << (jollyjumpers(N,A) ? "Jolly" : "Not jolly") << endl;
    }
}
// That but in java:
import java.io.*;
import java.util.*;

public class Main{
    // Input: N and A, where A is an array of N integers
    // Output: True if the vector is Jolly, False otherwise
    public static boolean jollyjumpers(int N, int[] A){
        //Your code here
        return true;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = br.readLine()) != null){
            StringTokenizer st = new StringTokenizer(line);
            int N = Integer.parseInt(st.nextToken());
            int[] A = new int[N];
            for(int i = 0; i < N; i++){
                A[i] = Integer.parseInt(st.nextToken());
            }
            System.out.println(jollyjumpers(N,A) ? "Jolly" : "Not jolly");
        }
    }
}