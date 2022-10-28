import java.io.*;
import java.util.*;
import java.awt.Point;

class Main{
    // Make sure when you submit, the class name is Main


    // input format: grid[i][j] is the value of the cell at row i, column j
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1}; // You may want to use these arrays in your implementation
                                    // You may also want to use java.awt.Point

    // return the minimum number of steps to escape the fire, or -1 if it's impossible
    static int fire(int rows, int cols, char[][] grid){
        // We can use two bfs's to find the distance to the fire and to the person
        // An exit point is valid iff the person can reach it before the fire
        int distToPerson[][] = new int[rows][cols];
        int distToFire[][] = new int[rows][cols];

        Queue<Point> personQ = new LinkedList<Point>(), fireQ = new LinkedList<Point>();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                distToPerson[i][j] = distToFire[i][j] = Integer.MAX_VALUE;
                if(grid[i][j] == '@'){
                    personQ.add(new Point(i, j));
                    distToPerson[i][j] = 0;
                }else if(grid[i][j] == '*'){
                    fireQ.add(new Point(i, j));
                    distToFire[i][j] = 0;
                }
            }
        }

        while(!personQ.isEmpty()){
            Point p = personQ.poll();
            for(int d = 0; d < 4; d++){
                int nx = p.x + dx[d], ny = p.y + dy[d];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                if(grid[nx][ny] == '#') continue;
                if(distToPerson[nx][ny] != Integer.MAX_VALUE) continue;
                if(distToPerson[nx][ny] > distToPerson[p.x][p.y] + 1){
                    distToPerson[nx][ny] = distToPerson[p.x][p.y] + 1;
                    personQ.add(new Point(nx, ny));
                }
            }   
        }

        while(!fireQ.isEmpty()){
            Point p = fireQ.poll();
            for(int d = 0; d < 4; d++){
                int nx = p.x + dx[d], ny = p.y + dy[d];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                if(grid[nx][ny] == '#') continue;
                if(distToFire[nx][ny] != Integer.MAX_VALUE) continue;
                if(distToFire[nx][ny] > distToFire[p.x][p.y] + 1){
                    distToFire[nx][ny] = distToFire[p.x][p.y] + 1;
                    fireQ.add(new Point(nx, ny));
                }
            }   
        }

        int ans = Integer.MAX_VALUE;
        // Now we can check each exit point to see if it's valid
        for(int i = 0; i < rows; i++){
            if(distToPerson[i][0] < distToFire[i][0]) {
                ans = Math.min(ans, distToPerson[i][0]);
            }
            if(distToPerson[i][cols - 1] < distToFire[i][cols - 1]) {
                ans = Math.min(ans, distToPerson[i][cols - 1]);
            }
        }

        for(int j = 0; j < cols; j++){
            if(distToPerson[0][j] < distToFire[0][j]) {
                ans = Math.min(ans, distToPerson[0][j]);
            }
            if(distToPerson[rows - 1][j] < distToFire[rows - 1][j]) {
                ans = Math.min(ans, distToPerson[rows - 1][j]);
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans + 1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(in.readLine());
        for(int t = 1; t <= q; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int cols = Integer.parseInt(st.nextToken()), rows = Integer.parseInt(st.nextToken());
            char[][] grid = new char[rows][cols];
            for(int i = 0; i < rows; i++){
                grid[i] = in.readLine().toCharArray();
            }
            int ans = fire(rows, cols, grid);
            if(ans == -1){
                System.out.println("IMPOSSIBLE");
            }else{
                System.out.println(ans);
            }
        }
    }
}