#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

/*
 * 栈的顺序存储
 */

#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack &S) {
    S.top = -1;
}

// 判栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

// 入栈
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}