typedef long long lld;
typedef unsigned long long llu;
typedef double lf;
const int MAXN = 100050;
const lf EPS = 1e-14;
const int MAX_POW = 20;
const int INF = 0x3f3f3f3f;
int lrand() {
	return rand() & ((1 << 30) - 1);
}
struct Node {
	Node *f, *s[2];
	lf m[2], v;
	int val, idx, rand;
	Node *tf;
	void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
};
bool eq(lf a, lf b) {
	return a + EPS > b && a - EPS < b;
}
class SuffixTreap { // Ð¡¸ù¶Ñ 
public:
	queue<Node *>q;
	Node null;
	Node *root;
	Node pool[MAXN];
	int pidx;
	Node *new_node(int val, int idx, Node *tf, Node *f) {
		Node *nd;
		if (q.empty()) {
			nd = &pool[pidx++];
		} else {
			nd = q.front();
			nd->s[0] = nd->s[1] = 0;
			q.pop();
		}
		nd->val = val;
		nd->idx = idx;
		nd->tf = tf;
		nd->f = f;
		nd->rand = lrand();
		return nd;
	}
	SuffixTreap() {
		null.rand = -INF;
		null.val = INF;
		null.mark(0, 2);
		root = &null;
	}
	inline int cmp(int val, int idx, Node *tf, Node *nd) {
		if (val != nd->val) {
			return val > nd->val;
		}
		if (!eq(tf->v, nd->tf->v)) {
			return tf->v > nd->tf->v;
		}
		return idx > nd->idx;
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[pos ^ 1] = f;
	}
	
	Node* insert(int val, int idx, Node *tf, bool mark = true) {
		Node *nd = root;
		while (1) {
			int pos = cmp(val, idx, tf, nd);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new_node(val, idx, tf, nd);
				break;	
			}
		}
		while (nd->f && nd->rand < nd->f->rand) {
			rotate(nd);
		}
		if (mark) {
			mark_new(nd);
		}
		return nd;
	}
	void mark_new(Node *nd) {
		Node *f = nd->f;
		lf m[2];
		int pos = nd == f->s[1];
		m[pos] = f->m[pos];
		m[pos ^ 1] = f->v;
		remark(nd, m[0], m[1]);
	}
	void remark(Node *nd, lf l, lf r) {
		if (nd) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);	
		}
	}
	Node* near(Node *nd, int pos) {
		if (nd->s[pos]) {
			nd = nd->s[pos];
			while(nd->s[pos ^ 1]) {
				nd = nd->s[pos ^1];
			}
			return nd;
		}
		Node *f = nd->f;
		while (f && nd != f->s[pos ^ 1]) {
			nd = f;
			f = nd->f;
		}
		return f == root ? 0 : f;
	}
	void erase(Node *nd) {
		Node *s, *f;
		int pos;
		while(1) {
			pos = nd->s[1] == 0;
			if (pos || nd->s[0] == 0) {
				f = nd->f;
				s = nd->s[pos ^ 1];
				f->s[nd == f->s[1]] = s;
				if (s) {
					s->f = f;
				}
				break;
			}
			s = nd->s[nd->s[1]->rand < nd->s[0]->rand];
			rotate(s);
		}
		q.push(nd);
	}
}tree[2];

