#if 0

/**
 * 读者-写者问题
 */

// 读者优先
int count = 0;                 // 记录当前的读者数量
semaphore mutex = 1;           // 控制对 count 的互斥访问
semaphore rw = 1;              // 控制读者与写者对文件的互斥访问

writer() {                     // 写者进程
    while(1) {
        P(rw);                 // 申请对文件的独占写权限
        写文件;
        V(rw);                 // 释放文件写权限
    }
}

reader() {                     // 读者进程
    while(1) {
        P(mutex);              // 互斥访问 count
        if(count == 0)         // 若是第一个读者
            P(rw);             // 阻止写者访问文件
        count++;               // 读者数量加 1
        V(mutex);              // 释放对 count 的访问
        读文件;
        P(mutex);              // 互斥访问 count
        count--;               // 读者数量减 1
        if(count == 0)         // 是最后一个读者
            V(rw);             // 允许写者访问文件
        V(mutex);              // 释放对 count 的访问
    }
}

// 写者优先
int count = 0;               // 记录当前的读者数量
semaphore mutex = 1;         // 控制对 count 的互斥访问
semaphore rw = 1;            // 控制读者与写者对文件的互斥访问
semaphore w = 1;             // 实现写者优先的关键信号量

writer() {                   // 写者进程
    while(1) {
        P(w);                // 申请写者优先权：阻止新读者进入
        P(rw);               // 申请对文件的独占写权限
        写文件;
        V(rw);               // 释放文件写权限
        V(w);                // 释放写者优先权，允许其他进程进入
    }
}

reader() {                   // 读者进程
    while(1) {
        P(w);                // 申请进入权限：若无写者等待，则通过
        P(mutex);            // 互斥访问 count
        if(count == 0)       // 若是第一个读者
            P(rw);           // 阻止写者访问文件
        count++;             // 读者数量加 1
        V(mutex);            // 释放对 count 的访问
        V(w);                // 立即释放 w，允许其他进程竞争
        读文件;
        P(mutex);            // 互斥访问 count
        count--;             // 读者数量减 1
        if(count == 0)       // 若是最后一个读者
            V(rw);           // 允许写者访问文件
        V(mutex);            // 释放对 count 的访问
    }
}

// 写者优先

#endif