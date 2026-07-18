#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

/*
 * 链的链式存储
 */

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkStack;