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
typedef pair<int, int> p;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
priority_queue<p, vector<p>, greater<p> > heap;
const int MXN = 1e3 + 10, MXM = 1e6 + 1e3 + 10;
struct _Main {
	int head[MXM], edge[MXM << 2][3];
	int eidx;
	inline int tr(int nd, int lay) {
		return nd + lay * n;
	}
	inline void dir_add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	inline void add(int a, int b, int c) {
		dir_add(a, b, c);
		dir_add(b, a, c);
	}
	int n, m, S, T, K;
	int dis[MXM];
	inline p mp(int a, int b) {
		return (p) {a, b};
	}
	void dijkstra() {
		memset(dis + 1, 0x3f, n * (K + 1) * sizeof(int));
		dis[S] = 0;
		heap.push(mp(0, S));
		int nd, d, t, v;
		while (!heap.empty()) {
			nd = heap.top().second;
			d = heap.top().first;
			heap.pop();
			if ((nd - 1) % n + 1 == T) {
				break;
			}
			if (d != dis[nd]) {
				continue;
			}
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (dis[t = edge[e][DST]] > (v = edge[e][VAL] + d)) {
					dis[t] = v;
					heap.push(mp(v, t));
				}
			}
		} 
	}
	_Main() {
		read(n); read(m); read(S); read(T); read(K);
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			for (int j = 0; j <= K; j++) {
				add(tr(a, j), tr(b, j), c);
				if (j < K) {
					dir_add(tr(a, j), tr(b, j + 1), 0);
					dir_add(tr(b, j), tr(a, j + 1), 0);
				}
			}
		}
		dijkstra();
		int ans = INF;
		for (int i = 0; i <= K; i++) {
			ans = min(ans, dis[tr(T, i)]);
		}
		printf("%d", ans);
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
