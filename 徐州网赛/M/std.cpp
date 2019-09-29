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
	int right[MXN][26];
	char mu[MXN], dst[MXN];
	int n, m;
	_Main() {
		read(n); read(m);
		scanf("%s%s", mu, dst);
		for (int i = 0; i < 26; i++) right[n][i] = INF;
		for (int i = n - 1; i >= 0; i--) {
			memcpy(right[i], right[i + 1], 26 * sizeof(int));
			right[i][mu[i] - 'a'] = i;
		}
		int ans = -1;
		int nowmu = -1;
		int i = 0;
		for (i = 0; i < m && i < n && nowmu < n - 1; i++) {//相同部分长度
			for (int j = dst[i] - 'a' + 1; j < 26; j++) {//下一个字符
				ans = max(ans, i + n - right[nowmu + 1][j]);
			}
			nowmu = right[nowmu + 1][dst[i] - 'a'];
		}
		//前m相同
		if (i == m && nowmu < n - 1) {
			ans = max(ans, n - 1 - nowmu + m);
		}
		printf("%d", ans);
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
