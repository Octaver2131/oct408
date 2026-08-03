#if 0

/*
 * 顺序表 - 静态分配
 */

#define InitSize 100

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

// C 的初始动态分配语句为
// L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);

// C++的初始动态分配语句为
// L.data = new ElemType[InitSize];

// 顺序表的初始化
void InitList(SeqList &L){
    L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
}

#endif