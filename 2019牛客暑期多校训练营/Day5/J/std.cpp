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
const int MOD = 998244353;
const int MXN = 3e3 + 10;
struct _Main {
	int dp[MXN][MXN];
	int com[MXN][MXN];
	int coms[MXN][MXN];
	char s[MXN], t[MXN];
	int pow[MXN];
	int n, m;
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			scanf("%s%s", s + 1, t + 1);
			for (int i = 1; i <= n; i++) {
				s[i] -= '0';
			}
			for (int i = 1; i <= m; i++) {
				t[i] -= '0';
			}
			for (int i = 0; i <= m; i++) {
				memset(dp[i] + i, 0, (n - i + 1) * sizeof(int));
			}
			com[0][0] = 1;
			coms[0][0] = 1;
			for (int i = 1; i <= n; i++) {
				com[i][0] = 1;
				coms[i][0] = 1;
				for (int j = 1; j <= i; j++) {
					com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD; 
					coms[i][j] = (coms[i][j - 1] + com[i][j]) % MOD;
				}
			}
			int ans = 0;
			dp[0][0] = 1;
			for (int i = 1; i <= m; i++) {
				for (int j = i, sum = 0; j <= n; j++) {//接j
					sum = (sum + dp[i - 1][j - 1]) % MOD;
					if (s[j] > t[i]) {
						ans = (ans + (lld)sum * com[n - j][m - i]) % MOD;
					} else 
					if (s[j] == t[i]) {
						dp[i][j] = sum;
					}
				}
			}
			pow[0] = 1;
			for (int i = 1; i <= n; i++) {
				pow[i] = (pow[i - 1] << 1) % MOD;
			}
			for (int i = 1; i <= n - m; i++) {
				if (s[i]) ans = (ans + pow[n - i] - coms[n - i][m - 1]) % MOD;
			}
			ans += MOD;
			ans %= MOD;
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
