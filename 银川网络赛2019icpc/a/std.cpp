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
const int MXN = 5e6 + 10;
struct _Main {
	u SA, SB, SC;
	u rng61() {
		SA ^= SA << 16;
		SA ^= SA >> 5;
		SA ^= SA << 1;
		u t = SA;
		SA = SB;
		SB = SC;
		SC ^= t ^ SA;
		return SC;
	}
	void gen() {
		int n, p, q, m;
		scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
		for (int i = 1; i <= n; i++) {
			if (rng61() % (p + q) < p) {
				PUSH(rng61() % m + 1);
			} else {
				POP();
			}
			ans ^= (lld)i * s[st];
		}
	}
	int q[MXN], qt; 
	int s[MXN], st;
	
	void PUSH(int a) {
		if (s[st] <= a) {
			s[++st] = a;
		}
		q[++qt] = a;
	}	
	void POP() {
		if (qt) {
			st -= s[st] == q[qt--];
		}
	}
	lld ans;
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			ans = st = qt = 0;
			gen();
			printf("Case #%d: %lld\n", T, ans);
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

































