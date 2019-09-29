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
const int MXN = 3e5 * 3 + 10;
struct fd {//FuncDelta
	lld pos, da, db;
	bool friend operator < (const fd &a, const fd &b) {
		return a.pos < b.pos;
	}
}srt[MXN];
struct _Main {
	lld a, b; //f(x) = ax + b
	lld ans = 0;
	int n;

	_Main() {
		lld l, r;
		read(n);
		for (int i = 0; i < n; i++) {
			read(l); read(r);
			l <<= 1, r <<= 1;
			srt[i * 3 + 1] = {l, 2, -2 * l};
			srt[i * 3 + 2] = {l + r >> 1, -4, 2 * r + 2 * l};
			srt[i * 3 + 3] = {r, 2, -2 * r};
		}
		sort(srt + 1, srt + 3 * n + 1);
		for (int i = 1; i <= 3 * n; i++) {
			a += srt[i].da, b += srt[i].db;
			ans = max(ans, a * srt[i].pos + b);
		}
		printf("%lld", ans / 2);
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
