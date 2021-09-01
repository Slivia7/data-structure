
#include <stdio.h>

#include <stdlib.h>

 

#define MAX_VERTEX_NUM 100  /* ͼ�����ڵ��� */

typedef char VertexType;

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

 

typedef struct

{

    AdjList adjlist;             /* ����ͼ�ṹ���ڽӱ� */

    int vexnum;                  /* �ڵ����Ŀ */

    int edgenum;                 /* �ߵ���Ŀ */

}ALGraph;                        /* adjacency list���ڽӱ� */

 

void CreateALG(ALGraph * ALG);   /* �ڽӱ�����ͼ */

void TraverseALG(ALGraph ALG);   /* ����ͼALG */

void DFSTraverseALG(ALGraph ALG);/* ������ȱ������ڽӱ�洢��ͼALG */

void DFSALG(ALGraph ALG, int i); /* ��ViΪ��������ڽӱ�洢��ͼALG��ʼDFS���� */

void LocateVex(ALGraph ALG, VertexType vertex, int * index);

                                 /* ��λ�ڵ�vertex���������±긳��index */

int visited[MAX_VERTEX_NUM];     /* ��־���� */

 

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

 

    printf("������ͼ�Ķ��㣺");

    while ((ch = getchar()) != '\n')/* ��������� */

    {

        ALG->adjlist[i].vex = ch;

        ALG->adjlist[i].firstedge = NULL;

        i++;

    }

    ALG->vexnum = i;/* ������ */

 

    for (i = 0; i < ALG->vexnum; i++)/* ͷ�巨����������ڽӱ߱� */

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


void DFSTraverseALG(ALGraph ALG)    /* ������ȱ������ڽӱ�洢��ͼALG */

{

    int i;

 

    for (i = 0; i < ALG.vexnum; i++)/* ��ʼ����־���� */

        visited[i] = 0;

 

    printf("ͼ��������ȱ������У�");

    for (i = 0; i < ALG.vexnum; i++)/* �ӵ�һ���ڵ㿪ʼDFS���� */

        if (!visited[i])

            DFSALG(ALG, i);

}

void DFSALG(ALGraph ALG, int i)/* ���±�Ϊi�Ľڵ�Ϊ�������ͼALG��ʼDFS���� */

{

    EdgeNode * temp;

    int index;

 

    printf("%c, ", ALG.adjlist[i].vex);

    visited[i] = 1;            /* ��ǽڵ�i�ѱ����� */

 

    temp = ALG.adjlist[i].firstedge;

    while (temp)

    {

    int k;

 

    for (k = 0; k < ALG.vexnum; k++)

    {

        if (ALG.adjlist[k].vex == temp->adjvex)

        {

            index = k;/* ���ڵ�vertex���±긳��index */

        }

    }

        if (!visited[index])   /* ����indexΪ�±�Ľڵ�δ������������������Ӹýڵ㿪ʼ������һ��DFS���� */

            DFSALG(ALG, index);

        temp = temp->next;     /* ����indexΪ�±�Ľڵ㱻��������Ѱ�ҽڵ����һ���ڽӵ� */

    }

}





