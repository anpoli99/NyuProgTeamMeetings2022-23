#include<bits/stdc++.h>
using namespace std;

/*
Completeing the course in two shots is the same as asking, 
"do two numbers in my list sum to the length of the course"?
We can, of _course_ (haha), use FFT to answer this question.
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

const int N = 2e5 + 5;
bool in_set[N]; // If we can get a hole in one, that also counts
// as completing the course, so we should keep track of that too
int main(){
    int n;
    cin >> n;
    vector<double> a(N);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        in_set[x] = true;
        a[x] = 1;
    }
    vector<double> res = conv(a, a);
    int ans = 0;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int k;
        cin >> k;
        if(round(res[k]) > 0 || in_set[k]){
            ans++;
        }
    }
    cout << ans << endl;
}