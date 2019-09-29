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
const int MXN = 2e5 + 5;



struct df {
	lf pos, da, db;
	bool friend operator < (const df &a, const df &b) {
		return a.pos < b.pos;
	}
	void operator += (const df &b) {
		return (df) {max(pos, b.pos), da, db};
	}
}org[MXN];
vector<df> node[(int)5.4e5];
int q[50], qt;
struct Tree {
	void build(int nd, int nl, int nr) {
		for (int i = nl; i <= nr; i++) {
			node[nd].push_back(org[i]);
		}
		if (nl == nr) return;
		sort(node[nd].begin(), node[nd].end());
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
	}
	void locate(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			q[++qt] = nd;
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) locate(ls[nd], nl, mid, l, r);
		if (r < mid) locate(rs[nd], mid + 1, nr, l, r);
	}
}tree;


df srt[MXN]
struct _Main {
	_Main() {
		
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
