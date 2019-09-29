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
	Node *l, *r, *u, *d;
	int id, size;
}pool[MXN << 2], _null;
Node *null;
int pidx;
Node *new_(int id = 0) {
	Node *nd = &pool[pidx++];
	nd->l = nd->r = nd->u = nd->d = null;
	nd->size = 1;
	nd->id = id;
	return nd;
}
struct SkipList {
	Node *L[MXH];
	Node *R[MXH];
	inline void mku(Node *u, Node *d) {
		d->u = u;
		u->d = d;
	}
	inline void lk(Node *l, Node *r) {
		l->r = r;
		r->l = l;
	}
	inline void dislink(Node *nd) {
		lk(nd->l, nd->r);
	}
	void init() {
		pidx = 0;
		null = &_null;
		null->l = null->r = null->u = null->d = null;
		for (int i = 0; i < MXH; i++) {
			L[i] = new_(), R[i] = new_();
			lk(L[i], R[i]);
			if (i) {
				mku(L[i], L[i - 1]);
				mku(R[i], R[i - 1]);
			}
			L[i]->size = R[i]->size = 0;
		}
	}
	void push(int id) {
		Node *nd = new_(id), *tmp;
		link(R[0]->l, nd);
		link(nd, R[0]);
		for (int i = 1; i < MXH && !(rand() & 3); i++) {
			tmp = new_(id);
			mku(tmp, nd);
			nd = tmp;
			link(R[i]->l, nd);
			link(nd, R[i]);
		}
		while(nd->l != null || nd->u != null) {
			while(nd->l != null && nd->u == null) {
				nd = nd->l;
			}
			if (nd->u != null) {
				nd = nd->u;
				nd->size++;
			}
		}
	}
	Node* locate(int rk) {
		Node *nd = L[MXH - 1];
		while (nd->d) {
			while(rk > nd->size) {
				rk -= nd->size;
				nd = nd->r;
			}
			nd = nd->d;
		}	
		return nd;
	}
	void erase(Node *nd) {
		Node *lst;
		while (nd != null) {
			lst = nd->l;
			dislink(nd);
			nd = nd->u;
		}
		while(nd->l != null || nd->u != null) {
			while(nd->l != null && nd->u == null) {
				nd = nd->l;
			}
			if (nd->u != null) {
				nd = nd->u;
				nd->size--;
			}
		}
	}
}sl;
int size;
struct _Main {
lld srt[MXN], id[MXN];
int n, m;
char opt[MXN], v[MXN];
	int lb(int id) {
		int l = 1, r = n, mid;
		while (l != r) {
			mid = l + r >> 1;
			if (srt[mid] < id) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
	void init() {
		pidx = 0;
	}
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			sl.init();
			int Qn;
			read(Qn); read(m);
			for (int Q = 1; Q <= Qn; Q++) {
				read(opt[Q]);
				read(id[Q]);
				read(v[Q]);
			}
			memcpy(srt + 1, id + 1, Qn * sizeof(lld));
			sort(srt + 1, srt + Qn + 1);
			n = unque(srt + 1, srt + Qn + 1) - srt - 1;
			for (int i = 1; i <= Qn; i++) {
				id[i] = lb(id[i]);
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
