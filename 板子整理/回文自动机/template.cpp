struct Node {
	Node *s[26], *fail;
	int len;
}pool[MXN << 1];
int pidx;
Node *new_(int len, int id) {
	Node *nd = &pool[pidx++];
	nd->len = len;
	return nd;
}
struct PalinTree {
	int str[MXN], val; 
	int len[MXN];
	int n;
	Node *r1, *r0, *lst;
	PalinTree () {
		r1 = new_(-1, 1);
		r1->fail = r1;
		r0 = new_(0, 0);
		r0->fail = r1;
		str[0] = -1;
		lst = r1;
	}
	void insert(int val) {
		Node *nd = lst, *s, *up;
		str[++n] = val;
		while (str[n - 1 - nd->len] != val) nd = nd->fail;
		if (!nd->s[val]) {
			s = new_(nd->len + 2, n + 1);
			up = nd->fail;
			while (str[n - 1 - up->len] != val) up = up->fail;
			s->fail = up->s[val] ? up->s[val] : r0;
			nd->s[val] = s;
		}
		lst = nd->s[val];
		len[n] = lst->len;
	}
}org, rev;

