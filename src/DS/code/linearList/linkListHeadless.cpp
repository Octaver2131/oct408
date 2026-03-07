#include <cstdlib>
#include <cstdio>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// ========== 基本操作 ==========
bool InitList(LinkList &L) {
    L = NULL;
    return true;
}

// 按位序插入（适配不带头结点）
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;

    if (i == 1) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }

    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL)
        return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定结点的后插操作（通用）
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定结点的前插操作（通用）
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 按位序删除（适配不带头结点）
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1 || L == NULL)
        return false;
    LNode *p;
    int j = 1;
    p = L;

    if (i == 1) {
        L = p->next;
        e = p->data;
        free(p);
        return true;
    }

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 指定结点的删除（通用）
bool DeleteNode(LNode *p) {
    if (p == NULL)
        return false;

    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    p->data = p->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找（适配不带头结点）
LNode *GetElem(LinkList L, int i) {
    if (i < 1 || L == NULL)
        return NULL;

    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找（适配不带头结点）
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 求表的长度（适配不带头结点）
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 尾插法建立单链表（适配不带头结点）
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = NULL;
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        if (L == NULL) {
            L = s;
            r = s;
        } else {
            r->next = s;
            r = s;
        }
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 头插法建立单链表（适配不带头结点）
LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = NULL;
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;
        L = s;
        scanf("%d", &x);
    }
    return L;
}

// ========== 补充操作 ==========
void PrintList(LinkList L) {
    printf("当前顺序表元素：");
    LNode *p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ========== 测试函数 ==========
int main() {
    LinkList L;
    ElemType e;
    LNode* node;

    // 1. 初始化单链表
    InitList(L);
    printf("\n===== 1. 初始化链表 =====\n");
    PrintList(L);

    // 2. 插入元素测试
    printf("\n===== 2. 按位插入元素测试 =====\n");
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 4, 40);
    ListInsert(L, 5, 50);
    PrintList(L);

    // 3. 前插操作测试
    printf("\n===== 3. 前插操作测试 =====\n");
    node = GetElem(L, 2); // 找第2个结点（值20）
    if (InsertPriorNode(node, 15)) {
        printf("在第2个结点前插入15成功！\n");
    } else {
        printf("前插操作失败！\n");
    }
    PrintList(L);

    // 4. 后插操作测试
    printf("\n===== 4. 后插操作测试 =====\n");
    node = GetElem(L, 4); // 找第4个结点（值30）
    if (InsertNextNode(node, 25)) {
        printf("在第4个结点后插入25成功！\n");
    } else {
        printf("后插操作失败！\n");
    }
    PrintList(L);

    // 5. 按位查找测试
    printf("\n===== 5. 按位查找测试 =====\n");
    node = GetElem(L, 3);
    if (node != NULL) {
        printf("第3个位置的元素是：%d\n", node->data);
    } else {
        printf("第3个位置的元素不存在！\n");
    }

    // 6. 按值查找测试
    printf("\n===== 6. 按值查找测试 =====\n");
    node = LocateElem(L, 40);
    if (node != NULL) {
        printf("找到值为%d的结点！\n", node->data);
    } else {
        printf("未找到元素40!\n");
    }

    // 7. 求链表长度测试
    printf("\n===== 7. 求链表长度测试 =====\n");
    int len = Length(L);
    printf("当前链表的长度为：%d\n", len);

    // 8. 按位删除测试
    printf("\n===== 8. 按位删除测试 =====\n");
    if (ListDelete(L, 6, e)) {
        printf("删除第6个位置的元素：%d 后：\n", e);
    } else {
        printf("按位删除失败！\n");
    }
    PrintList(L);

    // 9. 指定结点删除测试
    printf("\n===== 9. 指定结点删除测试 =====\n");
    node = GetElem(L, 3); // 找第3个结点
    if (DeleteNode(node)) {
        printf("删除第3个结点成功！\n");
    } else {
        printf("指定结点删除失败！\n");
    }
    PrintList(L);

    // 10. 尾插法建立新链表测试
    printf("\n===== 10. 尾插法建立新链表 =====\n");
    LinkList L_tail;
    List_TailInsert(L_tail);
    PrintList(L_tail);

    // 11. 头插法建立新链表测试
    printf("\n===== 11. 头插法建立新链表 =====\n");
    LinkList L_head;
    List_HeadInsert(L_head);
    PrintList(L_head);

    printf("\n===== 所有测试完成 =====\n");
    return 0;
}