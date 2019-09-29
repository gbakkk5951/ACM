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
struct Node {
	int sum, l, r;
}node[MXN * 200];
int nidx;
int n, Qn;
int new_(int org) {
	node[++nidx] = node[org];
	node[nidx].sum++;
	return nidx;
}
int root[MXN];
struct SegTree {
	void insert(int rt, int pos) {
		if (root[rt]) {
			root[rt] = new_(root[rt]);
		} else {
			root[rt] = new_(root[rt - 1]);
		}
		int nl = 1, nr = n, mid, nd = root[rt];
		while (nl != nr) {
			mid = nl + nr >> 1;
			if (pos <= mid) {
				nd = node[nd].l = new_(node[nd].l);
				nr = mid;
			} else {
				nd = node[nd].r = new_(node[nd].r);
				nl = mid + 1;
			}
		}
	}
	int query(int rl, int rr, int nl, int nr, int ql, int qr) {
		if (rl == rr || ql <= nl && nr <= qr) return node[rr].sum - node[rl].sum;
		int mid = nl + nr >> 1, ret = 0;
		if (ql <= mid) ret += query(node[rl].l, node[rr].l, nl, mid, ql, qr);
		if (mid < qr) ret += query(node[rl].r, node[rr].r, mid + 1, nr, ql, qr);
		return ret;
	}
}tree;

int pn;

struct _Main {
	int pos[MXN];
	int head[MXN];
	int edge[MXN * 20][2];
	int eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	_Main() {
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
				add(pos[i], pos[i * j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int e = head[i]; e; e = edge[e][NXT]) {
				tree.insert(i, edge[e][DST]);
			}
			if (head[i] == 0) root[i] = root[i - 1];
		}
		
		int l, r;
		for (int Q = 1; Q <= Qn; Q++) {
			read(l); read(r);
//			l = rand() % n + 1;
//			r = rand() % n + 1;
//			if (l > r) swap(l, r);
			printf("%d\n", tree.query(root[l - 1], root[r], 1, n, l, r));
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
