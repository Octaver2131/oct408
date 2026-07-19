#if 0

/*
 * 队列的顺序存储 - 循环队列
 */

#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

// 判队空
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

// 入队
bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

#endif