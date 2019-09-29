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
const int MXN = 2e3 + 5;
struct Node {
	lld s, ls, rs, mx;
}node[4100], null;
struct Tree {
	void clear(int nd, int nl, int nr) {
		node[nd] = null;
		if (nl == nr) return;
		int mid = nl + nr >> 1;
		clear(ls[nd], nl, mid);
		clear(rs[nd], mid + 1, nr);
	}
	void update(int nd) {
		node[nd].ls = max(node[ls[nd]].ls, node[ls[nd]].s + node[rs[nd]].ls);
		node[nd].rs = max(node[rs[nd]].rs, node[rs[nd]].s + node[ls[nd]].rs);	
		node[nd].s = node[ls[nd]].s + node[rs[nd]].s;
		node[nd].mx = max(node[ls[nd]].mx, max(node[rs[nd]].mx, node[ls[nd]].rs + node[rs[nd]].ls));
	}
	void add(int nd, int nl, int nr, int pos, int val) {
		if (nl == nr) {
			node[nd].s = node[nd].ls = node[nd].rs = (node[nd].mx += val);
			return;
		}
		int mid = nl + nr >> 1;
		if (pos <= mid) add(ls[nd], nl, mid, pos, val);
		else add(rs[nd], mid + 1, nr, pos, val);
		update(nd);
	}
}tree;
struct _Main {
	int x[MXN],	s[MXN], y[MXN], w[MXN];
	int n;
	int xn, yn;
	int head[MXN], nxt[MXN];
	void lsh(int a[], int &sn) {
		memcpy(s + 1, a + 1, n * sizeof(int));
		sort(s + 1, s + n + 1);
		sn = unique(s + 1, s + n + 1) - s - 1;
		for (int i = 1; i <= n; i++) {
			a[i] = lower_bound(s + 1, s + sn + 1, a[i]) - s;
		}
	}
	void add(int y, int mul) {
		for (int nd = head[y]; nd; nd = nxt[nd]) {
			tree.add(1, 1, xn, x[nd], w[nd] * mul);
		}
		ans = max(ans, node[1].mx);
	}
	lld ans;
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			ans = 0;
			read(n);
			for (int i = 1; i <= n; i++) {
				read(x[i]); read(y[i]); read(w[i]);
	//			ans = max(ans, (lld)w[i]); No, there might be some on the same position
			}
			lsh(x, xn); lsh(y, yn);
			memset(head + 1, 0, yn * sizeof(int));
			for (int i = 1; i <= n; i++) {
				nxt[i] = head[y[i]];
				head[y[i]] = i;
			}
			tree.clear(1, 1, xn);
			for (int i = 1; i <= yn; i++) {
				add(i - 1, -1);
				if (i & 1) {
					for (int j = i; j <= yn; j++) {
						add(j, +1);
					}
				} else {
					for (int j = yn; j > i; j--) {
						add(j, -1);
					}
				}
			}
			printf("%lld\n", ans);
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
