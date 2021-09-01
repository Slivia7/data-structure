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
Boolean visited[MaxVertexNum]; 			//定义数组保存访问的状态

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

/*邻接表的深度优先递归*/


/*邻接表的深度优先递归*/

void DFS(ALGraph *G,int i)

{
  EdgeNode * temp;

    int index;

 

    printf("%c, ", G->adjlist[i].vertex);

    visited[i] = TRUE;            /* 标记节点i已被访问 */

 

    temp = G->adjlist[i].firstedge;

    while (temp)

    {

    int k;

 

    for (k = 0; k < G->n; k++)

    {

        if (G->adjlist[k].vertex == temp->adjvex)

        {

            index = k;/* 将节点vertex的下标赋给index */

        }

    }

        if (!visited[index])   /* 若以index为下标的节点未被遍历，则遍历。并从该节点开始进行下一轮DFS搜索 */

            DFS(G, index);

        temp = temp->next;     /* 若以index为下标的节点被遍历，则寻找节点的下一个邻接点 */

    }
 } 

 

 //邻接表的深度遍历操作

 

void DFSTraverse(ALGraph *G)

{

int i;

 

    for (i = 0; i < G->n; i++)/* 初始化标志数组 */

        visited[i] = FALSE;

 

    printf("图的深度优先遍历序列：");

    for (i = 0; i < G->n; i++)/* 从第一个节点开始DFS搜索 */

        if (!visited[i])

            DFS(G, i); 			

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
	printf("Print Graph DFS: ");
	DFSTraverse(G);
	printf("\n");
//	printf("Print Graph BFS: ");
//	BFS(G, 3);
//	printf("\n");
}

