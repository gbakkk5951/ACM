inline int lb(int a) {
	return a & (-a);
}
int n, m;
int arr[mxn][mxn];
struct subArrayTree {
	int node[MXN];
	int & operator [] (int a) {
		return node[a];
	}
	void add(int nd, int val) {
		for (; nd <= m; nd += lb(nd)) {
			node[nd] += val;
		}
	}
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= lb(nd)) {
			ret += node[nd];
		}
		return ret;
	}
};
struct ArrayTree {
	subArrayTree node[MXN], sig[MXN];
	void add(int nd, int yl, int yr, int val) {
		for (; nd <= n; nd += lb(nd)) {
			node[nd].add(yl, yl * val);
			node[nd].add(yr + 1, (yr + 1) * (-val));
			sig[nd].add(yl, val);
		}
	}
	int query(int nd, int yl, int yr) {
		int ret = 0;
		for (; nd; nd -= lb(nd)) {
			ret += ((yr + 1) * sig[nd].query(yr) - node[nd].query(yr))
				 - ((yl) * sig[nd].query(yl - 1) - node[nd].query(yl - 1));
		}
		return ret;
	}
	void build() {
		int i_, j_;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				node[i][j] += arr[i][j];
				if ((i_ = i + lb(i)) <= n && (j_ = j + lb(j)) <= m) {
					node[i_][j] += arr[i][j];
					node[i][j_] += arr[i][j];
					node[i_][j_] -= arr[i][j];
				}
			}
		}
	}
};
struct Tree {
	ArrayTree atree;
	void add(int xl, int xr, int yl, int yr, int val) {
		atree.add(xl, yl, yr, xl * val);
		atree.add(xr + 1, yl, yr, (xr + 1) * (-val));
	}
	int query(int xl, int xr, int yl, int yr) {
		return atree.query(xr, yl, yr) - atree.query(xl - 1, yl, yr);
	}
}tree;

