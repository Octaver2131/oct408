#include <cstdlib>
#include <cstdio>

#define InitSize 10

typedef int ElemType;
typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;

// ========== 基本操作 ==========
void InitList(SeqList &L) {
    // 用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];  // 将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;  // 顺序表最大长度增加 len
    free(p);  // 释放原来的内存空间
}

// 顺序表插入操作
bool ListInsert(SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)  // 判断i的范围是否有效
        return false;
    if (L.length >= L.MaxSize)  // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--)  // 将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;  // 在位置i处放入e
    L.length++;  // 长度加1
    return true;
}

// 顺序表删除操作
bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length)  // 判断i的范围是否有效
        return false;
    e = L.data[i - 1];  // 将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)  // 将第i个位置之后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;  // 线性表长度减1
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
// 新增：打印顺序表内容的辅助函数（改用printf）
void PrintList(SeqList L) {
    printf("当前顺序表元素：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n顺序表当前长度：%d，最大容量：%d\n", L.length, L.MaxSize);
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
    ListInsert(L, 4, 40);
    ListInsert(L, 5, 50);
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

    // 6. 扩容测试
    printf("\n===== 扩容测试 =====\n");
    IncreaseSize(L, 5);
    printf("扩容5个容量后：\n");
    PrintList(L);

    // 7. 边界测试：插入超出最大长度
    printf("\n===== 边界测试 =====\n");
    for (int i = L.length + 1; i <= L.MaxSize; i++) {
        ListInsert(L, i, i * 10);
    }
    printf("插入到满容量后：\n");
    PrintList(L);

    if (!ListInsert(L, L.length + 1, 100)) {
        printf("插入失败：顺序表已达最大长度！\n");
    }

    free(L.data);
    L.data = NULL;

    return 0;
}