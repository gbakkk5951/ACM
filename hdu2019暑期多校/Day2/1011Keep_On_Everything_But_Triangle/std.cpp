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
struct Node {
	vector<int> arr;
	int & operator [] (int a) {
		return arr[a];
	}
};
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
const int MXN = 1e5 + 10;
priority_queue<p> heap;
int arr[MXN];
int pick[50], pnt;
int idx[50];
int n;
struct Tree {
	Node node[(1 << 18) + 5];
	void build(int nd, int nl, int nr) {
		node[nd].arr.resize(nr - nl + 1);
		if (nl == nr) {
			node[nd][0] = arr[nl];
			return;
		}
		int mid = nl + nr >> 1;
		int l = ls[nd], r = rs[nd];
		build(l, nl, mid);
		build(r, mid + 1, nr);
		int i = 0, j = 0;
		while (i < node[l].arr.size() && j < node[r].arr.size()) {
			if (node[l][i] > node[r][j]) {
				node[nd][i + j] = node[l][i];
				i++;
			} else {
				node[nd][i + j] = node[r][j];
				j++;
			}
		}
		if (j < node[r].arr.size()) {
			swap(i, j);
			swap(l, r);
		}
		while(i < node[l].arr.size()) {
			node[nd][i + j] = node[l][i];
			i++;
		}
	}
	void _pick(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			OI::pick[++pnt] = nd;
			heap.push((p) {node[nd][0], pnt});
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) _pick(ls[nd], nl, mid, l, r);
		if (r > mid) _pick(rs[nd], mid + 1, nr, l, r);
	}
	void pick(int l, int r) {
		pnt = 0;
		_pick(1, 1, n, l, r);
		memset(idx + 1, 0, pnt * sizeof(int));
	}
}tree;
int pick_max() {
	p t = heap.top();
	int nd = t.second;
	heap.pop();
	if (++idx[nd] < tree.node[pick[nd]].arr.size()) {
		heap.push((p) {tree.node[pick[nd]][idx[nd]], nd});
	}
	return t.first;
}

struct _Main {
	_Main() {
		int Qn;
		int l, r;
		int tmp[3], now;
		lld ans;
		while (~scanf("%d%d", &n, &Qn)) {
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
			}
			tree.build(1, 1, n);
			for (int Q = 1; Q <= Qn; Q++) {
				read(l); read(r);
				if (r - l + 1 < 3) {
					printf("-1\n");
					continue;
				}
				tree.pick(l, r);
				for (int i = 0; i < 3; i++) {
					tmp[i] = pick_max();
				}
				now = 2;
				ans = -1;
				while(!heap.empty() && tmp[now] + tmp[(now + 2) % 3] <= tmp[(now + 1) % 3]) {
					now = (now + 1) % 3;
					tmp[now] = pick_max();
				}
				if (tmp[now] + tmp[(now + 2) % 3] > tmp[(now + 1) % 3]) {
					ans = (lld)tmp[0] + tmp[1] + tmp[2];
				}
				while (!heap.empty()) {
					heap.pop();
				}
				printf("%lld\n", ans);
				
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
