using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const lld MOD = 998244353;
const int MXN = 1e6 + 10;
struct _Main {
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			if (pow & 1) ret = ret * base % MOD;
			if (pow >>= 1) base = base * base % MOD;
		}
		return ret;
	}
	int plim;
	int pn;
	bitset<MXN> v;
	int p[79000];
	int phi[MXN];
	int pw[MXN];
	
	int sum[MXN];
	int psum[MXN];
	
	void sieve() {
		phi[1] = 1;
		pw[1] = 1;
		for (int i = 2; i <= plim; i++) {
			if (!v[i]) {
				p[pn++] = i;
				phi[i] = i - 1;
				pw[i] = fastpower(i, m);
			}
			for (int j = 0, t, pp; j < pn && (t = i * (pp = p[j])) <= plim; j++) {
				v[t] = 1;
				pw[t] = (lld)pw[i] * pw[pp] % MOD;
				if (i % pp) {
					phi[t] = phi[i] * (pp - 1) % MOD;
				} else {
					phi[t] = phi[i] * pp % MOD;
					break;
				}
			}
		
		}
		for (int i = 1; i <= plim; i++) {
			sum[i] = (sum[i - 1] + pw[i]) % MOD;
			psum[i] = (psum[i - 1] + phi[i]) % MOD;
		}
	}
	lld f[1010];
	lld w[1010];
	void init() {
		f[0] = 1;
		for (int i = 1; i <= m + 1; i++) {
			f[i] = f[i - 1] * i % MOD;
		}
		for (int i = 1; i <= m + 2; i++) {
			w[i] = fastpower(f[i - 1] * f[m + 2 - i] * (((m + 2 - i) & 1) ? -1 : 1) % MOD, MOD - 2);
			w[i] = (w[i] * sum[i]) % MOD;
		}
	}
	lld getval(int a) {
		if (a <= plim) return sum[a];
		lld l = 1, r = 0;
		for (int i = 1; i <= m + 2; i++) {
			l = l * (a - i) % MOD;
			r = (r + w[i] * fastpower(a - i, MOD - 2) % MOD) % MOD;
		}
		return l * r % MOD;
	}
	int rem[1010];
	lld phisum(int a) {
		if (a <= plim) return psum[a];
		int it;
		if (rem[it = n / a]) return rem[it] - 1;
		lld ret = (a * (a + 1LL) >> 1);
		for (int st = 2, ed, t; st <= a; st = ed + 1) {
			ed = a / (t = a / st);
			ret -= (ed - st + 1) * phisum(t);
		}
		ret %= MOD;
		if (ret < 0) ret += MOD;
		rem[it] = ret + 1;
		return ret;
	}
	int n, m;
	lld calc() {
		lld ret = 0;
		for (int st = 1, ed, t; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret += (phisum(ed) - phisum(st - 1)) * getval(t);
			ret %= MOD;
		}
		if (ret < 0) ret += MOD;
		return ret;
	}
	_Main() {
		read(n); read(m);
		plim = max((lld) ceil(pow(n, 2.0 / 3.0)), (lld) ceil(sqrt((lf)n * m)));
		plim = max(plim, m + 2);
		sieve();
		init();
		printf("%lld", calc());
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
