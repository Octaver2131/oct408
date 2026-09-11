#if 0

/*
 * 堆选择排序
 */

// /堆调整筛选
void HeapAdjust(ElemType A[], int k, int len) {
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1])
            i++;
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

// 构立大根堆
void BuildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2; i > 0; i--)
        HeapAdjust(A, i, len);
}

//堆排序
void HeapSort(ElemType A[], int len){
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--) {
        swap(A[i], A[1]);
        HeapAdjust(A, 1, i-1);
    }
}

#endif