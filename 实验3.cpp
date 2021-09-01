/*****************************/
/*       Í¼ï¿½Íºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½        */
/*****************************/
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100						//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ó¶¥µï¿½ï¿½ï¿½

typedef struct
{
    char vexs[MaxVertexNum];					//ï¿½ï¿½ï¿½ï¿½ï¿½
    int edges[MaxVertexNum][MaxVertexNum];	//ï¿½Ú½Ó¾ï¿½ï¿½ó£¬¿É¿ï¿½ï¿½ï¿½ï¿½ß±ï¿½
    int n, e;										//Í¼ï¿½ÐµÄ¶ï¿½ï¿½ï¿½ï¿½ï¿½nï¿½Í±ï¿½ï¿½ï¿½e
} MGraph;										//ï¿½ï¿½ï¿½Ú½Ó¾ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½Í¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

//¶ÓÁÐ
typedef struct
{
	int data[MaxVertexNum];
	int front, rear;
}Queue;
//Èë¶Ó
void EnQueue(Queue *Q,int e)
{
	if ((Q->rear + 1) %  MaxVertexNum== Q->front){
		printf("¶ÓÁÐÂú£¬Èë¶ÓÊ§°Ü£¡\n"); 
		return;
	} 
	else
	{
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxVertexNum;
	}
}

typedef enum {FALSE,TRUE} Boolean;
bool visited[MaxVertexNum];					//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½é±£ï¿½ï¿½ï¿½ï¿½Êµï¿½×´Ì¬

void CreatMGraph(MGraph *G);
void BFS(MGraph *G, int k);
void DFSM(MGraph *G, int i);
void DFS(MGraph *G);

/*****************************/
/*      ï¿½ï¿½ï¿½ï¿½ï¿½Ú½Ó¾ï¿½ï¿½ï¿½         */
/*****************************/
void CreatMGraph(MGraph *G)
{
    int i, j, k;
    char a;
    printf("Input VertexNum(n) and EdgesNum(e): (n,e)");
    scanf("%d,%d",&G->n,&G->e);			//ï¿½ï¿½ï¿½ë¶¥ï¿½ï¿½ï¿½ï¿½ï¿½Í±ï¿½ï¿½ï¿½
    // scanf("%c",&a);
    fflush(stdin);
    printf("Input Vertex string:");
    for(i=0; i<G->n; i++)
    {
        scanf("%c",&a);
        getchar();
        G->vexs[i]=a;						//ï¿½ï¿½ï¿½ë¶¥ï¿½ï¿½ï¿½ï¿½Ï¢ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    }
    for(i=0; i<G->n; i++)
        for(j=0; j<G->n; j++)
            G->edges[i][j]=0;				//ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½Ú½Ó¾ï¿½ï¿½ï¿½
    printf("Input edges,Creat Adjacency Matrix\n");
    for(k=0; k<G->e; k++)  					//ï¿½ï¿½ï¿½ï¿½eï¿½ï¿½ï¿½ß£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú½Ó¾ï¿½ï¿½ï¿½
    {
        scanf("%d%d",&i,&j);				//ï¿½ï¿½ï¿½ï¿½ß£ï¿½Viï¿½ï¿½Vjï¿½ï¿½ï¿½Ä¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
        G->edges[i][j]=1;
        G->edges[j][i]=1;					//ï¿½ï¿½Îªï¿½ï¿½ï¿½ï¿½Í¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Îªï¿½Ô³Æ¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¼ï¿½ï¿½È¥ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    }
}

/*****************************/
/*          ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½           */
/*****************************/
int main()
{
    int i;
    MGraph *G;
    G=(MGraph *) malloc(sizeof(MGraph));	//ÎªÍ¼Gï¿½ï¿½ï¿½ï¿½ï¿½Ú´ï¿½Õ¼ï¿½
    CreatMGraph(G);						//ï¿½ï¿½ï¿½ï¿½ï¿½Ú½Ó¾ï¿½ï¿½ï¿½
    printf("Print Graph DFS: ");
    DFS(G);									//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È±ï¿½ï¿½ï¿½
    printf("\n");
    printf("Print Graph BFS:(start with 3) ");
    BFS(G, 3);								//ï¿½ï¿½ï¿½ï¿½ï¿½Îª3ï¿½Ä¶ï¿½ï¿½ã¿ªÊ¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È±ï¿½ï¿½ï¿½
    printf("\n");
    return 0;
}
/***********************************/
/*        BFS£º¹ã¶ÈÓÅÏÈ±éÀú       */
/*      £¨ÒÔ½ÚµãkÎª³ö·¢µã£©       */
/***********************************/
void BFS(MGraph *G, int k)
{
	int i,j;
	Queue Q;
	for (i = 0; i < G->n; i++)
		visited[i] = FALSE;
	Q.front = Q.rear = 0;
	visited[k]=TRUE;
	EnQueue(&Q,k);
	while(Q.front!=Q.rear){
		j = Q.data[Q.front];
		Q.front = (Q.front + 1) % MaxVertexNum;
		printf("%c ",G->vexs[j]);
		for(i=0;i<G->n;i++){
			if((G->edges[i][j]==1) && (visited[i]==FALSE)){
				
				EnQueue(&Q,i);
				visited[i]=TRUE;
			}
		}
	} 
}
/***********************************/
/*        DFS£ºÉî¶ÈÓÅÏÈ±éÀú       */
/* £¨µÝ¹é²¿·Ö£ºÒÔ½ÚµãiÎª³ö·¢µã£©  */
/***********************************/
void DFSM(MGraph *G, int i)
{
    int j;
    printf("%c ",G->vexs[i]);
    visited[i]=true;
    for(j=0; j<G->n; j++)
    {
        if((G->edges[j][i]!=0)&&(!visited[j]))
            DFSM(G,j);  		//jï¿½ï¿½iï¿½ï¿½ï¿½Ú½Óµã£¬ï¿½ï¿½Î´ï¿½ï¿½ï¿½ï¿½
    }
}
/**************************************************/
/*              DFS£ºÉî¶ÈÓÅÏÈ±éÀú                */
/*   £¨³õÊ¼»¯²¿·Ö£º³õÊ¼»¯·ÃÎÊÊý×é£¬µ÷ÓÃDFSM£©   */
/**************************************************/
void DFS(MGraph *G)
{
    int i;
    for(i=0; i<G->n; i++)
        visited[i]=FALSE;
    DFSM(G,0);
}


