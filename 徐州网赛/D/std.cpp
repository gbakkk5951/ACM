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
const lld BASE = 31, MOD = 1e9 + 7;
const int MXN = 1e5 + 10;
lld ht[MXN], hs[MXN];
char s[MXN], t[MXN];
lld pow[MXN]
int n, m;
int Qn;
struct _Main {
	void inithash(char str[], lld hash[], int n) {
		for (int i = 1; i <= n; i++) {
			hash[i] = (hash[i - 1] * BASE + str[i] - 'a' + 1) % MOD;
		}
	}
	lld gethash(lld hash[], int l, int r) {
		lld ret = (hash[r] - hash[l - 1]) * pow[l - 1] % MOD;
		return ret < 0 ? ret + MOD : ret;
	}
	bool isin(lld h1[], lld h2[], int n, int m) {
		// n <= m
		for (int i = 1; i + n - 1 <= m; i++) {
			if (h1[n] == gethash(h2, i, i + n - 1)) {
				return 1;
			}
		}
		return 0;
	}
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			if (pow & 1) ret = ret * base % MOD;
			if (pow >>= 1) base = base * base % MOD;
		}
		return ret;
	}
	_Main() {
		scanf("%s", t + 1);
		n = strlen(t + 1);
		read(Qn);
		inithash(t, ht, n);
		pow[0] = 1;
		for (int i = 1; i <= 1e5 + 1; i++) {
			pow[i] = pow[i - 1] * fastpower(BASE, MOD - 2) % MOD;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", s + 1);
			m = strlen(s + 1);
			inithash(s, hs, m);
			if (n > m) {
				if (isin(hs, ht, m, n)) {
					printf("my child!\n");
				} else {
					printf("oh, child!\n");
				}
			} else
			if (n == m) {
				if (isin(hs, ht, n, m)) {
					printf("jntm!\n");
				} else {
					printf("friend!\n");
				}
			} else 
			if (n < m) {
				if (isin(ht, hs, n, m)) {
					printf("my teacher!\n");
				} else {
					printf("senior!\n");
				}
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
