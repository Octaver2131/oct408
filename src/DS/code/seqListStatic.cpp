#include <cstdio>
#define MaxSize 10

typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;


void InitList(SqList& L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}


bool ListInsert(SqList& L, int i, int e)
{
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


bool ListDelete(SqList& L, int i, int& e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length --;
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


void PrintList(SqList L)
{
    printf("当前顺序表元素: ");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


int main()
{
    SqList L;
    InitList(L);

    printf("顺序表初始化完成。\n");
    printf("初始MaxSize: %d, 初始length: %d\n\n", MaxSize, L.length);

    // 测试插入操作
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    printf("插入元素 10, 20, 30 后:\n");
    PrintList(L);
    printf("当前length: %d\n\n", L.length);

    // 测试获取元素
    ElemType elem = GetElem(L, 1);
    printf("第1位元素：%d\n\n", elem);

    // 测试查找元素
    int pos = LocateElem(L, 20);
    printf("元素20的位置：%d\n\n", pos);

    // 测试删除元素
    ElemType deletedElem;
    ListDelete(L, 2, deletedElem);
    printf("删除第 2 个元素 (值为: %d) 后:\n", deletedElem);
    PrintList(L);
    printf("当前length: %d\n\n", L.length);

    return 0;  // 程序正常结束
}