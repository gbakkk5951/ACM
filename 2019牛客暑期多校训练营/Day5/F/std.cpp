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
const int MXN = 5e3 + 10;
struct _Main {
	inline char isin(int num) {
		return num == (num & (-num));
	}
	int ans, n;
	char vis[MXN];
	char color[MXN];
	int a[MXN];
	int q[2][MXN], qt[2];
	int aq[MXN];
	int head[MXN];
	int edge[(int)2e5][2];
	int eidx;
	int match[MXN];
	void dir_add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void add(int a, int b) {
		dir_add(a, b);
		dir_add(b, a);
	}
	char dfs(int nd) {
		vis[nd] = 1;
		for (int e = head[nd], t; e; e = edge[e][NXT]) {
			if (!match[t = edge[e][DST]] || !vis[match[t]] && dfs(match[t])) {
				match[nd] = t;
				match[t] = nd;
				return 1;
			}
		}
		return 0;
	}
	char mk[MXN];
	void mark(int nd) {
		int t;
		mk[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (!mk[t = edge[e][DST]]) {
				mk[t] = 1;
				mark(match[t]);
			}
		}
	}
	void colorfy(int nd, int now = 0) {
		vis[nd] = 1;
		color[nd] = now;
		for (int e = head[nd], t; e; e = edge[e][NXT]) {
			if (!vis[t = edge[e][DST]]) {
				colorfy(t, now ^ 1);
			}
		}
	}
	_Main() {
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (isin(a[i] ^ a[j])) {
					add(i, j);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) colorfy(i);
		}
		for (int i = 1; i <= n; i++) {
			if (!match[i] && color[i]) {
				memset(vis + 1, 0, n * sizeof(char));
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0 && !match[i]) {
				mark(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] != mk[i]) {
				aq[++ans] = a[i];
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i < ans; i++) {
			printf("%d ", aq[i]);
		}
		printf("%d", aq[ans]);
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
