struct Node {
	Node *s[26], *f;
	int mx, mn, id; 
};
class SAM {
public:
	Node node[4005];
	Node *root, *tail;
	int idx;
	Node *new_(int mx, Node *org = 0) {
		Node *nd = &node[idx];
		nd->id = idx++;
		nd->mx = mx;
		if (org) {
			memcpy(nd->s, org->s, 26 * sizeof(Node *));
		}
		return nd;
	}
	SAM() {
		root = tail = new_(0);
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = new_(tail->mx + 1);
		tail->s[c] = nd;
		Node *f = tail->f;
		tail = nd;
		while (f && f->s[c] == 0) {
			f->s[c] = nd;
			f = f->f;
		}
		if (f == 0) {
			ref(nd, root);
			return;
		}
		Node *s = f->s[c];
		if (f->mx + 1 == s->mx) {
			ref(nd, s);
			return ;
		}
		Node *nf = new_(f->mx, s);
		ref(nf, s->f);
		ref(nd, nf);
		ref(s, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
}sam;

