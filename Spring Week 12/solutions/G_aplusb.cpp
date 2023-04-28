#include<bits/stdc++.h>
using namespace std;

/*
Actually this problem is almost directly asking us to print
the result from FFT; we can treat the input array as a polynomial
and multiply it by itself. There are some edge cases to take care
of before printing the result though:

- This approach will give an extra +1 in each position 2 * A[i], for
    all 'i'. We can just subtract this off at the end.
- Because we need to know the number of ways that x + y = z, we can sum
    over all A[i] at the end as a substitue for 'z'.
- This approach will not handle zeroes correctly; we need to subtract
    off the number of ways that A[i] + 0 = A[i]. This is equal to the number 
    of zeroes times (n - 1) times two.  
*/

#define rep(i,a,b) for(int i=(a);i<(b);i++) 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using vi = vector<int>;
using vd = vector<double>; 


typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}


const int N = 1e5 + 10;
const int OFFSET = 5e4 + 5;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<double> poly(N);
    int zeros = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0){
            zeros++;
        }
        poly[a[i] + OFFSET] += 1;
    }
    vector<double> result = conv(poly, poly);
    for(int i : a){
        result[2 * (i + OFFSET)] -= 1;
    }
    long long total = 0;
    for(int i : a){
        // Since we added OFFSET to i for both the original indices,
        // the result will have a 2 * OFFSET displacement.
        total += round(result[i + 2 * OFFSET]);
    }
    total -= 1ll * zeros * (n - 1) * 2;
    cout << total << endl;
}