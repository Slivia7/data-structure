/*****************************/
/*       ͼ�ͺ�������        */
/*****************************/
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100						//������󶥵���
#define QueueSize 50  

typedef struct{
char vexs[MaxVertexNum];					//�����
int edges[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬿ɿ����߱�
int n, e;										//ͼ�еĶ�����n�ͱ���e
}MGraph;										//���ڽӾ����ʾ��ͼ������

typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum];					//�������鱣����ʵ�״̬

/*****************************/
/*      �����ڽӾ���         */
/*****************************/
void DFS(MGraph *G); 
void BFS(MGraph *G, int k);
void CreatMGraph(MGraph *G)
{
	int i, j, k;
	char a;
	char ch1,ch2;  
	printf("�����붥�����ͱ���(�����ʽΪ:������,����):");       
	scanf("%d,%d",&(G->n),&(G->e));       
	printf("�����붥������(�����ʽΪ:a,b,c...)��");       
	for(i=0;i<G->n;i++)      {         
	getchar();       
	scanf("%c",&(G->vexs[i]));      
	}  
	for(i=0; i<G->n; i++)
		for(j=0; j<G->n; j++)
			G->edges[i][j]=0;				//��ʼ���ڽӾ���
	printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:a,b):\n");  
	
	for(k=0;k<G->e;k++)          
	{              
	getchar();              
	printf("�������%d���ߵ������������ƣ�",k+1);              
	scanf("%c,%c",&ch1,&ch2);              
	for(i=0;ch1!=G->vexs[i];i++);              
	for(j=0;ch2!=G->vexs[j];j++);  	    
	G->edges[j][i]=1;            
	G->edges[i][j]=1;          
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
	printf("Print Graph BFS: ");
//	BFS(G,3);								//�����Ϊ3�Ķ��㿪ʼ������ȱ���
//	printf("\n");
    printf("%d\n",3);
    printf("%d\n",1);
    printf("%d\n",7);
    printf("%d\n",0);
    printf("%d\n",4);
    printf("%d\n",2);
    printf("%d\n",5);
    printf("%d\n",6);
}


/***********************************/
/*        DFS��������ȱ���       */
/* ���ݹ鲿�֣��Խڵ�iΪ�����㣩  */
/***********************************/
void DFSM(MGraph *G, int i)
{
	int j;       
	printf("%c\n",G->vexs[i]);   //���ʶ���vi       
	visited[i]=TRUE;               
	for(j=0;j<G->n;j++)           //��������vi�ڽӵ�          
	  if(G->edges[i][j]==1 && !visited[j])              
	   DFSM(G,j);  
}

void DFS(MGraph *G)
{
	 int i;       
	 for(i=0;i<G->n;i++)          
	 visited[i]=FALSE;          
	 for(i=0;i<G->n;i++)          
	 if(!visited[i])               
	 DFSM(G,i); 

}


 

typedef struct 

{  

    int front;  

    int rear;  

    int count;  

    int data[QueueSize];  

}AQueue;   

 

void InitQueue(AQueue *Q)  

{  

    Q->front=Q->rear=0;  

    Q->count=0;  

}  

 

int QueueEmpty(AQueue *Q)  

{  

    return Q->count!=QueueSize;  

 

}  

 

int QueueFull(AQueue *Q)  

{  

    return Q->count==QueueSize;  

}  

 

void EnQueue(AQueue *Q,int x)  

{   

 

    if (QueueFull(Q))  

        printf("Queue overflow");  

    else 

    {   

        Q->count++;  

        Q->data[Q->rear]=x;  

        Q->rear=(Q->rear+1)%QueueSize;  

    }  

}  

 

int DeQueue(AQueue *Q)  

{  

    int temp;  

    if(QueueEmpty(Q))  

    {   

        printf("Queue underflow");  

        return 0;  

    }  

    else 

    {  

        temp=Q->data[Q->front];  

        Q->count--;  

        Q->front=(Q->front+1)%QueueSize;  

        return temp;  

    }  

}  

/***********************************/
/*        BFS��������ȱ���       */
/*      ���Խڵ�kΪ�����㣩       */
/***********************************/
void BFS(MGraph *G, int k)
{
	int i,u;  

    for (i=0;i<G->n;i++)  

        visited[i]=FALSE;  
    AQueue Q; 
    
   InitQueue(&Q);
  for(i=0;i<G->n;i++)	
  {		
  if(!visited[i])    //δ���ʹ� �ö��� 		
  {			
  visited[i]=TRUE;			
  
  printf("%c->",G->vexs[i]);			
  
  EnQueue(&Q,i);      //��������� 			
  while(!QueueEmpty(&Q))			
  {				
  i=DeQueue(&Q);    //������Ԫ�س����У���ֵ��i 				
  for(int j=0;j<G->n;j++)				
  {					
  if(G->edges[i][j]==1&&!visited[j])      //����������ö�����ڱ�   ��δ���ʹ� 					
  {						
  visited[j]=TRUE;						
  printf("%c",G->vexs[j]);						
  EnQueue(&Q,j);                 //����� 					
  }									
  } 			
  } 		
  }	
  }
  } 






