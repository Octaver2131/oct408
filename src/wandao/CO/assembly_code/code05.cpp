#if 0
/*
 * 函数调用 - 循环语句的机器表示
 */

// C 语言函数示例
int add(int x, int y){
    return x + y;
}

int caller() {
    int temp1 = 125;
    int temp2 = 80;
    int sum = add(temp1, temp2);
    return sum;
}


// 对应汇编代码
caller:
push ebp                    // 保存调用者P的EBP
mov ebp, esp                // 建立新栈帧：EBP←当前栈顶
sub esp, 24                 // 为局部变量和参数区分配24字节空间
mov [ebp-12], 125           // M[R[ebp]-12]←125，即temp1=125
mov [ebp-8], 80             // M[R[ebp]-8]←80，即temp2=80
mov eax,dword ptr [ebp-8]   // R[eax]←M[R[ebp]-8]，加载temp2
mov [esp+4], eax            // M[R[esp]+4]←R[eax]，将temp2放入参数区高地址
mov eax,dword ptr [ebp-12]  // R[eax]←M[R[ebp]-12]，加载temp1
mov [esp], eax              // M[R[esp]]←R[eax]，将temp1放入参数区低地址
call add                    // 调用add，返回值保存于eax
mov [ebp-4], eax            // M[R[ebp]-4]←R[eax]，将返回值存入sum
mov eax, dword ptr [ebp-4]  // R[eax]←M[R[ebp]-4]，将sum作为返回值
leave                       // 等价于 mov esp,ebp 和 pop ebp
ret                         // 弹出返回地址并跳回

#endif