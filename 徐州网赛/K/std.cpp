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
struct _Main {
	p srt[MXN * MXN];
	p tmp[MXN][MXN];
	int x[MXN], y[MXN];
	int cnt[MXN * MXN];
	_Main() {
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(x[i]); read(y[i]);
		}
		int sn = 0;
		for (int i = 1; i <= n; i++) {
			srt[sn++] = (p) {x[i] << 1, y[i] << 1};
			for (int j = i + 1; j <= n; j++) {
				srt[sn++] = tmp[i][j] = (p) {x[i] + x[j], y[i] + y[j]};
			}
		}
		sort(srt, srt + sn);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt[lower_bound(srt, srt + sn, tmp[i][j]) - srt] += 2;
			}
			cnt[lower_bound(srt, srt + sn, (p) {x[i] + x[i], y[i] + y[i]}) - srt] += 1;
		}
		int mx = 1;
		for (int i = 1; i <= sn; i++) {
			mx = max(mx, cnt[i]);
		}
		printf("%d", n - mx);
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
