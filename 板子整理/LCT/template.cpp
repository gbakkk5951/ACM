struct Node {
	Node *s[2], *f;
	int val;
	int id;
	char swp, isnode;
	void update() {
	}
	void rotate() {
		Node *gf = f->f;
		int spo;
		if ((spo = f == gf->s[1]) || f == gf->s[0]) {
			gf->s[spo] = this;
		}
		spo = this == f->s[1];
		(f->s[spo] = s[spo ^ 1])->f = f;
		s[spo ^ 1] = f;
		f->f = this;
		f->update();
		update();
		f = gf;
	}
	inline void swap() {
		std::swap(s[0], s[1]);
		swp ^= 1;
	}
	void push() {
		if (swp) {
			s[0]->swap();
			s[1]->swap();
			swp = 0;
		}
	}
}pool[MXN << 1], *null;
int pidx;
Node *new_(int val, int isnode) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = nd->f = null;
	nd->val = val; nd->isnode = isnode;
	return nd;
}
struct LCT {
void push_to(Node *nd) {
	static Node *stk[MXN << 1];
	int top = 0;
	while (nd != null) {
		stk[++top] = nd;
		nd = nd->f;
	}
	while (top) {
		stk[top--]->push();
	}
}
Node *access(Node *nd) {
	push_to(nd);
	Node *lst = null, *org = nd;
	while (nd != null) {
		splay(nd);
		nd->s[1] = lst;
		lst = nd;
		nd = nd->f;
	}
	splay(org);
	return lst;
}
Node *getfa(Node *nd) {
	access(nd);
	nd->push();
	nd = nd->s[0];
	nd->push();
	while (nd->s[1] != null) {
		nd = nd->s[1];
		nd->push();
	}
	splay(nd);
	return nd;
}
void splay(Node *nd) {
	nd->update();
	Node *f = nd->f, *gf;
	char a, b;
	while ((a = nd == f->s[1]) || nd == f->s[0]) {
		gf = f->f;
		if ((b = f == gf->s[1]) || f == gf->s[0]) {
			(a == b ? f : nd)->rotate();
		}
		nd->rotate();
		f = nd->f;
	}
}
void mkrt(Node *nd) {
	access(nd);
	nd->swap();
}
void link(Node *s, Node *f) {
	mkrt(s);
	s->f = f;
}
void cut(Node *nd) {//将nd与f割下来
	access(nd);
	nd->s[0]->f = null;
	nd->s[0] = null;
}
inline Node *getlca(Node *a, Node *b) {
	access(a);
	return access(b);
}
LCT() {
	null = new_(0, 0);
	null->f = null->s[0] = null->s[1] = null;
}
