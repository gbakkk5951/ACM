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
const int MXN = 1e6 + 10;
struct _Main {
	char s[MXN];
	int nxt[MXN];
	int n;
	void exkmp() {
		int core = 1;
		int bound;
		for (int i = 1; i <= n; i++) {
			if (s[i] != s[i - 1] || i == n) {
				nxt[1] = i - 1;
				bound = i - 1;
				break;
			}
		}
		for (int i = 2; i < n; i++) {
			if (i + nxt[i - core] - 1 < bound) {
				nxt[i] = nxt[i - core];
			} else {
				int now = max(0, bound - i + 1);
				while (s[now] == s[i + now]) {
					++now;
				}
				nxt[i] = now;
				core = i;
				bound = i + nxt[i] - 1;
			}
		}
	}
	_Main() {
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", s);
			n = strlen(s);
			exkmp();
			lld ans = 0;
			for (int i = 1; i < n; i++) {
				ans += (i + nxt[i]) == n ? nxt[i] : (nxt[i] + 1);
			}
			printf("%lld\n", ans);
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
