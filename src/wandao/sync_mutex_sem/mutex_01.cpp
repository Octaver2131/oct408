#if 0

/*
 * 单标志法
 *
 * 违背 “让权等待” 准则
 */

// 进程 P0
while (turn != 0);            // 进入区
critical section;             // 临界区
turn = 1;                     // 退出区
remainder section;            // 剩余区

// 进程 P1
while (turn != 1);            // 进入区
critical section;             // 临界区
turn = 0;                     // 退出区
remainder section;            // 剩余区

#endif
