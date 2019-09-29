Node * build(int arr[], int size) {    // 这里构建一个根节点为最小值的笛卡尔树
    std::stack<Node * > S;    // 存储最右边路径的栈
    Node *now, *next, *last;
    for (int i = 0; i < size; i++) {
        next = new Node(i, arr[i]); last = NULL;    // last用来指向最后被弹出栈的元素（若有弹出），它的作用后面会写到
        while (!S.empty()) {
            if (S.top()->val < next->val) {    // 若栈顶节点的键值比当前节点键值小了，那么当前节点就做栈顶节点的右子节点
                now = S.top();
                if (now->rights) {    // 而栈顶节点的原右子节点要变成当前节点的左子节点（由于前面一定与当前节点比较过了，栈顶节点右子树的键值一定都比当前节点大）
                    now->rights->parent = next;
                    next->lefts = now->rights;
                }
                now->rights = next;
                next->parent = now;
                break;
            }
            last = S.top();
            S.pop();
        }
        if (S.empty() && last) {    // 这里为了特判一种可能出现的情况，就是当前节点把栈全部弹空了，就要把原先的根节点作为当前节点的左子节点
            next->lefts = last;
            last->parent = next;
        }
        S.push(next);
    }
    while (!S.empty()) now = S.top(), S.pop();
    return now;
}
