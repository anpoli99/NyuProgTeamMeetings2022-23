#include<bits/stdc++.h>
using namespace std;

/*
This FFT implementation is taken from KACTL; it is very fast and easy to use.
(although a bit hard to read if you ask me)
I've given an example of using it to multiply two polynomials.
*/

#define rep(i,a,b) for(int i=(a);i<(b);i++) 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using vi = vector<int>;
using vd = vector<double>; 
// Very competitive programmers like to keep their codes very short
// So they use all these macros and typedefs to write their code faster
// I like some of these, but I don't use rep and sz for example


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

int main(){
    // Arguments: First line should have n and m
    // Second line: an n degree polynomial of the form: a_0 + a_1x + a_2x^2 + ... + a_nx^n
    // Third line: an m degree polynomial of the form: b_0 + b_1x + b_2x^2 + ... + b_mx^m
    int n, m;
    cin >> n >> m;
    vector<double> a(n+1), b(m+1);
    for(int i = 0; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= m; i++) cin >> b[i];
    vector<double> c = conv(a, b);
    for(int i = 0; i < sz(c); i++) cout << c[i] << " ";
    cout << endl;

}