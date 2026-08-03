#if 0
/*
 * while - 循环语句的机器表示
 */

// 通用形式
while(test_expr)              // test_expr 为循环判断的条件表达式
    body_statement            // 当 test_expr 为真时重复执行 body_statement 语句


// 等价的 do-while 语句形式
t = test_expr;                // 计算初始循环条件
if(!t)                        // 若初始条件为假（t=0）
    goto done;                // 跳过循环体，直接转至结束点
do
    body_statement            // 执行循环体
while(test_expr);             // 重新测试条件
done:                         // 循环结构的结束点


// 等价的 goto 语句形式
t = test_expr;                // 计算初始循环条件
if(!t)                        // 若为假
    goto done;                // 跳过循环
loop:
body_statement                // 执行循环体
t = test_expr;                // 重新计算条件
if(t)                         // 若仍为真
    goto loop;                // 继续下一轮
done:                         // 循环结束

#endif