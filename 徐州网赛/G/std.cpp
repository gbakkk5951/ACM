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
const int MXN = 6e5 + 10;
struct _Main {
	char org[MXN >> 1], s[MXN];
	int on, n;
	int l[MXN][26];
	int len[MXN];
	_Main() {
		scanf("%s", org);
		on = strlen(org);
		
		s[0] = -1;
		for (int i = 1; i <= on; i++) {
			s[++n] = '#';
			memcpy(l[n], l[n - 1], 26 * sizeof(int));
			s[++n] = org[i - 1];
			memcpy(l[n], l[n - 1], 26 * sizeof(int));
			l[n][org[i - 1] - 'a'] = n;
		}
		s[++n] = '#';
		int r = 1, c = 1;
		for (int i = 2; i <= n; i++) {
			len[i] = len[c - (i - c)];
			if (i + len[i] < r) {
			} else {
				len[i] = r - i;
				while (s[i + len[i] + 1] == s[i - len[i] - 1]) {
					++len[i];
				}
				c = i;
				r = i + len[i];
			}
		}
		int srt[30], sn;
		lld ans = 0;
		for (int i = 1; i <= n; i++) {
			sn = 0;
			for (int j = 0; j < 26; j++) {
				if (l[i][j] && i - l[i][j] <= len[i]) {
					srt[sn++] = i - l[i][j] + 1;
				}
			}
			srt[sn++] = len[i] + 2;
			sort(srt, srt + sn);
			for (int j = 0; j < sn - 1; j++) {
				ans += (j + 1) * (srt[j + 1] - srt[j]) / 2;
			}
		}
		printf("%lld", ans);
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
