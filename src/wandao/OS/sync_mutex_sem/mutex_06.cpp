#if 0

/*
 * TestAndSet 指令
 *
 * 违背 “让权等待” 准则
 */

// 功能描述
boolean TestAndSet(boolean *lock) {
    boolean old;
    old = *lock;               // old 用来存放 lock 的旧值
    *lock = true;              // 将 lock 置为 true
    return old;                // 返回 lock 的旧值
}

// 经典实现
while (TestAndSet(&lock));     // 尝试获取锁（忙等待）
进程的临界区代码段;
lock = false;                  // 解锁
进程的其他代码;

#endif
