#if 0

/*
 * 线索二叉树
 */

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

// 中序遍历二叉树线索化 - 递归
void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// 建立中序线索二叉树
void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL){
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 求中序序列的第一个结点
ThreadNode *Firstnode(ThreadNode *p) {
    while (p->ltag == 0) p = p->lchild;
    return p;
}

// 求结点 p 在中序序列中的后继
ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

// 中序遍历二叉树线索化 - 非递归
void Inorder(ThreadNode *T) {
    for (ThreadNode *p = Firstnode(T); p !=NULL; p = Nextnode(p))
        visit(p);
}

#endif