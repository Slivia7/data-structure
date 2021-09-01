/*****************************/
/*    二叉树和函数定义       */
/*****************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
#define Max 20	
const int N = 1010;					//结点的最大个数
typedef struct node{
char data;
struct node *lchild, *rchild;
}BinTNode;							//自定义二叉树的结点类型
typedef BinTNode *BinTree;			//定义二叉树的指针
int NodeNum,leaf,num;					//NodeNum为结点数，leaf为叶子数

void CreatBinTree(BinTree *T);			//基于先序遍历算法创建二叉树
void Preorder(BinTree T);				//先序遍历二叉树
void Inorder(BinTree T)	;			//中序遍历二叉树
void Postorder(BinTree T);			//后序遍历二叉树
int TreeDepth(BinTree T);				//采用后序遍历求二叉树的深度、结点数及叶子数的递归算法
void Levelorder(BinTree T);			//层次遍历二叉树
int countleaf(BinTree T);	//数叶子节点个数
int Node(BinTree T);			//数结点数 

/*****************************/
/*          主函数           */
/*****************************/
int main()
{
BinTree root;
char i;
int depth;
printf("\n");
printf("Creat Bin_Tree； Input preorder:");	//输入完全二叉树的先序序列，用#代表虚结点，如ABD###CE##F##
CreatBinTree(&root);							//创建二叉树，返回根结点
do {											//从菜单中选择遍历方式，输入序号。
printf("\t********** select ************\n");
printf("\t1: Preorder Traversal\n");    
printf("\t2: Iorder Traversal\n");
printf("\t3: Postorder traversal\n");
printf("\t4: PostTreeDepth,Node number,Leaf number\n");
printf("\t5: Level Depth\n");				//按层次遍历之前，先选择4，求出该树的结点数。
printf("\t0: Exit\n");
printf("\t*******************************\n");
fflush(stdin);
scanf("%c",&i);							//输入菜单序号（0-5）
switch (i-'0'){
case 1:	printf("Print Bin_tree Preorder: ");
Preorder(root);				//先序遍历
break;
case 2:	printf("Print Bin_Tree Inorder: ");
Inorder(root);				//中序遍历
break;
case 3:	printf("Print Bin_Tree Postorder: ");
Postorder(root);				//后序遍历
break;
case 4:
depth=TreeDepth(root);		//求树的深度
NodeNum=Node(root);
printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
printf("  BinTree Leaf number=%d",countleaf(root));
break;
case 5:	printf("LevePrint Bin_Tree: ");
Levelorder(root);     //按层次遍历
break;
default: exit(1);
}
printf("\n");
} while(i!=0);
}
 

void CreatBinTree(BinTree *T)
{
char val;    
scanf("%c",&val);     
if(val == '#')        
*T = NULL;  //null表示为空枝     
else    {        
*T = (BinTree)malloc(sizeof(BinTNode));        
(*T)->data = val;        
CreatBinTree(&(*T)->lchild);
CreatBinTree(&(*T)->rchild);    
    
}

}
/********************************/
/*       先序遍历二叉树         */
/********************************/
void Preorder(BinTree T)
{
 if(T==NULL)

        return;

    printf("%c ",T->data);

    Preorder(T->lchild);

    Preorder(T->rchild);


}

/********************************/
/*       中序遍历二叉树         */
/********************************/
void Inorder(BinTree T)
{
    if(T==NULL)

        return;

    Inorder(T->lchild);

    printf("%c ",T->data);

    Inorder(T->rchild);


}

/********************************/
/*       后序遍历二叉树         */
/********************************/
void Postorder(BinTree T)
{
  if(T==NULL)

        return;

    Postorder(T->lchild);

    Postorder(T->rchild);

    printf("%c ",T->data);


}

/************************************************/
/*  采用后序遍历求二叉树的深度、结点数及叶子数  */
/************************************************/
//要求采用递归算法
int TreeDepth(BinTree T)
{
	int x=0,y = 0;    
	if(T!=NULL)    {        
	x = TreeDepth(T->lchild);         
	y = TreeDepth(T->rchild);         
	if(x>y)            
	return(x+1);        
	else            
	return (y+1);    
	}    
	else        
	return 0;




}

/**************************************************/
/*  利用"先进先出"（FIFO）队列，按层次遍历二叉树  */
/**************************************************/
void Levelorder(BinTree T)
{
  BinTree que[N],p;    
 int f,r;   //队列的头指针 和 尾指针    
 f = -1; r = -1;    
 que[++r] = T;  //根节点入队    
 while(f!=r)    {        
 f = (f + 1)% N; //防止队溢出        
 p = que[f]; //队列头结点 出队        
 printf("%c -> ",p->data);        
 if(p->lchild !=NULL)  // 将其左孩子 压入队列        
 {            
 r = (r + 1 )% N;            
 que[r] = p->lchild;        
 }        
 if(p->rchild !=NULL)  // 将其右孩子 压入队列        
 {            
 r = (r + 1 )% N;            
 que[r] = p -> rchild;        
 }    
 }



}

/********************************/
/*       数叶子节点个数         */
/********************************/
int countleaf(BinTree T)
{
//	if(T!=NULL){
//		if(!T->lchild && !T->rchild )
//	}
   return !T ?           
   0 :           
   !T->lchild && !T->rchild ?            
   1 :            
   countleaf(T->lchild) + countleaf(T->rchild);

}
/********************************/
/*       数结点个数         */
/********************************/
int Node(BinTree T){
// return !T ?
//
//           0 :
//
//           Node(T->lchild) + Node(T->rchild) + 1;
if (T == NULL) {

			return 0;

		}

		num++;

		Node(T->lchild);

		Node(T->rchild);

 

		return num;
 
} 

