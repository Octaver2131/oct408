#if 0

/*
 * 顺序查找
 */

typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

// 顺序查找
int Search_Seq(SSTable ST,ElemType key) {
    ST.elem[0] = key;
    for (int i = ST.TableLen; ST.elem[i] != key; --i);
    return i;
}

#endif