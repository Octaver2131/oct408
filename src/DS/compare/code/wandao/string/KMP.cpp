#define MAXLEN 255                //预定义最大串长为255
typedef struct {
    char ch[MAXLEN];              //每个分量存储一个字符
    int length;                   //串的实际长度
} SString;

void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            next[i] = j;              //若p_i=p_j，则next[j+1]=next[j]+1
        } else
            j = next[j];             //否则令j=next[j]，循环继续
    }
}

void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            if (T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}

int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i; ++j;                 //继续比较后继字符
        } else
            j = next[j];              //模式串向右滑动
    }
    if (j > T.length)
        return i - T.length;          //匹配成功
    else
        return 0;
}