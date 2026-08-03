#if 0
/*
 * do-while - 循环语句的机器表示
 */

// 通用形式
do                            // 先执行循环体，再判断循环条件
    body_statement            // body_statement 为循环体执行语句
while(test_expr);             // test_expr 为循环继续的条件表达式


// 等价的 goto 语句形式
loop:                         // 循环入口标签
body_statement                // 执行循环体语句（首次进入时必然执行）
t = test_expr;                // 计算循环条件
if(t)                         // 若条件为真（t≠0）
    goto loop;                // 跳回 loop 标签，继续下一轮迭代

#endif