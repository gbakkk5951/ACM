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
const int MXN = 2e5 + 10;
struct _Main {
	int dp[MXN][2]; // 0 表示以ｎ为结尾，１表示以n - 1为结尾
	_Main() {
		dp[1][0] = 1;
		for (int i = 2; i <= 200000; i++) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			dp[i][1] = dp[i - 2][0];
		}
		int Qn;
		read(Qn);
		int n, x, y;
		for (int Q = 1; Q <= Qn; Q++) {
			read(n); read(x); read(y);
			int ans;
			if (x == 1 && y == n) {
				ans = dp[n][0];
			} else if (x == 1 || y == n){
				ans = dp[y - x][0];
			} else {
				ans = dp[y - x - 1][0];
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
