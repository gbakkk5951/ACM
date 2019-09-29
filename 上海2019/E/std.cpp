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
struct Matrix {
	lld data[2][2];
	lld * operator [] (int x) {
		return data[x];
	}
	void clear() {
		memset(this, 0, sizeof(Matrix));
	}
	Matrix operator * (Matrix &b) {
		Matrix ret;
		ret.clear();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				lld mul = data[i][j];
				for (int k = 0; k < 2; k++) {
					(ret[i][k] += mul * b[j][k]) %= MOD;
				}
			}
		}
		return ret;
	}
};
typedef Matrix ma;
struct _Main {
	ma one, base, now;
	_Main() {
		int Tn;
		for (int i = 0; i < 2; i++) {
			one[i][i] = 1;
		}
		read(Tn);
		lld n;
		int m;
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			base[0][0] = base[1][1] = m - m / 2;
			base[0][1] = base[1][0] = m / 2;
			now = one;
			while (n) {
				if (n & 1) now = now * base;
				if (n >>= 1) base = base * base;
			}
			printf("%lld\n", now[1][1]);
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
