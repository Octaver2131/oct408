#if 0

/*
 * 树 - 双亲表示法
 */

#define MAX_TREE_SIZE 100

typedef struct {
    ElemType data;
    int parent;
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;

#define SIZE 100
int UFSets[SIZE];

// 并查集的初始化操作
void Initial(int S[]) {
    for(int i = 0; i < SIZE; i++)
        S[i] = -1;
}

// 并查集的 Find 操作
int Find(int S[], int x) {
    while (S[x] >= 0)
        x = S[x];
    return x;
}

// 并查集的 Union 操作
void Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    S[Root2] = Root1;
}

// 改进的 Find 操作
int Find(int S[], int x) {
    int root = x;
    while (S[root] >= 0)
        root=S[root];
    while (x != root) {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return root;
}

// 改进的 Union 操作
void Union(int S[], int Root1, int Root2) {
    if (Root1 == Root2) return;
    if (S[Root2] > S[Root1]) {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    } else {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

#endif

