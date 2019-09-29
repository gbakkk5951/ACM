struct HeapNode{
	HeapNode *f,*l,*r,*qj;
	int val,sig,npl;
}heap[600010],*root;
int add;
struct _Main{
HeapNode *getfa(HeapNode *a){
	while(a->f!=a)a=a->f;
	return a;
}
void inline pushdown(HeapNode *a){
	if(a->sig){
		if(a->l){
			a->l->sig+=a->sig;
			a->l->val+=a->sig;
		}
		if(a->r){
			a->r->sig+=a->sig;
			a->r->val+=a->sig;
		}
		a->sig=0;		
	}
}
stack<HeapNode *>stk;
void getsig(HeapNode *a){
	do{
		a=a->f;
		stk.push(a);
	}while(a!=a->f);
	while(!stk.empty()){
		pushdown(stk.top());
		stk.pop();
	}
}
HeapNode * merge(HeapNode *a,HeapNode *b){
	if(a==0)return b;
	if(b==0)return a;
	if(a->val<b->val){
		swap(a,b);
	}
	pushdown(a);
	a->r=merge(a->r,b);
	a->r->f=a;
	if(a->l == 0 || a->l->npl<a->r->npl ){
		swap(a->l,a->r);
	}a->npl=a->r?a->r->npl+1:0;
	return a;
}
HeapNode *del(HeapNode *a){
	
	HeapNode *temp=0;
	pushdown(a);
	temp=merge(a->l,a->r);
	if(temp) temp->f=temp;
	if(a->f!=a){
		if(a->f->l==a){
			a->f->l=temp;
		}else if(a->f->r==a) {
			a->f->r=temp;
		}
		if(temp)temp->f=a->f;
		temp=getfa(a->f);
	}
	a->l=a->r=0;a->f=a;a->npl=0;
	
	return temp;
}

