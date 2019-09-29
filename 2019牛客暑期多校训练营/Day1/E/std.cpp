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
const int MXN = 4e3 + 5;
const int MOD = 1e9 + 7;
struct _Main {
int com[MXN][MXN];
	_Main() {
		for (int i = 0;i <= 4e3; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
			}
		}
		int n, m;
		while(~scanf("%d%d", &n, &m)) {
			int ans = 0, len = (n + m) << 1;
			for (int l = 1; l <= len - m; l++) {
				for (int r = len; r >= m; r--) {
					if (l == r) {
						continue;
					}
					if (l < r) {
						if (len - r + 1 - n > m) {//右边的A不够
							continue;
						} else
						if (l - n > m) {//左边的B不够
							continue;
						} 
						ans = (ans + (lld)com[l - 1][n - 1] * com[len - r][n - 1]) % MOD;
					}
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
