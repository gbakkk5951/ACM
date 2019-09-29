#pragma GCC optimize(2)
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
const int MOD = 1e9 + 7;
struct _Main {
	int dp[2][8005][8005];
	int q[2][(int)8e7];
	int qt[2];
	_Main() {
		int it = 0;
		int n = 4e3;
		dp[it][0][1] = 1;
		q[it][++qt[it]] = 0 * 1e4 + 1;
		int sum, mul, ss, mm, val;
		for (int i = 1; i <= (int)3e3; i++) {
			int ans = 0;
			it ^= 1;
			for (int j = 1; j <= qt[it ^ 1]; j++) {
				sum = q[it ^ 1][j] / (int)1e4;
				mul = q[it ^ 1][j] % (int)1e4;
				val = dp[it ^ 1][sum][mul];
				for (int k = 1; k <= 2 * n / mul && k <= 2 * n - sum; k++) {
					ss = sum + k;
					mm = mul * k;
					if (dp[it][ss][mm] == 0) {
						q[it][++qt[it]] = ss * (int) 1e4 + mm;
					}
					(dp[it][ss][mm] += val) %= MOD;
					if (ss == mm) (ans += val) %= MOD;
				}
			}
			qt[it ^ 1] = 0;
			if (i > 1) printf("%d,", ans);
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
