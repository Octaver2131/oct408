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
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 按位序插入
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
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

// 指定结点的后插操作
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

// 指定结点的前插操作
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

// 按位序删除
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
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

// 指定结点的删除
bool DeleteNode(LNode *p) {
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找
LNode *GetElem(LinkList L, int i) {
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

// 求表的长度
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// ========== 补充操作 ==========
// 按位序插入
bool _ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    return InsertNextNode(p, e);
}

void PrintList(LinkList L) {
    printf("当前顺序表元素：");
    LNode *p = L->next;
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
    printf("\n===== 初始化顺序表 =====\n");
    InitList(L);
    if (InitList(L)) {
        printf("单链表初始化成功！\n");
    } else {
        printf("单链表初始化失败！\n");
    }
    PrintList(L);

    // 2. 插入元素测试
    printf("\n===== 插入元素测试 =====\n");
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 4, 40);
    ListInsert(L, 5, 50);
    PrintList(L);

    // 3. 前插操作测试
    printf("\n===== 前插操作测试 =====\n");
    node = GetElem(L, 2);
    if (InsertPriorNode(node, 15)) {
        printf("在第2个结点前插入15成功！\n");
    } else {
        printf("前插操作失败！\n");
    }
    PrintList(L);

    // 4. 后插操作测试
    printf("\n===== 后插操作测试 =====\n");
    node = GetElem(L, 4);  // 找到第4个结点（值为30）
    if (InsertNextNode(node, 25)) {
        printf("在第4个结点后插入25成功！\n");
    } else {
        printf("后插操作失败！\n");
    }
    PrintList(L);

    // 3. 按位查找测试
    printf("\n===== 按位查找测试 =====\n");
    node = GetElem(L, 3);
    if (node != NULL) {
        printf("第3个位置的元素是：%d\n", node->data);
    } else {
        printf("第3个位置的元素不存在！\n");
    }

    // 6. 按值查找测试
    printf("\n===== 按值查找测试 =====\n");
    node = LocateElem(L, 40);
    if (node != NULL) {
        printf("找到值为%d的结点！\n", node->data);
    } else {
        printf("未找到元素40!\n");
    }

    // 7. 求链表长度测试
    printf("\n===== 求链表长度测试 =====\n");
    int len = Length(L);
    printf("当前链表的长度为：%d\n", len);

    // 8. 按位删除测试
    printf("\n===== 按位删除测试 =====\n");
    if (ListDelete(L, 6, e)) {
        printf("删除第6个位置的元素：%d 后：\n", e);
    } else {
        printf("按位删除失败！\n");
    }
    PrintList(L);

    // 9. 指定结点删除测试
    printf("\n===== 指定结点删除测试 =====\n");
    node = GetElem(L, 3);
    if (DeleteNode(node)) {
        printf("删除第3个结点成功！\n");
    } else {
        printf("指定结点删除失败！\n");
    }
    PrintList(L);

    // 10. 尾插法建立新链表测试
    printf("\n===== 尾插法建立新链表 =====\n");
    LinkList L_tail;
    List_TailInsert(L_tail);
    printf("尾插法建立的链表：");
    PrintList(L_tail);

    // 11. 头插法建立新链表测试
    printf("\n===== 头插法建立新链表 =====\n");
    LinkList L_head;
    List_HeadInsert(L_head);
    printf("头插法建立的链表（逆序）：");
    PrintList(L_head);

    // 12. 复用版按位插入测试
    printf("\n===== 复用后插的按位插入测试 =====\n");
    if (_ListInsert(L, 5, 35)) {
        printf("在第5个位置插入35成功！\n");
    } else {
        printf("插入失败！\n");
    }
    PrintList(L);

    printf("\n===== 所有测试完成 =====\n");
    return 0;
}
