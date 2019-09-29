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
const int MXN = 5e5 + 10;
struct _Main {
	int n, m;
	int qh;
	p srt[MXN];
	int mx;
	int ans[MXN];
	_Main() {
		int a;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(a);
			srt[i] = (p) {a, i};
		}
		
		sort(srt + 1, srt + n + 1, greater<p>());
		mx = 0;
		qh = 1;
		for (int i = 1; i <= n; i++) {
			while (qh < i && srt[qh].first - srt[i].first >= m) {
				mx = max(mx, srt[qh++].second);
			}
			if (mx > srt[i].second) {
				ans[srt[i].second] = mx - srt[i].second - 1;
			} else {
				ans[srt[i].second] = -1;
			}
		}
		for (int i = 1; i <= n - 1; i++) {
			printf("%d ", ans[i]);
		}
		printf("%d", ans[n]);
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
