import java.util.*;
import java.io.*;

/*
This FFT implementation is taken from KACTL; it is very fast and easy to use.
(although a bit hard to read if you ask me)
I've adapted it to Java, but mostly left it as-is.
I've given an example of using it to multiply two polynomials.
*/

class Main{
    static class C{
        double x, y;
        C(double x, double y){
            this.x = x;
            this.y = y;
        }
        C add(C o){
            return new C(x + o.x, y + o.y);
        }
        C sub(C o){
            return new C(x - o.x, y - o.y);
        }
        C mul(C o){
            return new C(x * o.x - y * o.y, x * o.y + y * o.x);
        }
        C conj(){
            return new C(x, -y);
        }
    }
    static void fft(C[] a){
        int n = a.length, L = 31 - Integer.numberOfLeadingZeros(n);
        C[] R = new C[n];
        R[0] = new C(1, 0);
        R[1] = new C(1, 0);
        C[] rt = new C[n];
        rt[0] = new C(1, 0);
        rt[1] = new C(1, 0);
        for(int k = 2; k < n; k *= 2){
            C x = new C(Math.cos(Math.PI / k), Math.sin(Math.PI / k));
            for(int i = k; i < 2 * k; i++){
                rt[i] = R[i] = (i & 1) == 1 ? R[i/2].mul(x) : R[i/2];
            }
        }
        int[] rev = new int[n];
        for(int i = 0; i < n; i++){
            rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        }
        for(int i = 0; i < n; i++){
            if(i < rev[i]){
                C temp = a[i];
                a[i] = a[rev[i]];
                a[rev[i]] = temp;
            }
        }
        for(int k = 1; k < n; k *= 2){
            for(int i = 0; i < n; i += 2 * k){
                for(int j = 0; j < k; j++){
                    C z = rt[j + k].mul(a[i + j + k]);
                    a[i + j + k] = a[i + j].sub(z);
                    a[i + j] = a[i + j].add(z);
                }
            }
        }
    }
    static double[] conv(double[] a, double[] b){
        if(a.length == 0 || b.length == 0) return new double[0];
        int s = a.length + b.length - 1;
        int L = 32 - Integer.numberOfLeadingZeros(s);
        int n = 1 << L;
        C[] in = new C[n];
        C[] out = new C[n];
        for(int i = 0; i < n; i++){
            in[i] = new C(0, 0);
            out[i] = new C(0, 0);
        }
        for(int i = 0; i < a.length; i++){
            in[i] = new C(a[i], 0);
        }
        for(int i = 0; i < b.length; i++){
            in[i].y = b[i];
        }
        fft(in);
        for(int i = 0; i < n; i++){
            in[i] = in[i].mul(in[i]);
        }
        for(int i = 0; i < n; i++){
            out[i] = in[-i & (n - 1)].sub(in[i].conj());
        }
        fft(out);
        double[] res = new double[s];
        for(int i = 0; i < s; i++){
            res[i] = out[i].y / (4 * n);
        }
        return res;
    }
    public static void main(String[] args) throws IOException{
        // Arguments: first line should contain two integers n and m, the degrees of the two polynomials
        // Second line: an n degree polynomial of the form: a_0 + a_1x + a_2x^2 + ... + a_nx^n
        // Third line: an m degree polynomial of the form: b_0 + b_1x + b_2x^2 + ... + b_mx^m
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        double[] a = new double[n + 1];
        double[] b = new double[m + 1];
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i <= n; i++){
            a[i] = Double.parseDouble(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i <= m; i++){
            b[i] = Double.parseDouble(st.nextToken());
        }
        double[] c = conv(a, b);
        for(int i = 0; i < c.length; i++){
            out.print(c[i] + " ");
        }
        out.println();
        out.close();
    }
}
