
#include <stdio.h>

#include <stdlib.h>

 

#define MAX_VERTEX_NUM 100  /* 图中最大节点数 */

typedef char VertexType;

typedef struct node         /* 边表节点 */

{

    VertexType adjvex;      /* 与顶点相连的邻接点下标(adjoin：邻接) */

    struct node * next;     /* 指向顶点的下一个邻接点 */

}EdgeNode;

 

typedef struct vnode        /* 顶点结构 */

{

    VertexType vex;         /* 存储顶点名 */

    EdgeNode * firstedge;   /* 边表头指针，指向顶点第一个邻接点 */

}VertexNode, AdjList[MAX_VERTEX_NUM];

 

typedef struct

{

    AdjList adjlist;             /* 描述图结构的邻接表 */

    int vexnum;                  /* 节点的数目 */

    int edgenum;                 /* 边的数目 */

}ALGraph;                        /* adjacency list：邻接表 */

 

void CreateALG(ALGraph * ALG);   /* 邻接表法创建图 */

void TraverseALG(ALGraph ALG);   /* 遍历图ALG */

void DFSTraverseALG(ALGraph ALG);/* 深度优先遍历以邻接表存储的图ALG */

void DFSALG(ALGraph ALG, int i); /* 以Vi为出发点对邻接表存储的图ALG开始DFS搜索 */

void LocateVex(ALGraph ALG, VertexType vertex, int * index);

                                 /* 定位节点vertex，并将其下标赋给index */

int visited[MAX_VERTEX_NUM];     /* 标志数组 */

 

int main(void)

{

    ALGraph g;

 

    CreateALG(&g);

 

    printf("------------------------------\n");

    DFSTraverseALG(g);

 

    return 0;

}

void CreateALG(ALGraph * ALG)

{

    VertexType ch;

    int i = 0, count = 0;

    EdgeNode * temp;

 

    printf("请输入图的顶点：");

    while ((ch = getchar()) != '\n')/* 建立顶点表 */

    {

        ALG->adjlist[i].vex = ch;

        ALG->adjlist[i].firstedge = NULL;

        i++;

    }

    ALG->vexnum = i;/* 顶点数 */

 

    for (i = 0; i < ALG->vexnum; i++)/* 头插法建立顶点的邻接边表 */

    {

        printf("请输入顶点 %c 的邻接顶点：", ALG->adjlist[i].vex);

        while ((ch = getchar()) != '\n')/* 按下回车结束邻接点的创建 */

        {

            temp = (EdgeNode *)malloc(sizeof(EdgeNode));

            temp->adjvex = ch;

            temp->next = ALG->adjlist[i].firstedge;

            ALG->adjlist[i].firstedge = temp;

            count++;

        }

    }

    ALG->edgenum = count / 2;

    // 无向图中每条边连接两个顶点，故：节点总度数 = 边数 * 2

}


void DFSTraverseALG(ALGraph ALG)    /* 深度优先遍历以邻接表存储的图ALG */

{

    int i;

 

    for (i = 0; i < ALG.vexnum; i++)/* 初始化标志数组 */

        visited[i] = 0;

 

    printf("图的深度优先遍历序列：");

    for (i = 0; i < ALG.vexnum; i++)/* 从第一个节点开始DFS搜索 */

        if (!visited[i])

            DFSALG(ALG, i);

}

void DFSALG(ALGraph ALG, int i)/* 以下标为i的节点为出发点对图ALG开始DFS搜索 */

{

    EdgeNode * temp;

    int index;

 

    printf("%c, ", ALG.adjlist[i].vex);

    visited[i] = 1;            /* 标记节点i已被访问 */

 

    temp = ALG.adjlist[i].firstedge;

    while (temp)

    {

    int k;

 

    for (k = 0; k < ALG.vexnum; k++)

    {

        if (ALG.adjlist[k].vex == temp->adjvex)

        {

            index = k;/* 将节点vertex的下标赋给index */

        }

    }

        if (!visited[index])   /* 若以index为下标的节点未被遍历，则遍历。并从该节点开始进行下一轮DFS搜索 */

            DFSALG(ALG, index);

        temp = temp->next;     /* 若以index为下标的节点被遍历，则寻找节点的下一个邻接点 */

    }

}





