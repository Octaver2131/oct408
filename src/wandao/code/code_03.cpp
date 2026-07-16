#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

/*
 * 单链表 - 带头结点
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

// 求表长操作
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 按序号查找结点
LNode *GetElem(LinkList L, int i) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找表结点
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while(p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 插入结点操作
bool ListInsert(LinkList &L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 对某个结点进行前插操作
// s->next = p->next;
// p->next = s;
// temp = p->data;
// p->data = s->data;
// s->data = temp;

// 删除结点操作
bool ListDelete(LinkList &L, int i, ElemType &e){
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 删除指定结点 *p
// LNode *q = p->next;
// p->data = p->next->data;
// p->next = q->next;
// free(q);

// 采用头插法建立单链表
LinkList List_HeadInsert (LinkList &L) {
    LNode *s; int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

// 采用尾插法建立单链表
LinkList List_TailInsert (LinkList &L) {
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode *s,*r = L;
    scanf("%d", &x);
    while(x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}