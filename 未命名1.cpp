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
Boolean visited[MaxVertexNum]; 			//�������鱣����ʵ�״̬

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

/*�ڽӱ��������ȵݹ�*/


/*�ڽӱ��������ȵݹ�*/

void DFS(ALGraph *G,int i)

{
  EdgeNode * temp;

    int index;

 

    printf("%c, ", G->adjlist[i].vertex);

    visited[i] = TRUE;            /* ��ǽڵ�i�ѱ����� */

 

    temp = G->adjlist[i].firstedge;

    while (temp)

    {

    int k;

 

    for (k = 0; k < G->n; k++)

    {

        if (G->adjlist[k].vertex == temp->adjvex)

        {

            index = k;/* ���ڵ�vertex���±긳��index */

        }

    }

        if (!visited[index])   /* ����indexΪ�±�Ľڵ�δ������������������Ӹýڵ㿪ʼ������һ��DFS���� */

            DFS(G, index);

        temp = temp->next;     /* ����indexΪ�±�Ľڵ㱻��������Ѱ�ҽڵ����һ���ڽӵ� */

    }
 } 

 

 //�ڽӱ����ȱ�������

 

void DFSTraverse(ALGraph *G)

{

int i;

 

    for (i = 0; i < G->n; i++)/* ��ʼ����־���� */

        visited[i] = FALSE;

 

    printf("ͼ��������ȱ������У�");

    for (i = 0; i < G->n; i++)/* �ӵ�һ���ڵ㿪ʼDFS���� */

        if (!visited[i])

            DFS(G, i); 			

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
	printf("Print Graph DFS: ");
	DFSTraverse(G);
	printf("\n");
//	printf("Print Graph BFS: ");
//	BFS(G, 3);
//	printf("\n");
}

