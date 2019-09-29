#pragma GCC optimize(2)
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
typedef pair<int, int> p;
const int MXN = 1e3 + 5;
const int MXE = 1e6 + 10;
struct _Main {
	int n, m, k, C;
	int loc[MXN];
	int dis[MXN];
	priority_queue<p, vector<p>, greater<p> > heap;
	void dijkstra() {//init before
		while (!heap.empty()) {
			int nd = heap.top().second;
			if (heap.top().first != dis[nd]) {
				heap.pop();
				continue;
			}
			heap.pop();
			for (int e = head[nd], t, v; e; e = edge[e][NXT]) {
				if (dis[t = edge[e][DST]] > (v = dis[nd] + edge[e][VAL])) {
					heap.push((p) {dis[t] = v, t});
				} 
			}
		}
	}
	int head[MXN], edge[MXE][3];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	_Main() {
		int Tn, a, b, c;
		int s;
		read(Tn);
		int l1, l2;
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m); read(s); read(k); read(C);
			for (int i = 1; i <= k; i++) {
				read(loc[i]);
			}
			eidx = 0;
			memset(head + 1, 0, n * sizeof(int));
			for (int i = 1; i <= m; i++) {
				read(a); read(b); read(c);
				add(a, b, c); add(b, a, c);
			}
			memset(dis + 1, 63, n * sizeof(int));
			heap.push((p) {dis[s] = 0, s});
			dijkstra();
			l1 = 0;
			for (int i = 1; i <= n; i++) {
				l1 = max(l1, dis[i]);
			}
			memset(dis + 1, 63, n * sizeof(int));
			for (int i = 1; i <= k; i++) {
				heap.push((p) {dis[loc[i]] = 0, loc[i]});
			}
			dijkstra();
			l2 = 0;
			for (int i = 1; i <= n; i++) {
				l2 = max(l2, dis[i]);
			}
			if (l2 * C >= l1) {
				printf("%d\n", l1);
			} else {
				printf("%d\n", l2);
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
