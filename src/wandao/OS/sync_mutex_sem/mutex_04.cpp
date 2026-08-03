#if 0

/*
 * Peterson 算法
 *
 * 违背 “让权等待” 准则
 */

// 进程 P0
flag[0] = true;                // 进入区
turn = 1;                      // 进入区
while (flag[1] && turn == 1);  // 进入区
critical section;              // 临界区
flag[0] = false;               // 退出区
remainder section;             // 剩余区

// 进程 P1
flag[1] = true;                // 进入区
turn = 0;                      // 进入区
while (flag[0] && turn == 0);  // 进入区
critical section;              // 临界区
flag[1] = false;               // 退出区
remainder section;             // 剩余区

#endif
