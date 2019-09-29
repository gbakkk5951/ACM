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
const int MXN = 1e6 + 10;
struct _Main {
	int n, Qn;
	int op[MXN], x[MXN];
	int srt[MXN << 1];
	int r[MXN << 1], l[MXN << 1];
	char v[MXN << 1];
	int getr(int nd) {
		if (!v[nd]) return nd;
		return r[nd] = getr(r[nd]);
	}
	void del(int nd) {
		if (v[nd] == 0) {
			v[nd] = 1;
			r[l[nd]] = r[nd];
			l[r[nd]] = l[nd];
		}
	}
	int sidx;
	_Main() {
		read(n); read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op[Q]); read(x[Q]);
			srt[++sidx] = x[Q];
			srt[++sidx] = x[Q] + 1;
		}
		srt[++sidx] = n + 1;
		sort(srt + 1, srt + sidx + 1);
		sidx = unique(srt + 1, srt + sidx + 1) - srt - 1;
		for (int i = 1; i <= sidx; i++) {
			l[i] = i - 1;
			r[i] = i + 1;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			x[Q] = lower_bound(srt + 1, srt + sidx + 1, x[Q]) - srt;
			if (op[Q] == 1) del(x[Q]);
			else {
				int t = getr(x[Q]);
				if (t == sidx) {
					printf("-1\n");
				} else {
					printf("%d\n", srt[t]);
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
