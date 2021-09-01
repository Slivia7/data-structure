/*****************************/
/*       ͼ�ͺ�������        */
/*****************************/
#include "stdio.h"
#include "stdlib.h"
#define MaxVertexNum 50					//������󶥵���
typedef struct node{							//�߱���
int adjvex;								//�ڽӵ���
struct node *next;						//����
} EdgeNode;
typedef struct vnode{							//�������
char vertex;								//������
EdgeNode *firstedge;					//�߱�ͷָ��
} VertexNode;
typedef VertexNode AdjList[MaxVertexNum];	//AdjList���ڽӱ�����
typedef struct{
AdjList adjlist;							//�ڽӱ�
int n,e;									//ͼ�е�ǰ�������ͱ���
} ALGraph;									//ͼ����
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum]; 	
		//�������鱣����ʵ�״̬
		typedef struct              /* ѭ��˳����� */

{

    int data[MaxVertexNum];      /* �洢ͼ�нڵ��±� */

    int front, rear;        /* front:ָ������е�һ��Ԫ��

                               rear:ָ����������һ��Ԫ����һλ�� */

}Queue;

void InitQueue(Queue * Q);            /* ����һ����ѭ������ */

void InQueue(Queue * Q, int index);   /* ��� */

void OutQueue(Queue * Q, int * index);/* ���� */

 

void CreatALGraph(ALGraph * ALG);        /* �ڽӱ�����ͼ */


void BFS(ALGraph *ALG,int k);     /* ������ȱ������ڽӱ�洢��ͼALG */
/*****************************/
/*      �����ڽ�����         */
/*****************************/
void CreatALGraph(ALGraph *G)
{
	int i, j, k;
	char a;
	EdgeNode *s;							//����߱���
	printf("Input VertexNum(n) and EdgesNum(e): ");
	scanf("%d,%d",&G->n,&G->e);			//���붥�����ͱ���
	scanf("%c",&a);
	printf("Input Vertex string:");
	for(i=0;i<G->n;i++)						//�����߱�
	{
		scanf("%c",&a);
		G->adjlist[i].vertex=a;				//���붥����Ϣ
		G->adjlist[i].firstedge=NULL;			//�߱���Ϊ�ձ�
	}
	printf("Input edges,Creat Adjacency List\n");
	for(k=0;k<G->e;k++) 
	{										//�����߱�
		scanf("%d%d",&i,&j);				//����ߣ�Vi��Vj���Ķ�������
		s=(EdgeNode *) malloc(sizeof(EdgeNode));	//���ɱ߱���
		s->adjvex=j;							//�ڽӵ����Ϊj
		s->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=s;				//���½��*S���붥��Vi�ı߱�ͷ��
		s=(EdgeNode *)malloc(sizeof(EdgeNode)); 
		s->adjvex=i;							//�ڽӵ����Ϊi
		s->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=s;				//���½��*S���붥��Vj�ı߱�ͷ��
	}
}


/*****************************/
/*          ������           */
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

void BFS(ALGraph *G,int k)    /* ������ȱ������ڽӱ�洢��ͼALG */

{

    int i, index;
                    /* �ӽڵ�ch��ʼ��ͼ����BFS���� */

    EdgeNode * temp;

    Queue Q;

 

    for (i = 0; i < G->n; i++)/* ��ʼ����־���� */

        visited[i] = FALSE;

   
for (int m = 0; m < G->n; m++)

    {

        if (G->adjlist[m].vertex == k)

        {

            index = m;             /* ���ڵ�vertex���±긳��index */

        }

    }printf("�ڵ� %c ��λʧ�ܣ�\n", k);
 

    printf("ͼ�Ĺ�����ȱ������У�");

    InitQueue(&Q);                  /* ����һ����ѭ������ */

    if (!visited[index])

    {

        InQueue(&Q, index);         /* ��ʼ�ڵ���ӣ����޸�visited���� */

        visited[index] = TRUE;

        

        while (Q.rear != Q.front)   /* �����в���ʱ */

        {

            OutQueue(&Q, &index);   /* ����Ԫ�س��Ӳ����� */

            printf("%c, ", G->adjlist[index].vertex);

 

            temp = G->adjlist[index].firstedge;

            while (temp)            /* ���ڵ�������ڽӵ���� */

            {

   
    for (int m = 0; m < G->n; m++)

    {

        if (G->adjlist[m].vertex == temp->adjvex)

        {

            index = m;             /* ���ڵ�vertex���±긳��index */

        }

    }printf("�ڵ� %c ��λʧ�ܣ�\n", temp->adjvex);
                if (!visited[index])/* ���ڵ�δ������������Ӳ��޸�visited���� */

                {

                    InQueue(&Q, index);

                    visited[index] = TRUE;

                }

                temp = temp->next;                

            }

        }

    }

}



void InitQueue(Queue * Q)           /* ����һ���ն��� */

{

    Q = (Queue *)malloc(sizeof(Queue));

    Q->front = Q->rear = 0;

}

void InQueue(Queue * Q, int index)  /* ��� */

{

    if ((Q->rear + 1) % MaxVertexNum == Q->front)

    {

        printf("�����������ʧ�ܣ�\n");

        return;

    }

    Q->data[Q->rear] = index;

    Q->rear = (Q->rear + 1) % MaxVertexNum;

}

void OutQueue(Queue * Q, int * index)/* ���� */

{

    if (Q->rear == Q->front)

    {

        printf("���пգ�����ʧ�ܣ�\n");

        return;

    }

    *index = Q->data[Q->front];

    Q->front = (Q->front + 1) % MaxVertexNum;

}

