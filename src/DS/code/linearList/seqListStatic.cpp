#include <cstdio>
#define MaxSize 10

typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

// ========== 基本操作 ==========
void InitList(SeqList &L) {
    L.length = 0;
}

bool ListInsert(SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

ElemType GetElem(SeqList L, int i) {
    return L.data[i - 1];
}

int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// ========== 补充操作 ==========
void PrintList(SeqList L) {
    printf("当前顺序表元素：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n当前顺序表长度：%d\n", L.length);
}

// ========== 测试函数 ==========
int main() {
    SeqList L;
    ElemType elem;
    ElemType deleteElem;
    int loc;

    // 1. 初始化顺序表
    InitList(L);
    printf("\n===== 初始化顺序表 =====\n");
    PrintList(L);

    // 2. 插入元素测试
    printf("\n===== 插入元素测试 =====\n");
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 2, 15);
    PrintList(L);

    // 3. 按位查找测试
    printf("\n===== 按位查找测试 =====\n");
    elem = GetElem(L, 3);
    printf("第3个位置的元素是：%d\n", elem);

    // 4. 按值查找测试
    printf("\n===== 按值查找测试 =====\n");
    loc = LocateElem(L, 30);
    if (loc != 0) {
        printf("元素30的位置是：%d\n", loc);
    } else {
        printf("未找到元素30\n");
    }

    // 5. 删除元素测试
    printf("\n===== 删除元素测试 =====\n");
    if (ListDelete(L, 3, deleteElem)) {
        printf("删除第3个位置的元素：%d 后：\n", deleteElem);
        PrintList(L);
    } else {
        printf("删除失败\n");
    }

    // 6. 边界测试：插入超出最大长度
    printf("\n===== 边界测试 =====\n");
    for (int i = 4; i <= 10; i++) {
        ListInsert(L, i, i * 10);
    }
    PrintList(L);

    if (!ListInsert(L, 11, 110)) {
        printf("插入失败：顺序表已达最大长度！\n");
    }

    return 0;
}