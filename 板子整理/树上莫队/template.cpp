void insert(int nd) {}
void erase(int nd) {}
void getlca(int a, int b) {}
char inchain[MXN];
type calcans() {}
void change(int nd) {
	if (inchain[nd]) {
		erase(nd);
	} else {
		insert(nd);
	}
	inchain[nd] ^= 1;
}
int idx;
int in[MXN], out[MXN], org[MXN * 2];
void getdfn(int nd, int fa) {
	org[in[nd] = ++idx] = nd;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if ((t = edge[e][DST]) != fa) {
			getdfn(t, nd);
		}
	}
	org[out[nd] = ++idx] = nd;
}
int blk[MXN * 2];
void getblk(int nd) {
	int now = 0;
	for (int i = 1; i <= idx; i++) {
		now += i % sq == 0;
		blk[i] = now;
	}
}
struct Query{
	int l, r, a, b;
	void operator < (const Query &dst) {
		return blk[l] != blk[dst.l] ? blk[l] < blk[dst.l] : r < dst.r;
	}
}arr[MXM];
void solve() {
	int nowa, nowb;
	nowa = nowb = 1;
	for (int Q = 1; Q <= Qn; Q++) {
		int a = arr[Q].a, b = arr[Q] = b;
		move(nowa, a);
		nowa = a;
		move(nowb, b);
		nowb = b;
		lca = getlca(a, b);
		change(lca);
		ans = calcans();
		change(lca);
	}
}
void move(int a, int b) {
	if (h[a] < h[b]) swap(a, b);
	while (h[a] > h[b]) {
		change(a);
		a = f[a];
	}
	if (a == b) return;
	while (a != b) {
		change(a); change(b);
		a = f[a]; b = f[b];
	}
}
void readin() {
	for (int Q = 1; Q <= Qn; Q++) {
		read(a); read(b);
		if (in[a] > in[b]) swap(a, b);
		if (in[b] < out[a]) arr[Q] = (Query) {in[a], in[b], a, b};
		else arr[Q] = (Query) {out[a], in[b], a, b};
	}
	sort(arr + 1, arr + Qn + 1);
}
