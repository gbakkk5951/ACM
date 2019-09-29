using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

//#define DEBUG
namespace OI {
typedef long long lld;
typedef double lf;
const lf EPS = 1e-6;
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;

struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
struct Node {
	lf yl, yr, mid;
	int id, x0, y0, x1, y1;
};
bool dy(lf a, lf b) {
	return a - b > EPS;
}
bool eq(lf a, lf b) {
	return fabs(a - b) < EPS;
}
bool xy(lf a, lf b) {
	return b - a > EPS;
}
class Tree {
public:
	Node node[132000];
	void calc(int x0, int y0, int x1, int y1, lf &k, lf &b) {
		k = (y0 - y1) / (lf) (x0 - x1);
		b = y0 - k * x0;
	}	
	void insert(int nd, int nl, int nr, int id, int x0, int y0, int x1, int y1) {
		lf k, b;
		if (nl == nr) {
			lf v;
			if (x0 != x1) {
				calc(x0, y0, x1, y1, k, b);
				v = nl * k + b;
			} else {
				v = max(y0, y1);
			}
			if (dy(v, node[nd].mid) || eq(v, node[nd].mid) && id < node[nd].id) {
				node[nd].mid = v;
				node[nd].id = id;
			}
			return ;
		}
		int mid = nl + nr >> 1;
		char l, r;
		if (x0 <= nl && nr <= x1) {
			lf yl, yr, v;
			calc(x0, y0, x1, y1, k, b);
			yl = k * nl + b;
			yr = k * nr + b;
			v = (yr + yl) / 2.0;
			Node now = (Node){yl, yr, v, id, x0, y0, x1, y1};
			if (node[nd].id == 0 || dy(yl, node[nd].yl) && dy(yr, node[nd].yr)) {
				node[nd] = now;
				return;
			} else if (eq(yl, node[nd].yl) && eq(yr, node[nd].yr)) {
				if (id <node[nd].id) {
					node[nd].id = id;
				}
				return;
			} else if (dy(yr, node[nd].yr)) {

				if (dy(v, node[nd].mid) || eq(v, node[nd].mid) && id < node[nd].id) {
					insert(ls[nd], nl, mid, node[nd].id, 
						node[nd].x0, node[nd].y0, node[nd].x1, node[nd].y1
					);
					node[nd] = now;
					return;
				} else {
					l = 0; r = 1;
				}
			} else if (dy(yl, node[nd].yl) ) {

				if (dy(v, node[nd].mid) || eq(v, node[nd].mid) && id < node[nd].id) {
					insert(rs[nd], mid + 1, nr, node[nd].id, 
						node[nd].x0, node[nd].y0, node[nd].x1, node[nd].y1
					);
					node[nd] = now;
					return;
				} else {
					l = 1; r = 0;
				}

			} else {

				l = r = 0;
			}
		} else {
			l = x0 <= mid;
			r = x1 > mid;
		} 
		if (l == 1) {
			insert(ls[nd], nl, mid, id, x0, y0, x1, y1);
		}
		if (r == 1) {
			insert(rs[nd], mid + 1, nr, id, x0, y0, x1, y1);
		}
	}
	int query(int nd, int nl, int nr, int pos) {
		lf ans = 0; int id = 0;
		while (1) {
			if (node[nd].id) {
				lf y;
				if (nl != nr) {
					lf k, b;
					calc(node[nd].x0, node[nd].y0, node[nd].x1, node[nd].y1, k, b);
					y = k * pos + b;
				} else {
					y = node[nd].mid;
				}
				if (dy(y, ans) || eq(y, ans) && node[nd].id < id) {
					id = node[nd].id;
					ans = y;
				}
			}
			if (nl == nr) {
				break;
			}
			int mid = nl + nr >> 1;
			if (pos <= mid) {
				nr = mid;
				nd = ls[nd];
			} else {
				nl = mid + 1;
				nd = rs[nd];
			}
		}
		return id;
	}
}tree;

struct _Main {
int lstans;
template <typename Type>	
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
template <typename Type>
	void readx(Type &a) {
		read(a);
		a = (a + lstans - 1) % 39989 + 1;
	}
template <typename Type>
	void ready(Type &a) {
		read(a);
		a = (a + lstans - 1) % (int)1e9 + 1;
	}
	_Main() {
		int idx = 0;
		int Qn, oper, x0, y0, x, x1, y1;
		read(Qn); 
		for (int Q = 1; Q <= Qn; Q++) {
			read(oper);
			if (oper == 0) {
				readx(x);
				lstans = tree.query(1, 1, 39989, x);
				printf("%d\n", lstans);
				
			} else {
				readx(x0); ready(y0);
				readx(x1); ready(y1);
				if (x0 > x1) {
					swap(x0, x1);
					swap(y0, y1);
				}
				tree.insert(1, 1, 39989, ++idx, x0, y0, x1, y1);
			}
		}
	}
}bzoj3165;

}
//不要过分封装也不要过分散装，其实可以写个线段类，会方便很多，
//分类讨论的时候要注意细节 
