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
struct _Main {
	int sum[11][22][11];//b = i, bit = j, 最高位<= k
	int pow[11][22];
	void init(int bit) {
		int mx = 1;
		pow[bit][0] = 1;
		for (int mx = 1, now = 1; mx <= (int)1e6; now++) {//后i位
			mx *= bit;
			pow[bit][now] = mx;
			for (int j = 0; j < bit; j++) {
				sum[bit][now][j] = sum[bit][now - 1][bit - 1] + pow[bit][now - 1] * j + (j ? sum[bit][now][j - 1] : 0);
			}
		}
	}
	int calc(int n, int b) {
		int mx, now; 
		for (mx = 1, now = 1; mx <= n; now++) {
			mx *= b;
		}
		--now;
		int ret = 0, nowbit, bef = 0;
		for (int i = now; i >= 1; i--) {
			nowbit = n / pow[b][i - 1] % b;
			if (nowbit) {
				ret += sum[b][i][nowbit - 1] + pow[b][i - 1] * nowbit * bef;
			}
			bef += nowbit;
		}
		ret += bef;//数本身
		return ret;
	}
	int brute(int nn, int b) {
		int ret = 0;
		for (int n = 1; n <= nn; n++) {
			int p = n;
			while (p) {
				ret += p % b;
				p /= b;
			}
		}
		return ret;
	}
	_Main() {
		int Tn;
		read(Tn);
		for (int i = 2; i <= 10; i++) {
			init(i);
		}
		for (int T = 1; T <= Tn; T++) {
			int n, b;
			read(n); read(b);
//			n = rand() % (int) 1E6 + 1;
//			b = rand() % 9 + 2;
//			if (brute(n, b) != calc(n, b)) printf("???");
			printf("Case #%d: %d\n", T, calc(n, b));
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
