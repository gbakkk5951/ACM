#pragma GCC optimize(2)
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
struct Matrix {
	lld a[2][2];
	lld & operator () (int x, int y) {
		return a[x][y];
	}
	Matrix operator * (Matrix &b) {
		Matrix ret;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ret(i, j) = 0;
				for (int k = 0; k < 2; k++) {
					ret(i, j) += a[i][k] * b(k, j);
				}
				ret(i, j) %= MOD;
			}
		}
		return ret;
	}
}one;
typedef Matrix ma;
struct _Main {
	ma pow1[(int)1e5 + 1], pow2[(int)1e4 + 1];
	_Main() {
		one(0, 0) = one(1, 1) = 1;
		pow1[0] = pow2[0] = one;
		pow1[1](0, 0) = 3; pow1[1](0, 1) = 2;
		pow1[1](1, 0) = 1; pow1[1](1, 1) = 0;
		for (int i = 2; i <= 100000; i++) {
			pow1[i] = pow1[i - 1] * pow1[1];
		}
		pow2[1] = pow1[100000];
		for (int i = 1; i <= 10000; i++) {
			pow2[i] = pow2[i - 1] * pow2[1];
		}
		int Qn;
		
		lld lsta = 0, lstn = 0, ans = 0, a;
		read(Qn); read(lstn);
		lld n;
		for (int Q = 1; Q <= Qn; Q++) {
			lstn = n = lstn ^ (lsta * lsta);
			if (n <= 1) {
				a = n;
			} else {
				--n;
				n %= MOD - 1;
				if (n <= 100000) {
					a = pow1[n](0, 0);
				} else {
					a = (pow1[n % 100000](0, 0) * pow2[n / 100000](0, 0) + pow1[n % 100000](0, 1) * pow2[n / 100000](1, 0)) % MOD;
				}
			}
			ans ^= a;
			lsta = a;
		}
		printf("%lld", ans);
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
