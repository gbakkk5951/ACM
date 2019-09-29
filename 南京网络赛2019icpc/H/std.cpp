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
const int MXE = 500 + 10;
const int MXN = 300 + 10;
struct _Main {
	int eidx;
	int edge[MXE][3];
	int head[MXN];
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	lld dis[MXN];
	int q[MXN * MXE], qt;
	char inq[MXN];
	void push(int a, lld d) {
		dis[a] = d;
		if (!inq[a]) {
			q[++qt] = a;
			inq[a] = 1;
		}
	}
	void SPFA(int src) {
		memset(dis, 63, n * sizeof(lld));
		push(src, 0);
		int nd, t;
		lld c;
		for (int i = 1; i <= qt; i++) {
			nd = q[i];
			inq[nd] = 0;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (dis[t = edge[e][DST]] > (c = dis[nd] + edge[e][VAL])) {
					push(t, c);
				}
			}
		}
		qt = 0;
	}
	int n, m, Tn;
	_Main() {
		int a, b, c;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			for (int i = 1; i <= m; i++) {
				read(a); read(b); read(c);
				add(a, b, c);
			}
			for (int i = 1; i <= 6; i++) {
				read(a); read(b);
				SPFA(b);
				add(a, b, -dis[a]);
				printf("%lld\n", -dis[a]);
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
