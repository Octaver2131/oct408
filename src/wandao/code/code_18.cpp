#if 0

/*
 * 深度度优先搜索
 */

bool visited[MAX_VERTEX_NUM];

// 深度度优先搜索 - 递归
void DFSTraverse(Graph G) {
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = FALSE;
    for (i = 0; i < G.vexnum; i++)
        if(!visited[i])
            DFS(G, i);
}

#endif