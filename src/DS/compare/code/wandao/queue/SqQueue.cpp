#include <cstdlib>
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];        //用数组存放队列元素
    int front, rear;                //队首指针和队尾指针
} SqQueue;

// ========== 基本操作 ==========

// 1. 初始化
void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;           //初始化队首、队尾指针
}

// 2. 判队空
bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front)         //队空条件
        return true;
    else
        return false;
}

// 3. 入队
bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)  //队满则报错
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;         //队尾指针加1取模
    return true;
}

// 4. 出队
bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)                  //队空则报错
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;      //队首指针加1取模
    return true;
}