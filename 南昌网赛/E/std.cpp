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
struct _Main {
	int getans(int n, int m, int k) {
		int len = n;
		if (k == 1) return 1;
		len--; k--;
		int pos = (-(k - 1) + len) % len, t;
		while (1) {
			//走到末尾
			t = (len - pos) / (m + 1);
			pos += t * m;
			len -= t;
			pos %= len;
			//走一个m 包括越好几圈才放东西
			pos = (pos + m) % len;
			--len;
			if (pos == 0) break;
			pos %= len;
		}
		return n - len;
	}
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			int n, m, k, Qn;
			read(n); read(m);
			read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				read(k);
				printf("%d\n", getans(n, m, k));
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
