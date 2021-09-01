
#include <stdio.h>

#include <stdlib.h>

 

#define MAX_VERTEX_NUM 100  /* 图中最大节点数 */

typedef char VertexType;    /* 定义节点名为char型 */

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

 

typedef struct              /* 描述图结构的邻接表 */

{

    AdjList adjlist;        

    int vexnum;             /* 节点的数目 */

    int edgenum;            /* 边的数目 */

}ALGraph;                   /* adjacency list：邻接表 */

 

#define MAXSIZE 100         /* 队列最大元素个数 */

typedef struct              /* 循环顺序队列 */

{

    int data[MAXSIZE];      /* 存储图中节点下标 */

    int front, rear;        /* front:指向队列中第一个元素

                               rear:指向队列中最后一个元素下一位置 */

}Queue;

void InitQueue(Queue * Q);            /* 建立一个空循环队列 */

void InQueue(Queue * Q, int index);   /* 入队 */

void OutQueue(Queue * Q, int * index);/* 出队 */

 

void CreateALG(ALGraph * ALG);        /* 邻接表法创建图 */

void TraverseALG(ALGraph ALG);        /* 遍历图ALG */

void BFSTraverseALG(ALGraph ALG);     /* 广度优先遍历以邻接表存储的图ALG */



                                      /* 定位节点vertex，并将其下标赋给index */

int visited[MAX_VERTEX_NUM];          /* 标志数组 */

 

int main(void)

{

    ALGraph g;

 

    CreateALG(&g);

    printf("------------------------------\n");

    BFSTraverseALG(g);

 

    return 0;

}

void CreateALG(ALGraph * ALG)

{

    VertexType ch;

    int i = 0, count = 0;

    EdgeNode * temp;

 

    printf("请输入图的顶点：");

    while ((ch = getchar()) != '\n')    /* 建立顶点表 */

    {

        ALG->adjlist[i].vex = ch;

        ALG->adjlist[i].firstedge = NULL;

        i++;

    }

    ALG->vexnum = i;                    /* 顶点数 */

 

    for (i = 0; i < ALG->vexnum; i++)   /* 头插法建立顶点的邻接边表 */

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

void TraverseALG(ALGraph ALG)

{

    int i;

    EdgeNode * index;

 

    if (ALG.vexnum == 0)            /* 若图为空，则停止遍历 */

    {

        printf("图为空\n");

        return;

    }

 

    for (i = 0; i < ALG.vexnum; i++)/* 遍历图 */

    {

        printf("顶点 %c ：", ALG.adjlist[i].vex);

        index = ALG.adjlist[i].firstedge;

        while (index)               /* 以邻接表形式输出图的信息 */

        {

            printf("[ %c ] -> ", index->adjvex);

            index = index->next;

        }

        printf("NULL\n");

    }

}

void BFSTraverseALG(ALGraph ALG)    /* 广度优先遍历以邻接表存储的图ALG */

{

    int i, index;

    char ch;                        /* 从节点ch开始对图进行BFS搜索 */

    EdgeNode * temp;

    Queue Q;

 

    for (i = 0; i < ALG.vexnum; i++)/* 初始化标志数组 */

        visited[i] = 0;

 

    printf("请输入开始节点：");

    scanf("%c", &ch);

    
       int m;

 

    for (m = 0; m < ALG.vexnum; m++)

    {

        if (ALG.adjlist[i].vex == ch)

        {

            index = m;             /* 将节点vertex的下标赋给index */

        }

    }
 

    printf("图的广度优先遍历序列：");

    InitQueue(&Q);                  /* 建立一个空循环队列 */

    if (!visited[index])

    {

        InQueue(&Q, index);         /* 开始节点入队，并修改visited数组 */

        visited[index] = 1;

        

        while (Q.rear != Q.front)   /* 当队列不空时 */

        {

            OutQueue(&Q, &index);   /* 队首元素出队并访问 */

            printf("%c, ", ALG.adjlist[index].vex);

 

            temp = ALG.adjlist[index].firstedge;

            while (temp)            /* 将节点的所有邻接点入队 */

            {

            
    int m;

 

    for (m = 0; m < ALG.vexnum; m++)

    {

        if (ALG.adjlist[i].vex == temp->adjvex)

        {

            index = m;             /* 将节点vertex的下标赋给index */

        }

    }

                if (!visited[index])/* 若节点未被遍历，则入队并修改visited数组 */

                {

                    InQueue(&Q, index);

                    visited[index] = 1;

                }

                temp = temp->next;                

            }

        }

    }

}




void InitQueue(Queue * Q)           /* 建立一个空队列 */

{

    Q = (Queue *)malloc(sizeof(Queue));

    Q->front = Q->rear = 0;

}

void InQueue(Queue * Q, int index)  /* 入队 */

{

    if ((Q->rear + 1) % MAXSIZE == Q->front)

    {

        printf("队列满，入队失败！\n");

        return;

    }

    Q->data[Q->rear] = index;

    Q->rear = (Q->rear + 1) % MAXSIZE;

}

void OutQueue(Queue * Q, int * index)/* 出队 */

{

    if (Q->rear == Q->front)

    {

        printf("队列空，出队失败！\n");

        return;

    }

    *index = Q->data[Q->front];

    Q->front = (Q->front + 1) % MAXSIZE;

}


