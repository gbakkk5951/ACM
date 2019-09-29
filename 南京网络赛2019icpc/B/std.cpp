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
const int MXN = 1e6 + 5;
lld m;
struct _Main {
	int a, b, Tn;	
	lf now;
	lld tag;
	lld fastpower(lld base, lld pow, lld mod) {
		lld ret = 1;
		while (pow) {
			if (tag || base >= m) {
				tag = 1;
				base %= mod;
			}
			if (pow & 1) ret = ret * base;
			if (tag || ret >= m) {
				tag = 1;
				ret %= mod;
			}
			if (pow >>= 1) base = base * base;
		}
		return ret;
	}
	lld calc(int now, int mx, lld mod) {
		if (now == mx) {
			return tag ? a % mod : a;
		} else
		if (now <= 40 || mx <= 60) {
			lld tmp =  calc(now + 1, mx, phi[mod]);
			lld t2;
			if (!tag) {
				t2 = fastpower(a, tmp, mod);
			}
			if (tag) {
				t2 = fastpower(a, tmp + phi[mod], mod);
			}
			return t2;
		} else {
			tag = 1;
			return 1;
		}
	}
	char v[MXN];
	int pn, p[100000], phi[MXN];
	void getprime() {
		int mx = 1e6, t;
		phi[1] = 1;
		for (int i = 2; i <= mx; i++) {
			if (!v[i]) {
				p[pn++] = i;
				phi[i] = i - 1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				v[t] = 1;
				if (i % p[j]) {
					phi[t] = phi[i] * (p[j] - 1);
				} else {
					phi[t] = phi[i] * p[j];
					break;
				}
			}
		}
	}
	_Main() {
		getprime();
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			tag = 0;
			read(a); read(b); read(m);
			if (b == 0) {
				printf("%lld\n", 1 % m);
			} else {
				if (a >= m) tag = 1;
				printf("%lld\n", calc(1, b, m));
			}
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
