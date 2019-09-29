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
const int MXN = 4e5 + 11;
struct Node {
	int size, tag;
	lld sum;
}node[2120000];
int srt[MXN << 1], sidx;
struct Tree {
	void update(int nd) {
		node[nd].sum = node[ls[nd]].sum + node[rs[nd]].sum;
	}
	void push(int nd) {
		if (node[nd].tag) {
			node[ls[nd]].sum += (lld)node[nd].tag * node[ls[nd]].size;
			node[rs[nd]].sum += (lld)node[nd].tag * node[rs[nd]].size;
			node[ls[nd]].tag += node[nd].tag;
			node[rs[nd]].tag += node[nd].tag;
			node[nd].tag = 0;
		}
	}
	
	void build(int nd, int nl, int nr) {
		node[nd].size = srt[nr + 1] - srt[nl];
		if (nl == nr) return;
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
	}
	void add(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && r >= nr) {
			node[nd].sum += node[nd].size;
			node[nd].tag++;
			return;
		}
		int mid = nl + nr >> 1;
		push(nd);
		if (l <= mid) add(ls[nd], nl, mid, l, r);
		if (r > mid) add(rs[nd], mid + 1, nr, l, r);
		update(nd);
	}
	void find(int nd, int nl, int nr, lld &rem) {
		if (rem > node[nd].sum) {
			rem -= node[nd].sum;
			return;
		}
		if (nl == nr) {
//			printf("[%d, %d]: ", srt[nl], srt[nr + 1] - 1);
			printf("%d\n", (int)(srt[nl] + (rem - 1) / (node[nd].sum / node[nd].size)));
			rem = 0;
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		find(ls[nd], nl, mid, rem);
		if (rem) find(rs[nd], mid + 1, nr, rem);
	}
}tree;
struct _Main {
	lld x[3], y[3], a1, b1, c1, m1, a2, b2, c2, m2;
	int l[MXN], r[MXN];
	int ef(int a) {
		int l = 1, r = sidx, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (srt[mid] < a) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
	int n;
	_Main() {
		read(n);
		read(x[0]); read(x[1]); read(a1); read(b1); read(c1); read(m1);
		read(y[0]); read(y[1]); read(a2); read(b2); read(c2); read(m2);
		for (int i = 0; i < n; i++) {
			if (i >= 2) {
				x[i % 3] = (a1 * x[(i - 1) % 3] + b1 * x[(i - 2) % 3] + c1) % m1;
				y[i % 3] = (a2 * y[(i - 1) % 3] + b2 * y[(i - 2) % 3] + c2) % m2;
			}
			l[i + 1] = min(x[i % 3], y[i % 3]) + 1;
			r[i + 1] = max(x[i % 3], y[i % 3]) + 1 + 1;
			srt[++sidx] = l[i + 1];
			srt[++sidx] = r[i + 1];
		}
		srt[++sidx] = 1;
		sort(srt + 1, srt + sidx + 1);
		sidx = unique(srt + 1, srt + sidx + 1) - srt - 1;
		for (int i = 1; i <= n; i++) {
			l[i] = ef(l[i]);
		}
		for (int i = 1; i <= n; i++) {
			r[i] = ef(r[i]);
		}
		tree.build(1, 1, sidx - 1);
		lld rem;
		for (int i = 1; i <= n; i++) {
//			printf("throw [%d, %d]:(%d , %d)\n", l[i], r[i] - 1, srt[l[i]], srt[r[i]] - 1);
			tree.add(1, 1, sidx - 1, l[i], r[i] - 1);
			rem = (node[1].sum + 1) >> 1;
			tree.find(1, 1, sidx - 1, rem);
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
