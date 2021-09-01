/*****************************/
/*       ͼ�ͺ�������        */
/*****************************/
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100						//������󶥵���

typedef struct
{
    char vexs[MaxVertexNum];					//�����
    int edges[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬿ɿ����߱�
    int n, e;										//ͼ�еĶ�����n�ͱ���e
} MGraph;										//���ڽӾ����ʾ��ͼ������

//����
typedef struct
{
	int data[MaxVertexNum];
	int front, rear;
}Queue;
//���
void EnQueue(Queue *Q,int e)
{
	if ((Q->rear + 1) %  MaxVertexNum== Q->front){
		printf("�����������ʧ�ܣ�\n"); 
		return;
	} 
	else
	{
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MaxVertexNum;
	}
}

typedef enum {FALSE,TRUE} Boolean;
bool visited[MaxVertexNum];					//�������鱣����ʵ�״̬

void CreatMGraph(MGraph *G);
void BFS(MGraph *G, int k);
void DFSM(MGraph *G, int i);
void DFS(MGraph *G);

/*****************************/
/*      �����ڽӾ���         */
/*****************************/
void CreatMGraph(MGraph *G)
{
    int i, j, k;
    char a;
    printf("Input VertexNum(n) and EdgesNum(e): (n,e)");
    scanf("%d,%d",&G->n,&G->e);			//���붥�����ͱ���
    // scanf("%c",&a);
    fflush(stdin);
    printf("Input Vertex string:");
    for(i=0; i<G->n; i++)
    {
        scanf("%c",&a);
        getchar();
        G->vexs[i]=a;						//���붥����Ϣ�����������
    }
    for(i=0; i<G->n; i++)
        for(j=0; j<G->n; j++)
            G->edges[i][j]=0;				//��ʼ���ڽӾ���
    printf("Input edges,Creat Adjacency Matrix\n");
    for(k=0; k<G->e; k++)  					//����e���ߣ������ڽӾ���
    {
        scanf("%d%d",&i,&j);				//����ߣ�Vi��Vj���Ķ������
        G->edges[i][j]=1;
        G->edges[j][i]=1;					//��Ϊ����ͼ������Ϊ�Գƾ�������������ͼ��ȥ���������
    }
}

/*****************************/
/*          ������           */
/*****************************/
int main()
{
    int i;
    MGraph *G;
    G=(MGraph *) malloc(sizeof(MGraph));	//ΪͼG�����ڴ�ռ�
    CreatMGraph(G);						//�����ڽӾ���
    printf("Print Graph DFS: ");
    DFS(G);									//������ȱ���
    printf("\n");
    printf("Print Graph BFS:(start with 3) ");
    BFS(G, 3);								//�����Ϊ3�Ķ��㿪ʼ������ȱ���
    printf("\n");
    return 0;
}
/***********************************/
/*        BFS��������ȱ���       */
/*      ���Խڵ�kΪ�����㣩       */
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
/*        DFS��������ȱ���       */
/* ���ݹ鲿�֣��Խڵ�iΪ�����㣩  */
/***********************************/
void DFSM(MGraph *G, int i)
{
    int j;
    printf("%c ",G->vexs[i]);
    visited[i]=true;
    for(j=0; j<G->n; j++)
    {
        if((G->edges[j][i]!=0)&&(!visited[j]))
            DFSM(G,j);  		//j��i���ڽӵ㣬��δ����
    }
}
/**************************************************/
/*              DFS��������ȱ���                */
/*   ����ʼ�����֣���ʼ���������飬����DFSM��   */
/**************************************************/
void DFS(MGraph *G)
{
    int i;
    for(i=0; i<G->n; i++)
        visited[i]=FALSE;
    DFSM(G,0);
}


