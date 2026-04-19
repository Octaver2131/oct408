#define MaxSize 50
typedef int ElemType;

typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} LiStack;