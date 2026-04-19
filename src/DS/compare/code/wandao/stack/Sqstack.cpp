#include <cstdlib>
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];     //存放栈中元素
    int top;                    //栈顶指针
} SqStack;

// ========== 基本操作 ==========

// 1. 初始化
void InitStack(SqStack &S) {
    S.top = -1;                 //初始化栈顶指针
}

// 2.判栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)            //栈空
        return true;
    else                        //不空
        return false;
}

// 3. 入栈
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1)   //栈满，报错
        return false;
    S.data[++S.top] = x;        //指针先加1，再入栈
    return true;
}

// 4. 出栈
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)            //栈空，报错
        return false;
    x = S.data[S.top--];        //先出栈，指针再减1
    return true;
}

// 5. 读栈顶元素
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)            //栈空，报错
        return false;
    x = S.data[S.top];          //x记录栈顶元素
    return true;
}