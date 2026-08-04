#if 0

/**
 * 哲学家进餐问题
 */

// 存在死锁
semaphore chopstick[5] = {1, 1, 1, 1, 1};  // 初始化5根筷子的信号量
Pi() {                                     // i 号哲学家进程
    do {
        P(chopstick[i]);                   // 拿起左侧筷子
        P(chopstick[(i + 1) % 5]);         // 拿起右侧筷子
        进餐;
        V(chopstick[i]);                   // 放回左侧筷子
        V(chopstick[(i + 1) % 5]);         // 放回右侧筷子
        思考;
    } while(1);
}

// 破坏死锁 - 增设互斥量 mutex
semaphore chopstick[5] = {1, 1, 1, 1, 1};  // 初始化5根筷子的信号量
semaphore mutex = 1;                       // 设置取筷子的互斥信号量
Pi() {                                     // i 号哲学家的进程
    do {
        P(mutex);                          // 申请取筷子的权限
        P(chopstick[i]);                   // 拿起左侧筷子
        P(chopstick[(i + 1) % 5]);         // 拿起右侧筷子
        V(mutex);                          // 释放取筷子的权限
        进餐;
        V(chopstick[i]);                   // 放回左侧筷子
        V(chopstick[(i + 1) % 5]);         // 放回右侧筷子
        思考;
    } while(1);
}

// 写者优先

#endif