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
char s1[] = "COFFEE";
char s2[] = "CHICKEN";
struct _Main {
	llu f[61];
	int mx;
	int print(int n, lld k, lld len) {
		if (n == 1) {
			for (int i = k; i - k < len && s1[i]; i++) {
				putchar(s1[i]);
			}
			return;
		} else
		if (n == 2) {
			for (int i = k; i - k < len && s2[i]; i++) {
				putchar(s2[i]);
			}
			return;
		}
		if (k < f[n - 2]) print(n - 2, k, min(mx, f[n - 2] - k))
		if (k + len >= f[n - 2]) print(n - 1, max(k - f[n - 2], 0), k + len - f[n - 2] + 1);
	}
	_Main() {
		f[1] = 6; 
		f[2] = 7;
		for (int i = 3; ; i++) {
			f[i] = f[i - 1] + f[i - 2];
			if (f[i] > 1e12 + 10) {
				mx = i;
			}
		}
		int Qn;
		read(Qn);
		int 
		for (int Q = 1; Q <= Qn; Q++) {
			
			print("%")
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
