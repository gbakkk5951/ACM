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
		lld dp[2][2][2][3][3];
		int _a, _b, _c;
		char a[32], b[32], c[32];
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(_a); read(_b); read(_c);
			int mxp = 0;
			while ((1 << mxp + 1) <= _a || (1 << mxp + 1) <= _b) mxp++;
			for (int i = 0; i <= mxp; i++) {
				a[i] = (_a >> i) & 1;
				b[i] = (_b >> i) & 1;
				c[i] = (_c >> i) & 1;
			}
			char it = 0, sg, sl;
			memset(dp, 0, sizeof(dp));
			if ((1 << mxp + 1) <= _c) {
				dp[it][1][1][2][1] = 1;
			} else {
				dp[it][1][1][0][0] = 1;
			}
			for (int i = mxp; i >= 0; i--) {//填充第i位
				it ^= 1;
				for (int A = 0; A <= 1; A++) {//equal to A
					for (int B = 0; B <= 1; B++) {//equal to B
						for (int G = 0; G <= 2; G++) {//& Greater than C
							for (int L = 0; L <= 2; L++) {//^ Less than C
								if (lld &nd = dp[it ^ 1][A][B][G][L]) {
//									printf("dp[%d][%d][%d][%d][%d] = %lld\n", i + 1, A, B, G, L, nd);
									for (int an = 0; an <= 1; an++) {
										if (A && an && (a[i] == 0)) break;
										for (int bn = 0; bn <= 1; bn++) {
											if (B && bn && (b[i] == 0)) break;
											sg = ((an & bn) < c[i] && !G) | (G == 2);
											sl = ((an ^ bn) > c[i] && !L) | (L == 2);
											dp[it][A & (an == a[i])][B & (bn == b[i])][sg ? 2 : (G | ((an & bn) > c[i]))][sl ? 2 : (L | ((an ^ bn) < c[i]))] += nd;
										}
									}
									nd = 0;
								}
							}
						}
					}
				}
			}
			lld ans = 0;
			ans = ans - min(_c, _a + 1) - min(_c, _b + 1) + 1;
			for (int A = 0; A <= 1; A++) {
				for (int B = 0; B <= 1; B++) {
					for(int G = 0; G <= 2; G++) {
						for (int L = 0; L <= 2; L++) {
							if ((G | L) & 1) ans += dp[it][A][B][G][L];
						}
					}
				}
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
