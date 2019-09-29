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
const int MXN = 1e5 + 10;
struct Team {
	char name[11];
	int p, t;
	bool friend operator < (const Team &a, const Team &b) {
		return a.p == b.p ? a.t < b.t : a.p > b.p;
	}
}team[MXN];
struct _Main {
	_Main() {
		int Tn;
		read(Tn);
		int n, d, dst;
		for (int T = 1; T <= Tn; T++) {
			read(n); read(d);
			for (int i = 1; i <= n; i++) {
				scanf("%s", team[i].name);
				read(team[i].p); read(team[i].t);
			}
			if (n * d % 10 == 5) {
				dst = (n * d + 5) / 10;
				nth_element(team + 1, team + dst, team + n + 1);
				printf("%s\n", team[dst].name);
			} else {
				printf("Quailty is very great\n");
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
