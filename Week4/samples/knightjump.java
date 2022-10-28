import java.io.*;
import java.util.*;
import java.awt.Point; // For 2-d grid problems in Java, I like to use a Point to represent a cell

class Main{
    static int[] dx = {2,1,-1,-2,-2,-1,1,2};
    static int[] dy = {1,2,2,1,-1,-2,-2,-1}; 
                                         
    public static void main(String[] args){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        char[][] grid = new char[n][];
        for(int i = 0; i < n; i++){
            grid[i] = in.readLine().toCharArray();
        }
        Point start = null;
        int[][] dist = new int[n][n];
        for(int i = 0; i < n; i++){
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'K'){
                    start = new Point(i, j);
                }
            }
        }
        Queue<Point> q = new LinkedList<>();
        q.add(start);
        dist[start.x][start.y] = 0;
        while(!q.isEmpty()){
            Point p = q.poll();
            for(int d = 0; d < 8; d++){
                int nx = p.x + dx[d], ny = p.y + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // out of bounds
                if(grid[nx][ny] == '#') continue; // blocked
                if(dist[nx][ny] != Integer.MAX_VALUE) continue; // already visited
                dist[nx][ny] = dist[p.x][p.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
        if(dist[0][0] == Integer.MAX_VALUE) dist[0][0] = -1;
        System.out.println(dist[0][0]);
    }
}