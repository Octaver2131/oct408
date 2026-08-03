#if 0
/*
 * for - 循环语句的机器表示
 */

// 通用形式
for(init_expr; test_expr; update_expr)
    body_statement            // body_statement 为循环体执行语句


// 等价的 while 语句形式
init_expr;                    // 初始化（只执行一次）
while(test_expr) {            // 每次循环前判断条件
    body_statement            // 执行循环体
    update_expr;              // 更新循环变量
}


// 等价的 goto 语句形式
init_expr;                    // 执行初始化
t = test_expr;                // 测试初始条件
if(!t)                        // 若初始条件为假
    goto done;                // 跳过循环
loop:
body_statement                // 执行循环体
update_expr;                  // 执行更新操作
t = test_expr;                // 重新测试条件
if(t)                         // 若条件仍为真
    goto loop;                // 跳回循环体
done:


// C 语言函数示例
int nsum_for(int n) {
    int i;
    int result = 0;
    for (i = 1; i <= n; i++)
        result += i;
    return result;
}


// 对应汇编代码
mov  ecx, dword ptr [ebp+8]   // R[ecx]←M[R[ebp]+8]，即加载参数n到ecx
mov  eax, 0                   // R[eax]←0，即初始化result=0
mov  edx, 1                   // R[edx]←1，即初始化i=1
cmp  edx, ecx                 // 比较i与n（R[edx]与R[ecx]）并设置标志位
jg   .L2                      // If greater，则转移到L2
.L1:                          // 循环体入口
add  eax, edx                 // R[eax]←R[eax]+R[edx]，即result +=i
add  edx, 1                   // R[edx]←R[edx]+1，即i++
cmp  edx, ecx                 // 再次比较i:n
jle  .L1                      // If less or equal，则转移到L1
.L2:                          // 循环结束点

#endif