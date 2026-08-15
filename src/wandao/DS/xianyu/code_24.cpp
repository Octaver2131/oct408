#if 0

/*
 * 直接插入排序
 */

// 直接插入排序 - 带哨兵
void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++)
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; --j)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
}

#endif