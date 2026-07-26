#if 0

/*
 * Swap 指令
 *
 * 违背 “让权等待” 准则
 */

// 功能描述
void Swap(boolean *a, boolean *b) {
    boolean temp = *a;
    *a = *b;
    *b = temp;
}

// 经典实现
boolean key = true;
while (key != false)
Swap(&lock, &key);
进程的临界区代码段;
lock = false;
进程的其他代码;

#endif
