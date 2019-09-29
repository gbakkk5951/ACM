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
const int MXN = 2e7 + 10;
struct _Main {
	int n;
	int cnt_arr[MXN];
	int q[(int)(2e6 + 10)][2], qn;
	char del[(int)(2e6 + 10)];
	int base;
	lld ans;
	int sl, sr;
	int vis(int idx) {
		
		return cnt_arr[idx - base +( MXN >> 1)] + (idx >= sl && idx <= sr);
	}
	int pre_add(int idx) {
		++cnt_arr[idx - base + (MXN >> 1)];
		return vis(idx);
	}
	int post_add(int idx) {
		int ret = vis(idx);
		++cnt_arr[idx - base + (MXN >> 1)];
		return ret;
	}
	_Main() {
		sl = 1e8;
		int lst = -1;
		read(n);
		int l, r, now = 0, s = 1;
		pre_add(0);
		++qn;
		q[qn][0] = 0;
		q[qn][1] = 0;
		for (int Q = 1; Q <= n; Q++) {
			read(l); read(r);
//			printf("(%d)[%d, %d]\n", Q, l, r);
			int tmp = now + (l - lst - 1) * (-1);
			if (base - tmp > 1e7) {
				s -= vis(now);
				int org = now;
				while (s > 0) {
					ans += s -= vis(--now);
				}
				for (int i = 1; i <= qn; i++) {
					memset(cnt_arr + (MXN >> 1) + q[i][0] - base, 0, sizeof(int) * (q[i][1] - q[i][0] + 1));
					if (q[i][0] > tmp + (int)1e7) {
						del[i] = 1;
					} else {
						q[i][1] = min(q[i][1], tmp + (int)1e7);
					}
				}
				base = now = tmp;
				sl = now; sr = org - 1;
				int nn = 0;
				for (int i = 1; i <= qn; i++) {
					if (!del[i]) {
						++nn;
						del[nn] = 0;
						q[nn][0] = q[i][0];
						q[nn][1] = q[i][1];
						for (int j = q[nn][0]; j <= q[nn][1]; j++) {
							pre_add(j);
						}
					}
				}
				qn = nn;
				
				s = 1;
//				printf("s = 1__\n");
			} else if(now != tmp) {
				++qn;
				del[qn] = 0;
				q[qn][0] = tmp;
				q[qn][1] = now - 1;
				s -= vis(now);
				for (; now > tmp;) {
//					printf("[]ans += s(%d) -= %d\n", s, vis(now - 1));
					ans += s -= post_add(--now);
				}
				s += vis(now);
				now = tmp;
			}
//			printf("Hs = %d\n", s);
			++qn;
			del[qn] = 0;
			q[qn][0] = now + 1;
//			printf("A ans = %lld\n", ans);
			for (int i = l; i <= r; i++) {
				ans += s;
//				printf("ans += s(%d)\n", s);
				s += pre_add(++now);
//				printf("s += cnt[%d] = %d(%d)\n", now, vis(now), (now >= sl ? min(now, sr) - sl + 1 : 0));
			}
			
			q[qn][1] = now;
			lst = r;
//			printf("ans = %lld, s = %d\n", ans, s);
		}
		int pos = lst + 1;
		s -= vis(now);
//		printf("s -= cnt[%d] = %d\n", now, vis(now));
		while (s > 0 &&  pos < (int)1e9) {
			++pos;
			ans += s -= post_add(--now);
//			printf("s -= cnt[%d] = %d(%d)\n", now, vis(now) - 1, (now >= sl ? min(now, sr) - sl + 1 : 0));
//			printf("Pans += s(%d)\n", s);
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
