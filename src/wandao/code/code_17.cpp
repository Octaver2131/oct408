#if 0

/*
 * 广度优先搜索
 */

bool visited[MAX_VERTEX_NUM];

// 广度优先搜索
void BFSTraverse(Graph G) {
    int i;
    for (i = 0; i < G.vexnum; ++i)
        visited[i] = FALSE;

    InitQueue(Q);
    for (i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS(G, i);
}

// 非带权图的单源最短路径
void BFS_MIN_Distance(Graph G, int u) {
    int i, w;
    for (i = 0; i < G.vexnum; ++i)
        d[i] = INF;
    visited[u] = TRUE; d[u] = 0;
    EnQueue(Q, u);
    while(!QueueEmpty(Q)) {
        DeQueue(Q, u);
        for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
            if(!visited[w]) {
                visited[w] = TRUE;
                d[w] = d[u] + 1;
                EnQueue(Q, w);
            }
    }
}

#endif