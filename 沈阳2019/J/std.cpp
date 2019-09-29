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
typedef complex<lf> com;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const lld MOD = 1e9 + 7;
const lld PHI = MOD - 1;
const int MXN = 1e6 + 5;
struct _Main {
	lld f[MXN];
	lld fr[MXN];
	lld frs[MXN];
	lld s[MXN];
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			if (pow & 1) ret = ret * base % MOD;
			if (pow >>= 1) base = base * base % MOD;
		}
		return ret;
	}
	_Main() {
		int Tn;
		int n = 1e6;
		frs[0] = f[0] = fr[0] = 1;
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] * i % MOD;
	//		fr[i] = fastpower(f[i], PHI - 1);
	//		frs[i] = (frs[i - 1] + fr[i]) % MOD;
			s[i] = (s[i - 1] + fastpower(i, PHI - 1)) % MOD;
		}
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			int n, x;
			lld ans = 0;
			read(n); read(x);
			if (x >= n) {
				ans = 1;
			} else {
				ans = ((1 - (s[n] - s[x])) % MOD + MOD) % MOD;
			}
			printf("%lld\n", ans);
			
		}
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
