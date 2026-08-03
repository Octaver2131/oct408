#if 0
/*
 * if-else - 选择语句的机器表示
 */

// 通用形式
if (test_expr)                // test_expr 为条件测试表达式
    then_statement            // 当 test_expr 为真时，执行 then_statement 语句
elsevv
    else_statement            // 当 test_expr 为假时，执行 else_statement 语句


// 等价的 goto 语句形式
t = test_expr;                // 暂存测试表达式的结果
if (!t)                       // 若条件为假（t=0）
    goto false;               // 转移至 false 标签，进入假分支
then_statement                // 真分支：仅当 t≠0 时执行
goto done;                    // 执行完真分支后，跳过假分支，转移至结束点
false:                        // 假分支入口标签
else_statement                // 假分支：仅当 t=0 时执行
done:                         // 整个 if-else 结构的结束点


// C 语言函数示例
int get_cont(int *p1, int *p2) {
    if (p1 > p2)
        return *p2;
    else
        return *p1;
}


// 对应汇编代码
mov eax, dword ptr [ebp+8]    // R[eax] ← M[R[ebp]+8]，即加载参数p1到eax
mov edx, dword ptr [ebp+12]   // R[edx] ← M[R[ebp]+12]，即加载参数p2到edx
cmp eax, edx                  // 比较p1和p2，根据结果设置条件码
jbe .L1                       // 若p1<=p2，则转移到L1
mov eax, dword ptr [edx]      // R[eax] ← M[R[edx]]，即取*p2作为返回值
jmp .L2                       // 无条件转移到L2，跳过else分支
.L1:
mov eax, dword ptr [eax]      // R[eax] ← M[R[eax]]，即取*p1作为返回值
.L2:

#endif