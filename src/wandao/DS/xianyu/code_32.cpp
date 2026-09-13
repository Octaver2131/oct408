#if 0

/*
 * 计数排序
 */

// 计数操作
void CountSort(ElemType A[], ElemType B[], int n, int k) {
    int i, C[k];
    for (i = 0; i < k; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
        C[A[i]] = C[A[i]] + 1;
    for (i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];
    for (i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
}

#endif
