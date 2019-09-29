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
const int MXN = 5e5 + 10;
const int MXH = 10;
struct Node {
	Node *l, *r;
	int id;
}pool[MXN], _null;
Node *null;
int pidx;
Node inline *new_(int id = 0) {
	Node *nd = &pool[pidx++];
	nd->l = nd->r = null;
	nd->id = id;
	return nd;
}
Node *ptr[MXN];
int n, m;
struct List {
	Node *h, *t;
	inline void lk(Node *l, Node *r) {
		l->r = r;
		r->l = l;
	}
	inline void dislink(Node *nd) {
		lk(nd->l, nd->r);
	}
	int size;
	void push(int id) {
		++size;
		Node *nd = new_(id);
		if (size > m) {
			erase(h);
		}
		if (h == null) {
			h = nd;
		}
		lk(t, nd);
		t = nd;
		ptr[id] = nd;
	}
	void erase(Node *nd) {
		--size;
		if (nd == h) {
			h = nd->r;
		}
		if (nd == t) {
			t = nd->l;
		}
		dislink(nd);
		ptr[nd->id] = 0;
	}
	void init() {
		memset(ptr + 1, 0, n * sizeof(Node *));
		null = &_null;
		h = t = null;
		pidx = 0;
		size = 0;
	}
}l;
typedef pair<char, lld> p;
struct _Main {
	p srt[MXN], org[MXN];
	int id[MXN];
	int val[MXN];
	char opt[MXN], v[MXN];
	int lb(p nd) {
		int l = 1, r = n, mid;
		while (l != r) {
			mid = l + r >> 1;
			if (srt[mid] < nd) {
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
			l.init();
			int Qn;
			Node *nd;
			read(Qn); read(m);
			for (int Q = 1; Q <= Qn; Q++) {
				read(opt[Q]);
				org[Q].first = read(org[Q].second);
				read(v[Q]);
			}
			memcpy(srt + 1, org + 1, Qn * sizeof(p));
			sort(srt + 1, srt + Qn + 1);
			n = unique(srt + 1, srt + Qn + 1) - srt - 1;
			for (int i = 1; i <= Qn; i++) {
				id[i] = lb(org[i]);
			}
			for (int Q = 1; Q <= Qn; Q++) {
				if (opt[Q] == 0) {
					if (nd = ptr[id[Q]]) {
						printf("%d\n", val[id[Q]]);
						if (l.t != nd) {
							l.erase(nd);
							l.push(id[Q]);
						}
					} else {
						printf("%d\n", v[Q]);
						val[id[Q]] = v[Q];
						l.push(id[Q]);
					}
				} else {
					if (nd = ptr[id[Q]]) {
						if (v[Q] == 0) {
							printf("%d\n", val[id[Q]]);
						} else
						if (v[Q] == 1) {
							if ((nd = nd->r) != null) {
								printf("%d\n", val[nd->id]);
							} else {
								printf("Invalid\n");
							}
							
						} else
						if (v[Q] == -1) {
							if ((nd = nd->l) != null) {
								printf("%d\n", val[nd->id]);
							} else {
								printf("Invalid\n");
							}
						}
					} else {
						printf("Invalid\n");
					}
				}
			}
		}
	}
template <typename Type>
	char read(Type &a) {
		char t, f = 1, cnt = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
			++cnt;
		}
		a *= f;
		return cnt;
	}
}std;
}
