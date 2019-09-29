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
const int MXN = 1e3;
/*
11111111 = Null
	0000 = From
   0     = A
  0		 = B
*/
struct _Main {
	inline char getfrom(char d) {
		return d & 15;
	}
	inline char getA(char d) {
		return (d >> 4) & 1;
	}
	inline char getB(char d) {
		return (d >> 5) & 1;
	}
	inline char getArem(char s) {
		return s & 3;
	}
	inline char getBrem(char s) {
		return (s >> 2) & 3;
	}
	inline char coms(char Arem, char Brem) {
		return Arem | (Brem << 2);
	}
	inline char comd(char from, char A, char B) {
		return from | (A << 4) | (B << 5);
	}
	void ask(lld dst) {
		if (dst % 3 == 0) {
			printf("1 %lld\n", dst);
			return;
		}
		char dp[65][17];
		int mxpow;
		char ds, dd, arem, brem;
		memset(dp[0], -1, 17 * sizeof(char));
		dp[0][0] = 0;
		for (mxpow = 0; (1LL << mxpow) <= dst; mxpow++) {
			memset(dp[mxpow + 1], -1, 17 * sizeof(char));
			for (int s = 0; s < 17; s++) {
				if (dp[mxpow][s] != -1) {
					if (((dst >> mxpow) & 1) == 0) {
						ds = s;
						dd = comd(s, 0, 0);
						dp[mxpow + 1][ds] = dd;
					} else {
						arem = getArem(s), brem = getBrem(s);
						//A 1 B 0
						ds = coms((arem + (1LL << mxpow)) % 3, brem);
						dd = comd(s, 1, 0);
						dp[mxpow + 1][ds] = dd;
						//A 0 B 1
						ds = coms(arem, (brem + (1LL << mxpow)) % 3);
						dd = comd(s, 0, 1);
						dp[mxpow + 1][ds] = dd;
						//A 1 B 1
						ds = coms((arem + (1LL << mxpow)) % 3, (brem + (1LL << mxpow)) % 3);
						dd = comd(s, 1, 1);
						dp[mxpow + 1][ds] = dd;
					}
				}
			}
		}
		lld a = 0, b = 0;
		for (char now, s = 0; mxpow > 0; mxpow--) {
			now = dp[mxpow][s];
			a |= (lld)getA(now) << (mxpow - 1);
			b |= (lld)getB(now) << (mxpow - 1);
			s = getfrom(now);
		}
		printf("2 %lld %lld\n", a, b);
	}
	int cnt;
	_Main() {
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			lld a;
			read(a);
			ask(a);
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
