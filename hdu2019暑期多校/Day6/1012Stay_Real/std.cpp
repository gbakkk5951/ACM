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
const int MXN = 1e5 + 5;
struct _Main {
	lld ans[2];
	int s[MXN], v[MXN];
	priority_queue<p> heap;
	inline p mp(int a, int b) {
		return (p) {a, b};
	}
	int n;
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n);
			for (int i = 1; i <= n; i++) {
				read(v[i]);
				s[i] = 0;
				s[i >> 1]++;
			}
			for (int i = n; i >= 1 && s[i] == 0; i--) {
				heap.push(mp(v[i], i));
			}
			ans[0] = ans[1] = 0;
			int it = 1, nd;
			while (!heap.empty()) {
				ans[it ^= 1] += heap.top().first;
				nd = heap.top().second;
				heap.pop();
				if ((--s[nd >>= 1]) == 0) {
					heap.push(mp(v[nd], nd));
				}
			}
			printf("%lld %lld\n", ans[0], ans[1]);
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
