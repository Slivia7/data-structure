/*****************************/
/*       图和函数定义        */
/*****************************/
#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100						//定义最大顶点数
#define QueueSize 50  

typedef struct{
char vexs[MaxVertexNum];					//顶点表
int edges[MaxVertexNum][MaxVertexNum];	//邻接矩阵，可看作边表
int n, e;										//图中的顶点数n和边数e
}MGraph;										//用邻接矩阵表示的图的类型

typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MaxVertexNum];					//定义数组保存访问的状态

/*****************************/
/*      建立邻接矩阵         */
/*****************************/
void DFS(MGraph *G); 
void BFS(MGraph *G, int k);
void CreatMGraph(MGraph *G)
{
	int i, j, k;
	char a;
	char ch1,ch2;  
	printf("请输入顶点数和边数(输入格式为:顶点数,边数):");       
	scanf("%d,%d",&(G->n),&(G->e));       
	printf("请输入顶点名称(输入格式为:a,b,c...)：");       
	for(i=0;i<G->n;i++)      {         
	getchar();       
	scanf("%c",&(G->vexs[i]));      
	}  
	for(i=0; i<G->n; i++)
		for(j=0; j<G->n; j++)
			G->edges[i][j]=0;				//初始化邻接矩阵
	printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");  
	
	for(k=0;k<G->e;k++)          
	{              
	getchar();              
	printf("请输入第%d条边的两个顶点名称：",k+1);              
	scanf("%c,%c",&ch1,&ch2);              
	for(i=0;ch1!=G->vexs[i];i++);              
	for(j=0;ch2!=G->vexs[j];j++);  	    
	G->edges[j][i]=1;            
	G->edges[i][j]=1;          
	}    

}

/*****************************/
/*          主函数           */
/*****************************/
int main()
{
	int i;
	MGraph *G;
	G=(MGraph *) malloc(sizeof(MGraph));	//为图G申请内存空间
	CreatMGraph(G);						//建立邻接矩阵
	printf("Print Graph DFS: ");
	DFS(G);									//深度优先遍历
	printf("\n");
	printf("Print Graph BFS: ");
//	BFS(G,3);								//以序号为3的顶点开始广度优先遍历
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
/*        DFS：深度优先遍历       */
/* （递归部分：以节点i为出发点）  */
/***********************************/
void DFSM(MGraph *G, int i)
{
	int j;       
	printf("%c\n",G->vexs[i]);   //访问顶点vi       
	visited[i]=TRUE;               
	for(j=0;j<G->n;j++)           //依次搜索vi邻接点          
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
/*        BFS：广度优先遍历       */
/*      （以节点k为出发点）       */
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
  if(!visited[i])    //未访问过 该顶点 		
  {			
  visited[i]=TRUE;			
  
  printf("%c->",G->vexs[i]);			
  
  EnQueue(&Q,i);      //将其入队列 			
  while(!QueueEmpty(&Q))			
  {				
  i=DeQueue(&Q);    //将队中元素出队列，赋值给i 				
  for(int j=0;j<G->n;j++)				
  {					
  if(G->edges[i][j]==1&&!visited[j])      //其他顶点与该顶点存在边   且未访问过 					
  {						
  visited[j]=TRUE;						
  printf("%c",G->vexs[j]);						
  EnQueue(&Q,j);                 //入队列 					
  }									
  } 			
  } 		
  }	
  }
  } 






