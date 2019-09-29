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
int inline lb(int a) {
	return a & (-a);
}
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
const int MXN = 1e5 + 5;
lld arr[MXN];
struct Node {
	lld mx;
	multiset<lld> ele;
}node[MXN];
struct _Main {
	int n;
	void clear() {
		for (int i = 1; i <= n; i++) {
			node[i].mx = 0;
			node[i].ele.clear();
		}
	}
	void insert(int nd, lld val) {
		for (;nd <= n; nd += lb(nd)) {
			node[nd].mx = max(node[nd].mx, val);
			node[nd].ele.insert(val);
		}
	}
	void modify(int nd) {
		printf("modify %d\n", nd);
		lld org = arr[nd];
		lld now = (arr[nd] += 1e7);
		for (; nd <= n; nd += lb(nd)) {
			node[nd].mx = max(node[nd].mx, now);
			node[nd].ele.erase(node[nd].ele.find(org));
			node[nd].ele.insert(now);
		}
	}
	lld find(int nd, lld mn) {
		printf("Find %d %lld\n", nd, mn);
		lld ans = LINF;
		for (; nd && ans != mn; nd -= lb(nd)) {
			if (node[nd].mx < mn || *node[nd].ele.begin() >= ans) continue;
			ans = min(ans, *node[nd].ele.lower_bound(mn));
		}
		return ans;
	}
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			int Qn, op;
			lld lstans = 0, t1, t2;
			read(n); read(Qn);
			clear();
			for (int i = n; i >= 1; i--) {
				read(t1);
				insert(i, t1);
			}
			for (int Q = 1; Q <= Qn; Q++) {
				read(op);
				if (op == 1) {
					read(t1);
					t1 ^= lstans;
					modify(n - t1);
				} else {
					read(t1); read(t2);
					t1 ^= lstans, t2 ^= lstans;
			//		t1--;
					if (t1 == n) continue;
					printf("ans = %lld\n", lstans = find(n - t1, t2));
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
