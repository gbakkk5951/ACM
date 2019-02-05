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
const int SUM = 0, TAG = 1;
lf data[300010];
struct Tree {
	com node[1050000][2];
	void mul(int nd, const com &a) {
		node[nd][SUM] *= a;
		node[nd][TAG] *= a;
	}
	inline void push(int nd) {
		mul(ls[nd], node[nd][TAG]);
		mul(rs[nd], node[nd][TAG]);
		node[nd][TAG] = (com) {1.0, 0.0};
	}
	inline void update(int nd) {
		node[nd][SUM] = node[ls[nd]][SUM] + node[rs[nd]][SUM];
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			node[nd][SUM] = (com) {cos(data[nl]), sin(data[nl])};
		} else {
			build(ls[nd], nl, nl + nr >> 1);
			build(rs[nd], (nl + nr >> 1) + 1, nr);
			update(nd);
		}
		node[nd][TAG] = (com) {1.0, 0.0};
//		printf("B[%d, %d] = (%lf, %lf)\n", nl, nr, node[nd][SUM].real(), node[nd][SUM].imag());
	}
	com query(int nd, int nl, int nr, int l, int r) {
//		if (l <= nl && nr <= r) {
//			printf("Q[%d, %d] = (%lf, %lf)\n", max(nl, l), min(r, nr), node[nd][SUM].real(), node[nd][SUM].imag());
//		}
		if (l <= nl && nr <= r) return node[nd][SUM];
		push(nd);
		com ret = (com) {0.0, 0.0};
		int mid = nl + nr >> 1;
		if (l <= mid) ret += query(ls[nd], nl, mid, l, r);
		if (r > mid) ret += query(rs[nd], mid + 1, nr, l, r);
//		printf("Q[%d, %d] = (%lf, %lf)\n", max(nl, l), min(r, nr), ret.real(), ret.imag());
		return ret;
	}
	void change(int nd, int nl, int nr, int l, int r, const com &a) {
		if (l <= nl && nr <= r) {
			mul(nd, a);
//			printf("C[%d, %d] = (%lf, %lf)\n", nl, nr, node[nd][SUM].real(), node[nd][SUM].imag());
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		if (l <= mid) change(ls[nd], nl, mid, l, r, a);
		if (r > mid) change(rs[nd], mid + 1, nr, l, r, a);
		update(nd);
	//	printf("C[%d, %d] = (%lf, %lf)\n", max(nl, l), min(r, nr), node[nd][SUM].real(), node[nd][SUM].imag());
	}
}tree;

struct _Main {
	_Main() {
		/*
		int nd = 1, nl = 1, nr = 300000;
		while (nl != nr) {
			nl = (nl + nr >> 1) + 1;
			nd = nd << 1 | 1;
		}
		printf("%d\n", nd);
		*/
	//	printf("(%lf)\n", sin(-7.0) + sin(-9.0));
//		freopen("sinandcos_ex3.in", "r", stdin);
//		freopen("sinandcos_ex3.out", "w", stdout);
		
		int n, Qn, tp, l, r;
		lf a;
		com c;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &data[i]);
		}
		
		tree.build(1, 1, n);
		
		for (int Q = 1; Q <= Qn; Q++) {
			read(tp); read(l); read(r);
			switch (tp) {
				case 1: {
					printf("%.3Lf\n", (Lf) tree.query(1, 1, n, l, r).imag());
					break;
				}
				case 2: {
					printf("%.3Lf\n", (Lf) tree.query(1, 1, n, l, r).real());
					break;
				}
				case 3: {
					scanf("%lf", &a);
					c = (com) {cos(a), sin(a)};
					tree.change(1, 1, n, l, r, c);
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
