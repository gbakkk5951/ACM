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
const int MXN = 2e3 + 5;
const int dx[4] = {0, 0, -1, +1};
const int dy[4] = {+1, -1, 0, 0};
struct _Main {
	char down[MXN][MXN];
	int ans;
	void dfs(int x, int y) {
		if (1 <= x && x <= n && 1 <= y && y <= m && !down[x][y]) {
			if ((down[x - 1][y] || down[x + 1][y]) && (down[x][y - 1] || down[x][y + 1])) {
				down[x][y] = 1;
				++ans;
			} else return;
			for (int i = 0; i < 4; i++) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
	int n, m;
	
	_Main() {
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			memset(down, 0, sizeof(down));
			int Qn, x, y;
			read(n); read(m); read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				ans = 0;
				read(x); read(y);
				if (!down[x][y]) {
					++ans;
					down[x][y] = 1;
					for (int i = 0; i < 4; i++) {
						dfs(x + dx[i], y + dy[i]);
					}
				}
				printf("%d\n", ans);
			}
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
