#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

/*
 * 双链表
 */

typedef struct DNode {
    ElemType data;
    struct DNode *prior,*next;
} DNode, *DLinklist;

// 双链表的插入操作
// s->next = p->next;
// p->next->prior= s;
// s->prior = p;
// p->next = s;

// 双链表的删除操作
// p->next=q->next;
// q->next->prior=p;
// free(q);