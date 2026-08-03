#if 0

/*
 * 双标志后检查法
 *
 * 违背 “空闲让进”、“有限等待” 准则
 */

// 进程 P0
flag[0] = true;               // 进入区 - 1
while (flag[1]);              // 进入区 - 3
critical section;             // 临界区
flag[0] = false;              // 退出区
remainder section;            // 剩余区

// 进程 P1
flag[1] = true;               // 进入区 - 2
while (flag[0]);              // 进入区 - 4
critical section;             // 临界区
flag[1] = false;              // 退出区
remainder section;            // 剩余区

#endif
