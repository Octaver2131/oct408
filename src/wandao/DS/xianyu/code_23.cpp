#if 0

/*
 * 二叉排序树
 */

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BSTNode, *BiTree;

// 二叉排序树查找 - 循环
BSTNode *BST_Search(BiTree T, ElemType key) {
    while (T != NULL && key != T->data) {
        if (key < T->data) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}

// 二叉排序树插入
int BST_Insert(BiTree &T, ElemType k) {
    if (T == NULL) {
        T = (BiTree)malloc(sizeof(BSTNode));
        T->data = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if(k == T->data)
        return 0;
    else if(k < T->data)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

// 构造二叉排序树
void Creat_BST(BiTree &T, ElemType str[], int n) {
    T = NULL;
    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i]);
        i++;
    }
}

#endif