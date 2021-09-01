
#include <stdio.h>

#include <stdlib.h>

 

#define MAX_VERTEX_NUM 100  /* ͼ�����ڵ��� */

typedef char VertexType;    /* ����ڵ���Ϊchar�� */

typedef struct node         /* �߱�ڵ� */

{

    VertexType adjvex;      /* �붥���������ڽӵ��±�(adjoin���ڽ�) */

    struct node * next;     /* ָ�򶥵����һ���ڽӵ� */

}EdgeNode;

 

typedef struct vnode        /* ����ṹ */

{

    VertexType vex;         /* �洢������ */

    EdgeNode * firstedge;   /* �߱�ͷָ�룬ָ�򶥵��һ���ڽӵ� */

}VertexNode, AdjList[MAX_VERTEX_NUM];

 

typedef struct              /* ����ͼ�ṹ���ڽӱ� */

{

    AdjList adjlist;        

    int vexnum;             /* �ڵ����Ŀ */

    int edgenum;            /* �ߵ���Ŀ */

}ALGraph;                   /* adjacency list���ڽӱ� */

 

#define MAXSIZE 100         /* �������Ԫ�ظ��� */

typedef struct              /* ѭ��˳����� */

{

    int data[MAXSIZE];      /* �洢ͼ�нڵ��±� */

    int front, rear;        /* front:ָ������е�һ��Ԫ��

                               rear:ָ����������һ��Ԫ����һλ�� */

}Queue;

void InitQueue(Queue * Q);            /* ����һ����ѭ������ */

void InQueue(Queue * Q, int index);   /* ��� */

void OutQueue(Queue * Q, int * index);/* ���� */

 

void CreateALG(ALGraph * ALG);        /* �ڽӱ�����ͼ */

void TraverseALG(ALGraph ALG);        /* ����ͼALG */

void BFSTraverseALG(ALGraph ALG);     /* ������ȱ������ڽӱ�洢��ͼALG */



                                      /* ��λ�ڵ�vertex���������±긳��index */

int visited[MAX_VERTEX_NUM];          /* ��־���� */

 

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

 

    printf("������ͼ�Ķ��㣺");

    while ((ch = getchar()) != '\n')    /* ��������� */

    {

        ALG->adjlist[i].vex = ch;

        ALG->adjlist[i].firstedge = NULL;

        i++;

    }

    ALG->vexnum = i;                    /* ������ */

 

    for (i = 0; i < ALG->vexnum; i++)   /* ͷ�巨����������ڽӱ߱� */

    {

        printf("�����붥�� %c ���ڽӶ��㣺", ALG->adjlist[i].vex);

        while ((ch = getchar()) != '\n')/* ���»س������ڽӵ�Ĵ��� */

        {

            temp = (EdgeNode *)malloc(sizeof(EdgeNode));

            temp->adjvex = ch;

            temp->next = ALG->adjlist[i].firstedge;

            ALG->adjlist[i].firstedge = temp;

            count++;

        }

    }

    ALG->edgenum = count / 2;

    // ����ͼ��ÿ���������������㣬�ʣ��ڵ��ܶ��� = ���� * 2

}

void TraverseALG(ALGraph ALG)

{

    int i;

    EdgeNode * index;

 

    if (ALG.vexnum == 0)            /* ��ͼΪ�գ���ֹͣ���� */

    {

        printf("ͼΪ��\n");

        return;

    }

 

    for (i = 0; i < ALG.vexnum; i++)/* ����ͼ */

    {

        printf("���� %c ��", ALG.adjlist[i].vex);

        index = ALG.adjlist[i].firstedge;

        while (index)               /* ���ڽӱ���ʽ���ͼ����Ϣ */

        {

            printf("[ %c ] -> ", index->adjvex);

            index = index->next;

        }

        printf("NULL\n");

    }

}

void BFSTraverseALG(ALGraph ALG)    /* ������ȱ������ڽӱ�洢��ͼALG */

{

    int i, index;

    char ch;                        /* �ӽڵ�ch��ʼ��ͼ����BFS���� */

    EdgeNode * temp;

    Queue Q;

 

    for (i = 0; i < ALG.vexnum; i++)/* ��ʼ����־���� */

        visited[i] = 0;

 

    printf("�����뿪ʼ�ڵ㣺");

    scanf("%c", &ch);

    
       int m;

 

    for (m = 0; m < ALG.vexnum; m++)

    {

        if (ALG.adjlist[i].vex == ch)

        {

            index = m;             /* ���ڵ�vertex���±긳��index */

        }

    }
 

    printf("ͼ�Ĺ�����ȱ������У�");

    InitQueue(&Q);                  /* ����һ����ѭ������ */

    if (!visited[index])

    {

        InQueue(&Q, index);         /* ��ʼ�ڵ���ӣ����޸�visited���� */

        visited[index] = 1;

        

        while (Q.rear != Q.front)   /* �����в���ʱ */

        {

            OutQueue(&Q, &index);   /* ����Ԫ�س��Ӳ����� */

            printf("%c, ", ALG.adjlist[index].vex);

 

            temp = ALG.adjlist[index].firstedge;

            while (temp)            /* ���ڵ�������ڽӵ���� */

            {

            
    int m;

 

    for (m = 0; m < ALG.vexnum; m++)

    {

        if (ALG.adjlist[i].vex == temp->adjvex)

        {

            index = m;             /* ���ڵ�vertex���±긳��index */

        }

    }

                if (!visited[index])/* ���ڵ�δ������������Ӳ��޸�visited���� */

                {

                    InQueue(&Q, index);

                    visited[index] = 1;

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

    if ((Q->rear + 1) % MAXSIZE == Q->front)

    {

        printf("�����������ʧ�ܣ�\n");

        return;

    }

    Q->data[Q->rear] = index;

    Q->rear = (Q->rear + 1) % MAXSIZE;

}

void OutQueue(Queue * Q, int * index)/* ���� */

{

    if (Q->rear == Q->front)

    {

        printf("���пգ�����ʧ�ܣ�\n");

        return;

    }

    *index = Q->data[Q->front];

    Q->front = (Q->front + 1) % MAXSIZE;

}


