#define MAXLEN 255                //预定义最大串长为255
typedef struct {
    char ch[MAXLEN];              //每个分量存储一个字符
    int length;                   //串的实际长度
} SString;