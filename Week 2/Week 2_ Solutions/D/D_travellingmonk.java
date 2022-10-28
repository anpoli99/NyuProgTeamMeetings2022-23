import java.io.*;
import java.util.*;

// make sure you submit w/ the class name set to Main if you use this template
class Main{
                            // being generic let's us just write this function once
    static double calculateDistance(int[] distances, int[] times, int n, double targetTime){
        // this function calculates the distance travelled in a given time
        double currentDistance = 0;
        double targetTime = 0;
        for(int i = 0; i < n && currentTime < targetTime; i++){
            double nextTime = currentTime + times[i];
            if(nextTime > targetTime){
                double remainingTime = targetTime - currentTime;
                return currentDistance + remainingTime * (distances[i] / (double)times[i]);
            }
            currentDistance += distances[i];
            currentTime = nextTime;
        }
        return currentDistance;
    }
    // note: for convenience this template keeps these input variables global
    static final int MAXN = 5000 + 5;
    static int[] ascendingTime = new int[MAXN], descendingTime = new int[MAXN];
    static int[] ascendingDistance = new int[MAXN], descendingDistance = new int[MAXN];
    int a, d;
    static double travellingMonk(){
        double totalDistance = 0, totalTime = 0;
        for(int i = 0; i < a; i++){
            totalDistance += ascendingDistance[i];
            totalTime += ascendingTime[i];
        }
        double lo = 0, hi = totalTime;
        for(int i = 0; i < 100; i++){
            double mid = (lo + hi) / 2;
            double distAscent = calculateDistance(ascentDistance, ascentTime, a, mid);
            double distDescent = calculateDistance(descentDistance, descentTime, d, mid);
            if(distAscent < totalDistance - distDescent){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        return lo;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        a = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        for(int i = 0; i < a; i++){
            st = new StringTokenizer(in.readLine());
            ascendingDistance[i] = Integer.parseInt(st.nextToken());
            ascendingTime[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < d; i++){
            st = new StringTokenizer(in.readLine());
            descendingDistance[i] = Integer.parseInt(st.nextToken());
            descendingTime[i] = Integer.parseInt(st.nextToken());
        }
    }
}