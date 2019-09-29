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
const int MXN = 2e6 + 10;
struct _Main {
	int arr[MXN];
	_Main() {
		int n;
		read(n);
		memset(arr, -1, sizeof(arr));
		int l, r = 0;
		for (int i = 1; i <= n; i++) {
			read(l); read(r);
			l++; r++;
			for (int j = l; j <= r; j++) {
				arr[j] = 1;
			}
		}
		for (int k = 1; k <= r * 2; k++) {
			arr[k] += arr[k - 1];
		}
		int ans = 0;
		for (int k = 1; k <= r * 2; k++) {
			for (int j = 0; j < k; j++) {
				ans += arr[k] > arr[j];
			}
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
