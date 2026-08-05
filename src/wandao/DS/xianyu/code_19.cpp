#if 0

/*
 * 图的邻接矩阵存储
 */

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

// 广度优先搜索
void BFS(MGraph G, int i) {
    visit(i);
    visited[i] = TRUE;
    EnQueue(Q, i);

    while(!QueueEmpty(Q)) {
        DeQueue(Q, v);

        for(w = 0; w <G .vexnum; w++)
            if(visited[w] == FALSE && G.edge[v][w] == 1) {
                visit(w);
                visited[w] = TRUE;
                EnQueue(Q, w);
            }
    }
}

// 深度度优先搜索
void DFS(ALGraph G, int i) {
    visit(i);
    visited[i] = TRUE;

    for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
        j = p->adjvex;
        if (visited[j] == FALSE)
            DFS(G, j);
    }
}

#endif