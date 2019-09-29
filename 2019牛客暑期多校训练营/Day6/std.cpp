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
typedef multiset<int>::iterator it;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 1e3 + 10;

struct _Main {
	int v[MXN];
	int q[MXN], qh;
	int n, K;
	multiset<int> rem;
	void solve() {
		int mxv = 1, vs = 0;
		for (int i = 1; i <= n; i++) {
			mxv = max(mxv, v[i]);
			vs += v[i];
			rem.insert(v[i]);
		}
		int l = max(mxv, (vs + (K - 1)) / K), mid, r = min(vs, mxv * ((n + (K - 1)) / K));
		it tmp;
		int rv;
		qh = 0;
		while (l < r) {
			mid = l + r >> 1;
			while (qh) {
				rem.insert(q[qh--]);
			}
			for (int i = 1; i <= K && !rem.empty(); i++) {
				rv = mid;
				while (!rem.empty() && rv >= *rem.begin()) {
					tmp = rem.upper_bound(rv);
					--tmp;
					rv -= *tmp;
					q[++qh] = *tmp;
					rem.erase(tmp);
				}
			}
			if (rem.empty()) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		rem.clear();
		printf("%d", l);
		
	}
	_Main() {
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(n); read(K);
			for (int i = 1; i <= n; i++) {
				read(v[i]);
			}
			printf("Case #%d: ", Q);
			solve();
			if (Q != Qn) {
				printf("\n");
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
