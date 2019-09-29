    
struct Node {
    int val;
    int size;
    int cnt;
    Node *son[2], *fa;
    void inline update() {
        size = (son[0] ? son[0]->size : 0)
             + (son[1] ? son[1]->size : 0)
             + cnt;
    }
}pool[MAXN];
int poolIdx;

inline Node * newNode() {
    return &pool[poolIdx++];
}

class Tree {

private:
    int size;
    Node *root; 
    void inline buildNode (Node *fa, int pos, int val) {
        Node *nd = fa->son[pos] = newNode();
        nd->fa = fa;
        nd->val = val;
        nd->size = nd->cnt = 1;
    }
    void inline rotate (Node *nd) {
        Node *fa = nd->fa;
        
        int pos = (nd == fa->son[1]);
        fa->son[pos] = nd->son[pos ^ 1];
        nd->son[pos ^ 1] = fa;
        nd->fa = fa->fa;
        fa->fa=nd;
        if (fa->son[pos]) {
            fa->son[pos]->fa = fa;
        }
        if (nd->fa) {
            nd->fa->son[nd->fa->son[1] == fa] = nd;
        }
        fa->update();
        nd->update();
    }
    void splay (Node *nd, Node *top = 0) {
        Node *fa; 
        if((fa = nd->fa) == top) {
            return ;
        }      
        do {
            if(fa->fa != top && (fa->son[0] == fa) == (fa->fa->son[0] == fa)) {
                rotate(fa);
            }
            rotate(nd);
            fa = nd->fa;
//            printf("Splay");
        } while (fa != top);
        if (top == 0) {
            root = nd;
        }
    }
public:
    Tree() {
        root = newNode();
    }    
    void insert(int val) {
        if (size++ == 0) {
            root = newNode();
            root->val = val;
            return ;
        }
        Node *nd = root;
        int pos;
        while (1) {
            if (nd->val == val) {
                nd->cnt++;
                splay(nd);
                return;
            } else if (nd->son[ pos = (nd->val < val) ] == 0) {
                buildNode (nd, pos, val);
                splay (nd->son[pos]);
                return;
            } else {
                nd = nd->son[pos];
//                printf("here ");
            }
//            printf("SS");
        }
    }
    int getrank (int val) {
        int ret;
        insert(val);
        ret = root->son[0]->size;
        erase(val);
        return ret;
    }
    int getval (int rank) {
        Node *nd = root;
        int leftSize;
        while (1) {
            leftSize = (nd->son[0] ? nd->son[0]->size : 0);
            if(leftSize > rank) {
                nd = nd->son[0];
            } else if (leftSize + nd->cnt > rank) {
				splay(nd);
                return nd->val;
            } else {
                rank -= leftSize + nd->cnt;
                nd = nd->son[1];
            }
        }
    }
    int predecessor(int val) {
        Node *nd;
        int ret;
        insert(val);
        nd = root->son[0];
        while (nd->son[1]) {
            nd = nd->son[1];
        }
        ret = nd->val;
        splay(nd, root);
        erase(val);
        return ret;
    }
    int successor(int val) {
        Node *nd;
        int ret;
        insert(val);
        nd = root->son[1];
        while (nd->son[0]) {
            nd = nd->son[0];
        }
        ret = nd->val;
        splay(nd, root);
        erase(val);
        return ret;
    }
    void erase(int val) {
        insert(val);
        size-=2;
        if(root->cnt>2){
            root->cnt-=2;
            return;
        }
        Node *nd = root;
        if (nd->son[0] == 0) {
            root = nd->son[1];
            nd->son[1]->fa = 0;
        } else {
            nd = nd->son[0];
            while(nd->son[1]){
                nd = nd->son[1];
            }
            splay(nd, root);
            nd->son[1] = root->son[1];
            nd->son[1]->fa = nd;
            nd->fa = 0;
            root = nd;
        }
    }
    
}tree;


