/*****************************/
/*       图和函数定义        */
/*****************************/
#include "stdio.h"
#include "stdlib.h"
#define MaxVertexNum 50					//定义最大顶点数
typedef struct node{							//边表结点
int adjvex;								//邻接点域
struct node *next;						//链域
} EdgeNode;
typedef struct vnode{							//顶点表结点
char vertex;								//顶点域
EdgeNode *firstedge;					//边表头指针
} VertexNode;
typedef VertexNode AdjList[MaxVertexNum];	//AdjList是邻接表类型
typedef struct{
AdjList adjlist;							//邻接表
int n,e;									//图中当前顶点数和边数
} ALGraph;									//图类型
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum]; 	
		//定义数组保存访问的状态
		typedef struct              /* 循环顺序队列 */

{

    int data[MaxVertexNum];      /* 存储图中节点下标 */

    int front, rear;        /* front:指向队列中第一个元素

                               rear:指向队列中最后一个元素下一位置 */

}Queue;

void InitQueue(Queue * Q);            /* 建立一个空循环队列 */

void InQueue(Queue * Q, int index);   /* 入队 */

void OutQueue(Queue * Q, int * index);/* 出队 */

 

void CreatALGraph(ALGraph * ALG);        /* 邻接表法创建图 */


void BFS(ALGraph *ALG,int k);     /* 广度优先遍历以邻接表存储的图ALG */
/*****************************/
/*      建立邻接链表         */
/*****************************/
void CreatALGraph(ALGraph *G)
{
	int i, j, k;
	char a;
	EdgeNode *s;							//定义边表结点
	printf("Input VertexNum(n) and EdgesNum(e): ");
	scanf("%d,%d",&G->n,&G->e);			//读入顶点数和边数
	scanf("%c",&a);
	printf("Input Vertex string:");
	for(i=0;i<G->n;i++)						//建立边表
	{
		scanf("%c",&a);
		G->adjlist[i].vertex=a;				//读入顶点信息
		G->adjlist[i].firstedge=NULL;			//边表置为空表
	}
	printf("Input edges,Creat Adjacency List\n");
	for(k=0;k<G->e;k++) 
	{										//建立边表
		scanf("%d%d",&i,&j);				//读入边（Vi，Vj）的顶点对序号
		s=(EdgeNode *) malloc(sizeof(EdgeNode));	//生成边表结点
		s->adjvex=j;							//邻接点序号为j
		s->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=s;				//将新结点*S插入顶点Vi的边表头部
		s=(EdgeNode *)malloc(sizeof(EdgeNode)); 
		s->adjvex=i;							//邻接点序号为i
		s->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=s;				//将新结点*S插入顶点Vj的边表头部
	}
}


/*****************************/
/*          主函数           */
/*****************************/
int main()
{
	int i;
	ALGraph *G;
	G=(ALGraph *) malloc(sizeof(ALGraph));
	CreatALGraph(G);

	printf("Print Graph BFS: ");
	BFS(G, 3);
	printf("\n");
}

void BFS(ALGraph *G,int k)    /* 广度优先遍历以邻接表存储的图ALG */

{

    int i, index;
                    /* 从节点ch开始对图进行BFS搜索 */

    EdgeNode * temp;

    Queue Q;

 

    for (i = 0; i < G->n; i++)/* 初始化标志数组 */

        visited[i] = FALSE;

   
for (int m = 0; m < G->n; m++)

    {

        if (G->adjlist[m].vertex == k)

        {

            index = m;             /* 将节点vertex的下标赋给index */

        }

    }printf("节点 %c 定位失败！\n", k);
 

    printf("图的广度优先遍历序列：");

    InitQueue(&Q);                  /* 建立一个空循环队列 */

    if (!visited[index])

    {

        InQueue(&Q, index);         /* 开始节点入队，并修改visited数组 */

        visited[index] = TRUE;

        

        while (Q.rear != Q.front)   /* 当队列不空时 */

        {

            OutQueue(&Q, &index);   /* 队首元素出队并访问 */

            printf("%c, ", G->adjlist[index].vertex);

 

            temp = G->adjlist[index].firstedge;

            while (temp)            /* 将节点的所有邻接点入队 */

            {

   
    for (int m = 0; m < G->n; m++)

    {

        if (G->adjlist[m].vertex == temp->adjvex)

        {

            index = m;             /* 将节点vertex的下标赋给index */

        }

    }printf("节点 %c 定位失败！\n", temp->adjvex);
                if (!visited[index])/* 若节点未被遍历，则入队并修改visited数组 */

                {

                    InQueue(&Q, index);

                    visited[index] = TRUE;

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

    if ((Q->rear + 1) % MaxVertexNum == Q->front)

    {

        printf("队列满，入队失败！\n");

        return;

    }

    Q->data[Q->rear] = index;

    Q->rear = (Q->rear + 1) % MaxVertexNum;

}

void OutQueue(Queue * Q, int * index)/* 出队 */

{

    if (Q->rear == Q->front)

    {

        printf("队列空，出队失败！\n");

        return;

    }

    *index = Q->data[Q->front];

    Q->front = (Q->front + 1) % MaxVertexNum;

}

