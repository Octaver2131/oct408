#if 0

/*
 * 单链表 - 不带头结点
 */

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 单链表的初始化
bool InitList(LinkList &L) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

#endif