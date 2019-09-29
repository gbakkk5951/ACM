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
const int MXN = 5e3 + 5, MK = 2e3 + 5;
struct B {
	int w, h;
	lld s;
	bool friend operator < (const B &a, const B &b) {
		return a.h < b.h;
	}
}board[MXN];
struct _Main {
	lld dp[2][MXN];
	lld ss[MXN], ws[MXN];
	int n, K;
	void calc(int it, int l, int r, int dl, int dr) {
		int mid = l + r >> 1;
		lld tmp, s = 0, cho, w = 0, val;
		tmp = LINF;
		if (dr + 1 < mid) {
			w = ws[mid] - ws[dr + 1];
			s = ss[mid] - ss[dr + 1];
		}
		for (int k = min(mid - 1, dr); k >= dl; k--) {
			s += board[k + 1].s;
			w += board[k + 1].w;
			val = dp[it ^ 1][k] + (s - w * board[k + 1].h);
			if (tmp > val) {
				tmp = val;
				cho = k;
			}
		}
		dp[it][mid] = tmp;
		if (l < mid) calc(it, l, mid - 1, dl, cho);
		if (r > mid) calc(it, mid + 1, r, cho, dr);
	}
	_Main() {
		read(n); read(K);
//		n = 5e3; K = 2e3;
		for (int i = 1; i <= n; i++) {
			read(board[i].w); read(board[i].h);
//			board[i].w = rand() % (int)1e7 + 1;
//			board[i].h = rand() % (int)1e7 + 1;
			board[i].s = (lld)board[i].w * board[i].h;
		}
		sort(board + 1, board + n + 1);
		for (int i = 1; i <= n; i++) {
			ss[i] = ss[i - 1] + board[i].s;
			ws[i] = ws[i - 1] + board[i].w;
		}
		int it = 0;
		memset(dp[0] + 1, 63, (n - K) * sizeof(lld));
		for (int i = 1; i <= K; i++) {
			it ^= 1;
			calc(it, i, n - (K - i), i - 1, n - (K - i));
		}
		printf("%lld", dp[it][n]);
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
