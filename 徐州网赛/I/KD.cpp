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
const int MXN = 1e5 + 5;
struct P {
	int x, y;
}p[MXN * 20];
struct Xg {
	bool operator () (const P &a, const P &b) {
		return a.x < b.x;
	}
}xg;
struct Yg {
	bool operator () (const P &a, const P &b) {
		return a.y < b.y;
	}
}yg;
struct Node {
	int sum, l, r;
}node[MXN * 100];
int nn;
struct KDTree {
	void build(int nd, int nl, int nr, int dim = 0) {
		if (nl == nr) {
			node[nd].sum = 1;
			node[nd].l = min(p[nl].x, p[nl].y);
			node[nd].r = max(p[nl].x, p[nl].y);
			return;
		}
		int mid = nl + nr >> 1;
		if (dim == 0) {
			nth_element(p + nl, p + mid, p + nr + 1, xg);
		} else {
			nth_element(p + nl, p + mid, p + nr + 1, yg);
		}
		node[nd].sum = nr - nl + 1;
		build(ls[nd], nl, mid, dim ^ 1);
		build(rs[nd], mid + 1, nr, dim ^ 1);
		node[nd].l = min(node[ls[nd]].l, node[rs[nd]].l);
		node[nd].r = max(node[ls[nd]].r, node[rs[nd]].r);
	}
	int sum(int nd, int l, int r) {
		if (l <= node[nd].l && node[nd].r <= r) return node[nd].sum;
		
		int ret = 0;
		if (node[ls[nd]].l <= r && node[ls[nd]].r >= l) ret += sum(ls[nd], l, r);
		if (node[rs[nd]].l <= r && node[rs[nd]].r >= l) ret += sum(rs[nd], l, r);
		return ret;
	}
}tree;

int pn;

struct _Main {
	int pos[MXN];
	_Main() {
		int n, Qn;
		read(n); read(Qn);
//		n = 1e5; Qn = 1e5;
		int a;
		for (int i = 1; i <= n; i++) {
			read(a);
//			a = n - i + 1;
			pos[a] = i;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 2; i * j <= n; j++) {
				p[++pn] = (P) {pos[i], pos[i * j]};
			}
		}
		tree.build(1, 1, pn);
		int l, r;
		for (int Q = 1; Q <= Qn; Q++) {
			read(l); read(r);
//			l = rand() % n + 1;
//			r = rand() % n + 1;
//			if (l > r) swap(l, r);
			printf("%d\n", tree.sum(1, l, r));
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
