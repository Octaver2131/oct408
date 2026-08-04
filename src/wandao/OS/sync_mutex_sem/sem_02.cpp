#if 0

/*
 * 记录形信号量
 */

typedef struct {
    int value;
    struct process *L;
} semaphore;

void wait(semaphore S) {       // 相当于申请资源 - P 操作
    S.value--;
    if (S.value < 0) {
        add this process to S.L;
        block(S.L);
    }
}

void signal(semaphore S) {     // 相当于释放资源 - V 操作
    S.value++;
    if (S.value <= 0) {
        remove a process P from S.L;
        wakeup(P);
    }
}

#endif