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
const int MXN = 1e5 + 10;
struct Node {
	int mx, pos, tag;
}node[(1 << 18) + 5];
struct Tree {
	void add_(int nd, int val) {
		node[nd].mx += val;
		node[nd].tag += val;
	}
	void push(int nd) {
		if (node[nd].tag) {
			add_(ls[nd], node[nd].tag);
			add_(rs[nd], node[nd].tag);
			node[nd].tag = 0;
		}
	}
	void update(int nd) {
		if (node[ls[nd]].mx != node[rs[nd]].mx) {
			node[nd].mx = max(node[ls[nd]].mx, node[rs[nd]].mx);
			node[nd].pos = node[ls[nd]].mx > node[rs[nd]].mx ? node[ls[nd]].pos : node[rs[nd]].pos;
		} else {
			node[nd].mx = node[ls[nd]].mx;
			node[nd].pos = node[ls[nd]].pos;
		}
	}
	void build(int nd, int nl, int nr) {
		node[nd].mx = node[nd].tag = 0;
		node[nd].pos = nl;
		if (nl == nr) {
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
	}
	void add(int nd, int nl, int nr, int l, int r, int val) {
	//printf("add [%d, %d]%d %d %d\n", nl, nr, l, r, val);
		if (l <= nl && r >= nr) {
			add_(nd, val);
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		if (l <= mid) add(ls[nd], nl, mid, l, r, val);
		if (r > mid) add(rs[nd], mid + 1, nr, l, r, val);
		update(nd);
	//	printf("[%d, %d]mx = %d, pos = %d\n", nl, nr, node[nd].mx, node[nd].pos);
	}

}tree;
struct _Main {
	int n, c, K;
	int arr[MXN];
	int head[MXN];
	int tail[MXN];
	int nxt[MXN];
	void add(int a, int i) {
		nxt[i] = 0;
		if (head[a] == 0) head[a] = i;
		else nxt[tail[a]] = i;
		tail[a] = i;
	}
	int count[MXN];
	_Main() {
		while (~scanf("%d%d%d", &n, &c, &K)) {
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
			}
			if (K == 1) {
				printf("%d\n", n);
				continue;
			}
			tree.build(1, 1, n);
			memset(head + 1, 0, c * sizeof(int));
			memset(tail + 1, 0, c * sizeof(int));
			memset(count + 1, 0, c * sizeof(int));
			int cnt = 0, ans = 0;;
			for (int i = 1; i <= n; i++) {
				int nc = arr[i];
				if (!count[nc]) {
					++cnt;
					count[nc] = 1;
					if (i != n)
					tree.add(1, 1, n, i + 1, n, 1);
					add(arr[i], i);
				} else {
					tree.add(1, 1, n, tail[nc] + 1, i, -1);
					count[nc]++;
					add(arr[i], i);
					if (count[nc] == K) {
						tree.add(1, 1, n, 1, head[nc], +1);
					} else if(count[nc] > K) {
						tree.add(1, 1, n, head[nc] + 1, nxt[head[nc]], +1);
						head[nc] = nxt[head[nc]];
					}
				}
				if (node[1].mx == cnt) {
					ans = max(ans, i - node[1].pos + 1);
					//printf("[%d, %d] = %d\n", node[1].pos, i, node[1].mx);
				}
			}
			printf("%d\n", ans);
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
