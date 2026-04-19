#include <cstdio>
#include <cstdlib>

#define MaxSize 50      // 定义栈中元素的最大个数
typedef int ElemType;  // 定义栈中元素的类型

typedef struct {
    ElemType data[MaxSize];  // 存放栈中元素的数组
    int top;                 // 栈顶指针（指向当前栈顶元素下标）
} SqStack;

// ========== 基本操作 ==========

// 1. 初始化栈
void InitStack(SqStack &S) {
    S.top = -1;  // 初始化栈顶指针，栈空时top为-1
}

// 2. 判断栈是否为空
bool StackEmpty(SqStack S) {
    if (S.top == -1)  // 栈空条件：top为-1
        return true;
    else
        return false;
}

// 3. 入栈操作（元素x进栈）
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1)  // 栈满条件：top等于数组最大下标
        return false;          // 栈满，入栈失败
    S.data[++S.top] = x;       // 栈顶指针先+1，再将元素存入栈顶位置
    return true;
}

// 4. 出栈操作（栈顶元素出栈，存入x）
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)  // 栈空，无法出栈
        return false;
    x = S.data[S.top--];  // 先取出栈顶元素，再将栈顶指针-1
    return true;
}

// 5. 读取栈顶元素（不删除）
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)  // 栈空，无栈顶元素
        return false;
    x = S.data[S.top];  // 直接读取栈顶元素的值，栈顶指针不变
    return true;
}

// ========== 补充操作 ==========

// 打印栈中所有元素（从栈底到栈顶）
void PrintStack(SqStack S) {
    printf("当前栈中元素（栈底→栈顶）：");
    for (int i = 0; i <= S.top; i++) {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

// 求栈的长度
int StackLength(SqStack S) {
    return S.top + 1;  // 栈顶指针+1即为元素个数
}

// ========== 测试函数 ==========
int main() {
    SqStack S;
    ElemType e;

    // 1. 初始化栈
    printf("\n===== 初始化顺序栈 =====\n");
    InitStack(S);
    printf("栈初始化完成，当前栈是否为空：%s\n", StackEmpty(S) ? "是" : "否");
    PrintStack(S);

    // 2. 入栈测试
    printf("\n===== 入栈操作测试 =====\n");
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    Push(S, 40);
    Push(S, 50);
    printf("依次入栈10、20、30、40、50后：\n");
    PrintStack(S);
    printf("当前栈的长度为：%d\n", StackLength(S));

    // 3. 读取栈顶元素测试
    printf("\n===== 读取栈顶元素测试 =====\n");
    if (GetTop(S, e)) {
        printf("当前栈顶元素为：%d\n", e);
    } else {
        printf("读取栈顶元素失败（栈空）！\n");
    }

    // 4. 出栈测试
    printf("\n===== 出栈操作测试 =====\n");
    if (Pop(S, e)) {
        printf("出栈成功，出栈元素为：%d\n", e);
    } else {
        printf("出栈失败（栈空）！\n");
    }
    printf("出栈后栈的状态：\n");
    PrintStack(S);

    // 5. 再次读取栈顶元素
    printf("\n===== 再次读取栈顶元素 =====\n");
    GetTop(S, e);
    printf("当前栈顶元素为：%d\n", e);

    // 6. 栈空/栈满边界测试
    printf("\n===== 栈空边界测试 =====\n");
    // 依次出栈直到栈空
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("出栈元素：%d\n", e);
    }
    printf("栈已空，此时出栈操作：%s\n", Pop(S, e) ? "成功" : "失败");
    printf("栈空时读取栈顶元素：%s\n", GetTop(S, e) ? "成功" : "失败");

    printf("\n===== 所有测试完成 =====\n");
    return 0;
}