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
	_Main() {
		int Tn;
		int n;
		lld used, room, unmatched, x1, x2, x3, a, b;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n);
			used = room = unmatched = 0;
			for (int i = 1; i <= n; i++) {
				read(a); read(b);
				//虚空中的人
				x1 = min(b, unmatched);
				used += x1;
				unmatched -= x1;
				//人换杯子
				if (b -= x1) {
					x2 = min(b, used - x1);
					room += x2;
					b -= x2;
				}
				//新人拿杯子
				x3 = min(a, room);
				room -= x3;
				used += x3;
				room += b;
				unmatched += a - x3;
			}
			printf("%lld\n", used);
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
