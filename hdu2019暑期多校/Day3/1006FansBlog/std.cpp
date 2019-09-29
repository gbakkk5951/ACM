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
const int MXN = 1e7 + 10;
struct _Main {
	lld n;
	bool isprime(lld x) {
		for (int i = 0; i < pcnt && (lld)p[i] * p[i] <= x; i++) {
			if (x % p[i] == 0) return 0;
		}
		return 1;
	}
	int p[664600];
	int pcnt;
	bitset<MXN> v;
	lld mod;
	lld mul(lld a, lld b) {
//		printf("mul %lld %lld = %lld\n", a, b, ((a * b - (lld)((lf)a * b / mod) * mod) % mod + mod) % mod);
		return ((a * b - (lld)((Lf)a / mod * b) * mod) % mod + mod) % mod;
	}
	lld getrev(lld base) {
		lld ret = 1, pow = mod - 2;
		while (pow) {
			if (pow & 1) ret = mul(ret, base);
			if (pow >>= 1) base = mul(base, base);
		}	
		return ret;
	}
	void sieve() {
		int x, t, mx = 1e7;
		for (int i = 2; i <= mx; i++) {
			if (!v[i]) {
				p[pcnt++] = i;
			}
			for (int j = 0; j < pcnt && (t = i * (x = p[j])) <= mx; j++) {
				v[t] = 1;
				if (i % x == 0) {
					break;
				}
			}
		}
	}
	
	_Main() {
		sieve();
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(n);
			mod = n;
			lld ans = n - 1;
			for (lld i = n - 1; ; i--) {
				if (isprime(i)) {
					break;
				} else {
					ans = mul(ans, getrev(i));
				}
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
