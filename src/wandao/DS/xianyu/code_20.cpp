#if 0

/*
 * 图的邻接表存储
 */

#define MaxVertexNum 100

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    //InfoType info;
} ArcNode;


typedef struct VNode {
    ElemType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// 广度优先搜索
void BFS(ALGraph G, int i) {
    visit(i);
    visited[i] = TRUE;
    EnQueue(Q, i);

    while(!QueueEmpty(Q)) {
        DeQueue(Q, v);

        for (p = G.vertices[v].firstarc; p; p = p->nextarc) {
            w = p->adjvex;
            if(visited[w] == FALSE) {
                visit(w);
                visited[w] = TRUE;
                EnQueue(Q,w);
            }
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

// 拓扑排序
bool TopologicalSort(Graph G) {
    InitStack(S);
    int i;
    for (i = 0; i < G.vexnum; i++)
        if(indegree[i] == 0)
            Push(S, i);
    int count = 0;

    while(!StackEmpty(S)) {
        Pop(S, i);
        print[count++] = i;
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) {

            v = p->adjvex;
            if (!(--indegree[v]))
                Push(S, v);
        }
    }
    if(count < G.vexnum)
        return false;
    else
        return true;
}

#endif