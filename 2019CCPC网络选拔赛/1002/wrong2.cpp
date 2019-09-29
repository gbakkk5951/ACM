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
int inline lb(int a) {
	return a & (-a);
}
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
int n;
struct Node {
	Node *s[2];
	int sum;
}pool[(int)2e6], null;

Node *new_() {
	pool[pidx].s[0] = pool[pidx].s[1] = &null;
	pool[pidx].sum = 0;
	return pool[pidx++];
}
int pidx;
Node *root[(int)1e5 + 5];
void insert(int pos, int val) {
	for (int idx = pos; idx <= n; idx += lb(idx)) {
		Node *nd = root[idx];
		int nl = 1, nr = n + 1, mid, spo;
		
		while (1) {
			nd->sum++;
			if (nl == nr) break;
			mid = nl + nr >> 1;
			if (spo = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->s[spo] == null) {
				nd->s[spo] = new_();
			}
			nd = nd->s[spo];
		}
	}
}
void remove(int pos, int val) {
	for (int idx = pos; idx <= n; idx += lb(idx)) {
		Node *nd = root[idx];
		int nl = 1, nr = n + 1, mid, spo;
		while (1) {
			nd->sum--;
			if (nl == nr) break;
			mid = nl + nr >> 1;
			if (spo = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			nd = nd->s[spo];
		}
	}
}
Node *q[23];
int qn;
int val[MXN];
int query(int r, int k) {
	qn = 0;
	for (; r; r -= lb(r)) {
		q[++qn] = root[r];
	}
	int nl = 1, nr = n + 1, mid, sum, spo;
	while (nl != nr) {
		mid = nl + nr >> 1;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += q[i]->sum;
		}
		if (spo = (sum == mid - nl + 1)) {
			nl = mid + 1;
		} else {
			nr = mid;
		}
		for (int i = 1; i <= n; i++) {
			q[i] = q[i]->s[spo];
		}
	}
	return nl;
}
struct _Main {
	char del[(int)1e5 + 5];
	_Main() {
		null.s[1] = null.s[0] = &null;
		int Tn;
		read(Tn);
		int Qn;
		for (int T = 1; T <= Tn; T++) {
			read(n); read(Qn);
			pidx = 0;
			for (int i = 1, t; i <= n; i++) {
				root[i] = new_();
			}
			for (int i = 1, t; i <= n; i++) {
				read(val[i]);
				insert(i, val[i]);
				del[i] = 0;
			}
			int op, t1, t2, lstans = 0;
			for (int Q = 1; Q <= Qn; Q++) {
				read(op);
				if (op == 1) {
					read(t1);
					t1 ^= lstans;
					if (!del[t1]) {
						del[t1] = 1;
						remove(t1, val[i]);
					} else {
						read(t1); read(t2);
						t1 ^= ans; t2 ^= ans;
						printf()
					}
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
