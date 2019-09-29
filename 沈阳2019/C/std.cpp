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
const int MXN = 1e3 + 5, MXM = 1e4 + 5;
struct _Main {
	int n, m;
	p arr[MXN];
	int dp[MXM];
	_Main() {
		while (~scanf("%d%d", &n, &m)) {
			p ans = (p) {INF, INF};
			for (int i = 1; i <= n; i++) {
				read(arr[i].second);
				read(arr[i].first); 			
			}
			sort(arr + 1, arr + n + 1);
			n = unique(arr + 1, arr + n + 1) - arr - 1;
			int low = INF;
			for (int i = n; i >= 1; i--) {
				if (arr[i].second >= low) swap(arr[i], arr[n]), --n;
				else low = arr[i].second;
			}
			memset(dp, 63, m * sizeof(int));
			dp[0] = 0;
			for (int i = 1; i <= n; i++) {
				int kg = arr[i].first, c = arr[i].second;
				for (int j = 0; j < m; j++) {
					if (j + kg >= m) ans = min(ans, (p) {dp[j] + c, -(j + kg)});
					else dp[j + kg] = min(dp[j + kg], dp[j] + c);
				}
			}
			printf("%d %d\n", ans.first, -ans.second);
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
