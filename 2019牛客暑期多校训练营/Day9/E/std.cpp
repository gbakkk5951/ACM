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
llu node[270000][5];
struct Tree {
	void update(int nd) {
		for (int i = 0; i <= 4; i++) {
			llu tmp = 0;
			for (int j = 0; j <= i; j++) {
				tmp += node[ls[nd]][j] * node[rs[nd]][i - j];
			}
			node[nd][i] = tmp;
		}
	}
	void init(int nd, int nl, int nr) {
		if (nl == nr) {
			node[nd][0] = node[nd][1] = 1;
			return;
		}
		int mid = nl + nr >> 1;
		init(ls[nd], nl, mid);
		init(rs[nd], mid + 1, nr);
		update(nd);
	}
	void change(int nd, int nl, int nr, int pos, int val) {
		if (nl == nr) {
			node[nd][1] = val;
			return;
		}
		int mid = nl + nr >> 1;
		if (pos <= mid) change(ls[nd], nl, mid, pos, val);
		else change(rs[nd], mid + 1, nr, pos, val);
		update(nd);
	}
}tree;
struct _Main {
	int n;
	int s[MXN], f[MXN];
	int getf(int a) {
		return f[a] ? f[a] = getf(f[a]) : a;
	}
	void merge(int a, int b) {
		tree.change(1, 1, n, a, 0);
		tree.change(1, 1, n, b, s[b] += s[a]);
		f[a] = b;
	}
	_Main() {
		int Qn, a, b;
		read(n); read(Qn);
		tree.init(1, 1, n);
		printf("%llu\n", node[1][4]);
		fill(s + 1, s + n + 1, 1);
		for (int Q = 1; Q <= Qn; Q++) {
			read(a); read(b);
			if ((a = getf(a)) != (b = getf(b))) {
				merge(a, b);
			}
			printf("%llu\n", node[1][4]);
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
