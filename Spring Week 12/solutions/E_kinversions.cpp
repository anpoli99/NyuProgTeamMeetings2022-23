#include<bits/stdc++.h>
using namespace std;

/*
I've given away that this is an FFT problem, so it seems likely
that we'll be convolving the As and Bs. How can we do this to count
our target? For example, we want (1,3) and (2,4) to both map to 2.
It's not their sum that's important, but their _difference_. So let's
negate the B array. This gives us (-1, -) and (-2, 4). Now their sum is
the same. Since negative numbers don't really play nice with arrays, 
we can add 'n - 1' to the negative numbers to make sure they're all
positive. Now our answer for position 'k' will be located at position
'k + n - 1' in the convolved array.
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); // Fast I/O

    string s;
    cin >> s;
    int n = s.size();
    vector<double> A(n), B(n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            A[i] = 1;
        }else{
            B[n - i - 1] = 1;
        }
    }
    vector<double> C = conv(A, B);
    for(int k = n; k < C.size(); k++){
        cout << (int)round(C[k]) << '\n';
    }

}