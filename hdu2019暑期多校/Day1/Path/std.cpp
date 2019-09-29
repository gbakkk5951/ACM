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
const int MXN = 1e4 + 10, MXE = 1e4 + 10;
int n, m;
struct Flow {
	int eidx;
	int head[MXN], edge[MXE << 1][3], layer[MXN];
	int now[MXN];
	int q[MXN];
	inline void dir_add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][FLOW] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	inline void add(int a, int b, int c) {
		dir_add(a, b, c);
		dir_add(b, a, 0);
	}
	void init() {
		eidx = 1;
		memset(head + 1, 0, n * sizeof(int));
	}
	int getlayer() {
		memset(layer + 1, 0, n * sizeof(int));
		int qh = -1, nd, t;
		layer[1] = 1;
		q[++qh] = 1;
		for (int i = 0; i <= qh; i++) {
			nd = q[i];
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (edge[e][FLOW] && !layer[t = edge[e][DST]]) {
					layer[t] = layer[nd] + 1;
					q[++qh] = t;
				}
			}
		}
		return layer[n];
	}
	lld getflow(int nd, lld mx_flow) {
		if (nd == n) return mx_flow;
		lld rem = mx_flow, tmp;
		int e, t;
		for (e = now[nd]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW] && layer[t = edge[e][DST]] > layer[nd]) {
				tmp = getflow(t, min(rem, (lld)edge[e][FLOW]));
				edge[e][FLOW] -= tmp;
				edge[e ^ 1][FLOW] += tmp;
				if ((rem -= tmp) == 0) {
					break;
				}
			}
		}
		now[nd] = e;
		return mx_flow - rem;
	}
	lld run() {
		lld ret = 0;
		while (getlayer()) {
			memcpy(now + 1, head + 1, n * sizeof(int));
			ret += getflow(1, LINF);
		}
		return ret;
	}
}flow;
typedef pair<lld, int> p;
priority_queue<p, vector<p>, greater<p>> heap;
struct _Main {
	int head[MXN], edge[MXE][3], eidx;
	lld dis[MXN];
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	inline p mp(lld a, int b) {
		return (p) {a, b};
	}
	void dijkstra() {
		memset(dis + 1, 0x3f, n * sizeof(lld));
		dis[1] = 0;
		heap.push(mp(0, 1));
		int nd, t;
		lld v;
		p tmp;
		while (!heap.empty()) {
			tmp = heap.top();
			heap.pop();
			if (tmp.first != (v = dis[nd = tmp.second])) continue;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (v + edge[e][VAL] < dis[t = edge[e][DST]]) {
					heap.push(mp(dis[t] = v + edge[e][VAL], t));
				}
			}
		}
	}
	_Main() {
		int Tn, a, b, c, t;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			memset(head + 1, 0, n * sizeof(int));
			eidx = 0;
			for (int i = 1; i <= m; i++) {
				read(a); read(b); read(c);
				add(a, b, c);
			}
			dijkstra();
			flow.init();
			for (int nd = 1; nd <= n; nd++) {
				for (int e = head[nd]; e; e = edge[e][NXT]) {
					if (dis[t = edge[e][DST]] == dis[nd] + edge[e][VAL]) {
						flow.add(nd, t, edge[e][VAL]);
					}
				}
			}
			printf("%lld\n", flow.run());
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
