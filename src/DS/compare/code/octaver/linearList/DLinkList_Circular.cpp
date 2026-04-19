#include <cstdlib>
#include <cstdio>

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

// 初始化空的循环双链表
bool InitDLinkList(DLinklist &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;  // 头结点的 prior 指向头结点自身
    L->next = L;   // 头结点的 next 指向头结点自身
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == L)
        return true;
    else
        return false;
}

// 判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p) {
    if (p->next == L)
        return true;
    else
        return false;
}

// 在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p的后继结点q
bool DeleteNextDNode(DNode *p) {
    DNode *q = p->next;
    if (q == p)  // 链表为空或p是最后一个结点
        return false;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

// 遍历打印循环双链表
void PrintDLinkList(DLinklist L) {
    if (Empty(L)) {
        printf("循环双链表为空！\n");
        return;
    }
    printf("循环双链表元素：");
    DNode *p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 测试主函数
int main() {
    DLinklist L;
    if (InitDLinkList(L)) {
        printf("循环双链表初始化成功！\n");
    } else {
        printf("初始化失败！\n");
        return 1;
    }

    // 插入测试
    DNode *s1 = (DNode *)malloc(sizeof(DNode));
    s1->data = 10;
    InsertNextDNode(L, s1);

    DNode *s2 = (DNode *)malloc(sizeof(DNode));
    s2->data = 20;
    InsertNextDNode(s1, s2);

    DNode *s3 = (DNode *)malloc(sizeof(DNode));
    s3->data = 30;
    InsertNextDNode(s2, s3);

    PrintDLinkList(L);

    // 删除测试
    DeleteNextDNode(s2);
    printf("删除s2的后继结点后：\n");
    PrintDLinkList(L);

    // 判断空和表尾测试
    printf("链表是否为空：%s\n", Empty(L) ? "是" : "否");
    printf("s2是否为表尾结点：%s\n", isTail(L, s2) ? "是" : "否");

    return 0;
}