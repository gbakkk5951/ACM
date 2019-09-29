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
const int MXN = 2e5 + 10;
struct Node {
	int size;
	lld sum;
}node[(int)5.3e5];
int n, m, sn, a[MXN], srt[MXN];
struct Tree {
	int query(int nd, int nl, int nr, lld &rem) {
		if (rem >= node[nd].sum) {
			rem -= node[nd].sum;
			return node[nd].size;
		} else
		if (nl == nr) {
			int val = node[nd].sum / node[nd].size;
			val = (rem + val - 1) / val;
			rem = 0;
			return val;
		}
		int mid = nl + nr >> 1, ret = query(ls[nd], nl, mid, rem);
		if (rem) ret += query(rs[nd], mid + 1, nr, rem);
		return ret;
	}
	inline int query(lld val) {
		return query(1, 1, sn, val);
	}
	void insert(int pos, int val) {
		int nd = 1, nl = 1, nr = sn, mid;
		while (1) {
			node[nd].size++;
			node[nd].sum += val;
			if (nl == nr) return;
			mid = nl + nr >> 1;
			if (pos <= mid)  {
				nr = mid, nd = ls[nd];
			} else {
				nl = mid + 1, nd = rs[nd];
			}
		}
	}
}tree;
struct _Main {
	lld sum;
	int lb(int a) {
		int l = 1, r = sn, mid;
		while (l != r) {
			mid = l + r >> 1;
			if (srt[mid] > a) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			int pow = 0;
			while ((1 << pow) <= (sn << 1)) ++pow;
			memset(node, 0, (1 << pow) * sizeof(Node));
			read(n); read(m);
			for (int i = 1; i <= n; i++) {
				read(a[i]);
			}
			memcpy(srt + 1, a + 1, n * sizeof(int));
			sort(srt + 1, srt + n + 1, greater<int>());
			sn = unique(srt + 1, srt + n + 1) - srt - 1;
			sum = 0;
			for (int i = 1; i <= n; i++) {
				a[i] = lb(a[i]);
			}
			for (int i = 1; i <= n; i++) {
				sum += srt[a[i]];
				if (sum > m) {
					printf("%d ", tree.query(sum - m));
				} else {
					printf("0 ");
				}
				tree.insert(a[i], srt[a[i]]);
			}
			printf("\n");
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
