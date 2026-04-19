#include <cstdlib>
#define MaxSize 50
typedef int ElemType;

typedef struct LinkNode{                //链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{                         //链式队列
    LinkNode *front, *rear;            //队列的队头和队尾指针
}LinkQueue;

// 1. 初始化
void InitQueue(LinkQueue &Q) {         //初始化带头结点的链式队列
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
    Q.front->next = NULL;               //初始为空
}

// 2. 判队空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)             //判空条件
        return true;
    else
        return false;
}

// 3. 入队
void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode)); //创建新结点
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;                  //插入链尾
    Q.rear = s;                        //修改尾指针
}

// 4. 出队
bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (Q.front == Q.rear)             //空队
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;              //若原队列中只有一个结点，删除后变空
    free(p);
    return true;
}