#include <cstdlib>
#include <cstdio>

#define InitSize 10

typedef int ElemType;
typedef struct
{
    int* data;
    int MaxSize;
    int length;
}SqList;


void InitList(SqList& L)
{
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}


void IncreaseSize(SqList& L, int len)
{
    int* p = L.data;
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];
    L.MaxSize = L.MaxSize + len;
    free(p);
}


bool ListInsert(SqList& L, int i, int e)
{
    if (i<1 || i>L.length + 1)
        return false;
    if (L.length >= L.MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}


bool ListDelete(SqList& L, int i, int& e)
{
    if (i<1 || i>L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}


ElemType GetElem(SqList L, int i)
{
    return L.data[i - 1];
}


int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}


// 打印顺序表
void PrintList(SqList L) {
    printf("当前顺序表元素: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    InitList(L);

    printf("顺序表初始化完成。\n");
    printf("初始MaxSize: %d, 初始length: %d\n\n", L.MaxSize, L.length);

    // 测试插入
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    printf("插入元素 10, 20, 30 后:\n");
    PrintList(L);
    printf("当前length: %d\n\n", L.length);

    // 测试按位查找
    ElemType elem = GetElem(L, 2);
    printf("第 2 个位置的元素: %d\n\n", elem);

    // 测试按值查找
    int pos = LocateElem(L, 20);
    printf("元素 20 的位置: %d\n\n", pos);

    // 测试删除
    ElemType deletedElem;
    ListDelete(L, 2, deletedElem);
    printf("删除第 2 个元素 (值为: %d) 后:\n", deletedElem);
    PrintList(L);
    printf("当前length: %d\n\n", L.length);

    // 测试扩容
    IncreaseSize(L, 5);
    printf("扩容后 MaxSize: %d\n\n", L.MaxSize);

    // 继续插入测试
    ListInsert(L, 3, 40);
    ListInsert(L, 4, 50);
    printf("继续插入元素 40, 50 后:\n");
    PrintList(L);
    printf("当前length: %d\n", L.length);

    // 释放内存
    free(L.data);
    return 0;
}