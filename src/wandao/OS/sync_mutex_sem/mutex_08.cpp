#if 0

/*
 * 互斥锁
 *
 * 违背 “让权等待” 准则
 */

// 功能描述
acquire() {                   // 获得锁的定义
    while (!available)        // 忙等待
        ;
    available = false;        // 获得锁
}

release() {                   // 释放锁的定义
    available = true;         // 释放锁
}

#endif
