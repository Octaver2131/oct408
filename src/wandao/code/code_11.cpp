#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

/*
 * 串的定长顺序存储
 */

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

// 暴力匹配算法
int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i; ++j;
        } else {
            i = i - j + 2; j = 1;
        }
    }
    if (j > T.length) return i - T.length;
    else return 0;
}

// 计算 next 数组
void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            next[i] = j;
        } else
            j = next[j];
    }
}

// KMP 算法
int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i; ++j;
        } else
            j=next[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}

// 计算 nextval 数组
void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            if (T.ch[i] != T.ch[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}