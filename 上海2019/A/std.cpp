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
const int MXN = 1e5 + 10;
lld arr[MXN * 17], idx;
struct Tree {
	lld tag[MXN * 70], mx[MXN * 70];
	void push(int nd ) {
	
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			mx[nd] = arr[nl];
			return;
		}	
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		mx[nd] = max(mx[ls[nd]], mx[rs[nd]]);
	}
	void change(int nd, int nl, int nr, int l, int r, lld delta) {
		if (l <= nl && nr <= r) {
			tag[nd] += delta;
			mx[nd] += delta;
			return;
		}
		if (tag[nd]) {
			tag[ls[nd]] += tag[nd];
			mx[ls[nd]] += tag[nd];
			tag[rs[nd]] += tag[nd];
			mx[rs[nd]] += tag[nd];
			tag[nd] = 0;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) change(ls[nd], nl, mid, l, r, delta);
		if (r > mid) change(rs[nd], mid + 1, nr, l, r, delta);
		mx[nd] = max(mx[ls[nd]], mx[rs[nd]]);
	}
	lld query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) return mx[nd];
		if (tag[nd]) {
			tag[ls[nd]] += tag[nd];
			mx[ls[nd]] += tag[nd];
			tag[rs[nd]] += tag[nd];
			mx[rs[nd]] += tag[nd];
			tag[nd] = 0;
		}
		int mid = nl + nr >> 1;
		lld ret = -LINF;
		if (l <= mid) ret = query(ls[nd], nl, mid, l, r);
		if (r > mid) ret = max(ret, query(rs[nd], mid + 1, nr, l, r));
		return ret;
	}
}tree;
struct _Main {
	int u[MXN], v[MXN], w[MXN];
	char mark[MXN];
	int cho, chosize;
	int totsize;
	int h[17][MXN], core[17][MXN], subf[17][MXN], l[17][MXN], r[17][MXN];
	int getsize(int nd, int fa = 0) {
		int ret = 0, mx = 0, t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((mark[t = edge[e][DST]] == -1) && (t != fa)) {
				ret += t = getsize(t, nd);
				mx = max(mx, t);
			}
		}
		if ((t = max(mx, totsize - ret - 1)) < chosize) {
			chosize = t;
			cho = nd;
		}
		return ret + 1;
	}
	void dfs(int nd, int c, int depth, int fa = 0, lld sum = 0, int sf = 0) {
		core[depth][nd] = c;
		arr[l[depth][nd] = ++idx] = sum;
		subf[depth][nd] = sf;
		h[depth][nd] = h[depth][fa] + 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa && mark[t] == -1) {
				dfs(t, c, depth, nd, sum + edge[e][VAL], sf ? sf : t);
			}
		}
		r[depth][nd] = idx;
	}
	void fenzhi(int nd = 1, int depth = 0) {
		chosize = INF;
		cho = 0;
		getsize(nd);
		nd = cho;
		mark[nd] = depth;
		dfs(nd, nd, depth);
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (mark[t = edge[e][DST]] == -1) {
				totsize = getsize(t);
				if (totsize == 1) {
					mark[t] = depth;
				} else {
					fenzhi(t, depth + 1);
				}
			}
		}
	}
	int n;
	int eidx;
	int head[MXN], edge[MXN << 1][3];
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	lld query(int nd) {
		lld ret = 0, sum;
		for (int d = mark[nd]; d >= 0; d--) {
			if (nd == core[d][nd]) {
				sum = tree.query(1, 1, idx, l[d][nd], r[d][nd]);
			} else {
				sum = 0;
				if (r[d][subf[d][nd]] < r[d][core[d][nd]]) {
					sum = tree.query(1, 1, idx, r[d][subf[d][nd]] + 1, r[d][core[d][nd]]);
				}
				sum = max(sum, tree.query(1, 1, idx, l[d][core[d][nd]], l[d][subf[d][nd]] - 1));
				sum += tree.query(1, 1, idx, l[d][nd], l[d][nd]);
			}
			ret = max(ret, sum);
		}
		return ret;
	}
	void change(int id, int val) {
		int delta = val - w[id];
		int a = u[id], b = v[id];
		w[id] = val;
		for (int d = min(mark[a], mark[b]); d >= 0; d--) {
			if (h[d][a] > h[d][b]) swap(a, b);
			tree.change(1, 1, idx, l[d][b], r[d][b], delta);
		}
	}
	_Main() {
		int Qn;
		read(n);
		if (n == 1) {
			read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				printf("0\n");
			}
			return;
		}
		for (int i = 1; i <= n - 1; i++) {
			read(u[i]); read(v[i]); read(w[i]);
			add(u[i], v[i], w[i]);
			add(v[i], u[i], w[i]);
		}
		memset(mark + 1, -1, n * sizeof(char));
		totsize = n;
		fenzhi();
		tree.build(1, 1, idx);
		read(Qn);
		char op[5];
		int a, b;
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'Q') {
				read(a);
				printf("%lld\n", query(a));
			} else 
			if (op[0] == 'C') {
				read(a); read(b);
				change(a, b);
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
