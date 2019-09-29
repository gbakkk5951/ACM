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
const int MXN = 1e5 + 5;
typedef pair<lld, lld> p;
struct _Main {
	int n;
	p arr[MXN];
	multiset<lld> tree;
	_Main() {
		lld ans, a, b;
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			ans = LINF;
			read(n);
			for (int i = 1; i <= n; i++) {
				read(arr[i].first);
				read(arr[i].second);
			}
			sort(arr + 1, arr + n + 1);
			for (int i = 1; i <= n; i++) {
				tree.insert(arr[i].second);
			}
			multiset<lld>::iterator it;
			lld mx = -LINF; //不能是0
			for (int i = n; i >= 1; i--) {
				tree.erase(tree.find(arr[i].second));
				//
				ans = min(ans, llabs(arr[i].first - mx));
				if (mx < arr[i].first) {
					it = tree.lower_bound(arr[i].first);
					if (it != tree.end()) ans = min(ans, llabs(arr[i].first - *it));
					if (it != tree.begin() && *(--it) > mx) ans = min(ans, llabs(arr[i].first - *it));
				}
				mx = max(mx, arr[i].second);
			}
			printf("%lld\n", ans);
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
