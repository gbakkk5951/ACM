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
const lld MOD = 998244353;
const int MXN = 3e3 + 5;
int f[MXN], fr[MXN];
int a[MXN], cs[MXN][MXN], c[MXN][MXN], b[MXN];
int ans[MXN];
int getrev(lld a) {
	int pow = MOD - 2;
	lld ret = 1;
	while (pow) {
		if (pow & 1) ret = ret * a % MOD;
		if (pow >>= 1) a = a * a % MOD;
	}
	return ret;
}
void init(int n) {
	fr[0] = f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % MOD;
		fr[i] = getrev(f[i]) % MOD;
	}
	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	cs[0][0] = 1;;
	for (int i = 1; i <= n; i++) {
		cs[i][0] = i + 1;
		for (int j = 1; j <= i; j++) {
			cs[i][j] = (c[i][j] + cs[i - 1][j]) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) {
		lld s1 = 0;
		for (int j = 1; j <= i; j++) {
			lld mul = f[i - j] * f[j - 1] % MOD;
			lld sum = 0;
			for (int k = 1; k <= i - j; k++) {
				sum = (sum + cs[i - 1][k] * c[i - 1][i - j - k]) % MOD;
			}
			s1 = (s1 + sum * mul) % MOD;
		}
		a[i] = s1;
	}
	
	for (int i = 1; i <= n; i++) {
		lld sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += c[n][j] * c[n][j] % MOD * f[n - j] % MOD * a[j] % MOD;
		}
		b[i] = sum % MOD;
	}
	lld p = 1;
	for (int i = 1; i <= n; i++) {
		p <<= 1;
		p %= MOD;
		ans[i] = (a[i] * fr[n] % MOD + b[i] * fr[n] % MOD * getrev(p)) % MOD;
	}
}
struct _Main {
	_Main() {
		init(3000);
		int n;
		while (~scanf("%d", &n)) {
			printf("%d\n", ans[n]);
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
