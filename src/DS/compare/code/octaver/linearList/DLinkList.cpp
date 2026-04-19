#include <cstdlib>
#include <cstdio>

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

// ========== 基本操作 ==========
bool InitDLinkList(DLinklist &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 判断双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}

// 插入
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除
bool DeleteNextDNode(DNode *p) {
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

// 销毁
void DestroyList(DLinklist &L) {

    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}

// ========== 补充操作 ==========
// 遍历打印双链表
void PrintDLinkList(DLinklist L) {
    if (Empty(L)) {
        printf("双链表为空！\n");
        return;
    }
    printf("双链表元素（正序）：");
    DNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 可选：反向打印（验证前驱指针）
    printf("双链表元素（逆序）：");
    p = L->next;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    while (p != L) {
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n");
}


// 按位查找
DNode *GetElem(DLinklist L, int i) {
    if (i < 0 || Empty(L))
        return NULL;
    DNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// ========== 测试函数 ==========
int main() {
    DLinklist L;
    ElemType e;

    // 1. 初始化双链表
    printf("===== 初始化双链表 =====\n");
    if (InitDLinkList(L)) {
        printf("双链表初始化成功！\n");
    } else {
        printf("双链表初始化失败！\n");
    }
    PrintDLinkList(L);

    // 2. 插入元素测试（按位插入）
    printf("\n===== 插入元素测试 =====\n");
    DNode *s1 = (DNode *)malloc(sizeof(DNode));
    s1->data = 10;
    InsertNextDNode(L, s1);

    DNode *p = GetElem(L, 1);
    DNode *s2 = (DNode *)malloc(sizeof(DNode));
    s2->data = 20;
    InsertNextDNode(p, s2);

    p = GetElem(L, 2);
    DNode *s3 = (DNode *)malloc(sizeof(DNode));
    s3->data = 30;
    InsertNextDNode(p, s3);

    PrintDLinkList(L);

    // 3. 按位查找测试
    printf("\n===== 按位查找测试 =====\n");
    DNode *node = GetElem(L, 2);
    if (node != NULL) {
        printf("第2个位置的元素是：%d\n", node->data);
    } else {
        printf("第2个位置的元素不存在！\n");
    }

    // 4. 删除元素测试
    printf("\n===== 删除元素测试 =====\n");
    p = GetElem(L, 2);
    if (DeleteNextDNode(p)) {
        printf("删除第3个结点成功！\n");
    } else {
        printf("指定结点删除失败！\n");
    }
    PrintDLinkList(L);

    // 5. 判断链表是否为空
    printf("\n===== 5判断链表是否为空 =====\n");
    if (Empty(L)) {
        printf("当前双链表为空！\n");
    } else {
        printf("当前双链表非空！\n");
    }

    // 6. 销毁双链表
    printf("\n===== 销毁双链表 =====\n");
    DestroyList(L);
    if (L == NULL) {
        printf("双链表销毁成功！\n");
    } else {
        printf("双链表销毁失败！\n");
    }

    printf("\n===== 所有测试完成 =====\n");
    return 0;
}