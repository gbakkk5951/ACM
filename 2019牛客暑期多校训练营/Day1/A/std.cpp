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
const int MXN = 1e5 + 10;
struct _Main {
	int a[MXN], b[MXN];
	int sa[MXN], sb[MXN];
	_Main() {
		int n;
		while (~scanf("%d", &n)) {
			for (int i = 1; i <= n; i++) {
				read(a[i]);
			}
			for (int i = 1; i <= n; i++) {
				read(b[i]);
			}
			int ans = 1;
			int stk = 1;
			sa[1] = a[1];
			sb[1] = b[1];
			for (int i = 2; i <= n; i++) {
				int pa = a[i], pb = b[i];
				while (stk && pa < sa[stk] && pb < sb[stk]) {
					--stk;
				}
				++stk;
				sa[stk] = pa;
				sb[stk] = pb;
				if (stk > 1 && (pa < sa[stk - 1]) != (pb < sb[stk - 1])) {
					goto EndLoop;
				}
				ans++;
			}
			EndLoop:
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
