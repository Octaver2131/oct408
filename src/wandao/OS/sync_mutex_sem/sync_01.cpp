#if 0

/**
 * 生产者-消费者问题
 */

semaphore mutex = 1;           // 互斥访问缓冲区
semaphore empty = n;           // 空缓冲区数量
semaphore full = 0;            // 满缓冲区数量

producer () {                  // 生产者进程
    while(1) {
        生产一个产品;
        P(empty);              // 申请一个空缓冲区
        P(mutex);              // 进入临界区
        将产品放入缓冲区;
        V(mutex);              // 退出临界区
        V(full);               // 满缓冲区数加 1
    }
}

consumer () {                  // 消费者进程
    while(1) {
        P(full);               // 申请一个满缓冲区
        P(mutex);              // 进入临界区
        从缓冲区中取出一个产品;
        V(mutex);              // 退出临界区
        V(empty);              // 空缓冲区数加 1
        消费产品;
    }
}

#endif