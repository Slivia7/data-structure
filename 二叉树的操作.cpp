/*****************************/
/*    �������ͺ�������       */
/*****************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
#define Max 20	
const int N = 1010;					//����������
typedef struct node{
char data;
struct node *lchild, *rchild;
}BinTNode;							//�Զ���������Ľ������
typedef BinTNode *BinTree;			//�����������ָ��
int NodeNum,leaf,num;					//NodeNumΪ�������leafΪҶ����

void CreatBinTree(BinTree *T);			//������������㷨����������
void Preorder(BinTree T);				//�������������
void Inorder(BinTree T)	;			//�������������
void Postorder(BinTree T);			//�������������
int TreeDepth(BinTree T);				//���ú�����������������ȡ��������Ҷ�����ĵݹ��㷨
void Levelorder(BinTree T);			//��α���������
int countleaf(BinTree T);	//��Ҷ�ӽڵ����
int Node(BinTree T);			//������� 

/*****************************/
/*          ������           */
/*****************************/
int main()
{
BinTree root;
char i;
int depth;
printf("\n");
printf("Creat Bin_Tree�� Input preorder:");	//������ȫ���������������У���#�������㣬��ABD###CE##F##
CreatBinTree(&root);							//���������������ظ����
do {											//�Ӳ˵���ѡ�������ʽ��������š�
printf("\t********** select ************\n");
printf("\t1: Preorder Traversal\n");    
printf("\t2: Iorder Traversal\n");
printf("\t3: Postorder traversal\n");
printf("\t4: PostTreeDepth,Node number,Leaf number\n");
printf("\t5: Level Depth\n");				//����α���֮ǰ����ѡ��4����������Ľ������
printf("\t0: Exit\n");
printf("\t*******************************\n");
fflush(stdin);
scanf("%c",&i);							//����˵���ţ�0-5��
switch (i-'0'){
case 1:	printf("Print Bin_tree Preorder: ");
Preorder(root);				//�������
break;
case 2:	printf("Print Bin_Tree Inorder: ");
Inorder(root);				//�������
break;
case 3:	printf("Print Bin_Tree Postorder: ");
Postorder(root);				//�������
break;
case 4:
depth=TreeDepth(root);		//���������
NodeNum=Node(root);
printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
printf("  BinTree Leaf number=%d",countleaf(root));
break;
case 5:	printf("LevePrint Bin_Tree: ");
Levelorder(root);     //����α���
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
*T = NULL;  //null��ʾΪ��֦     
else    {        
*T = (BinTree)malloc(sizeof(BinTNode));        
(*T)->data = val;        
CreatBinTree(&(*T)->lchild);
CreatBinTree(&(*T)->rchild);    
    
}

}
/********************************/
/*       �������������         */
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
/*       �������������         */
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
/*       �������������         */
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
/*  ���ú�����������������ȡ��������Ҷ����  */
/************************************************/
//Ҫ����õݹ��㷨
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
/*  ����"�Ƚ��ȳ�"��FIFO�����У�����α���������  */
/**************************************************/
void Levelorder(BinTree T)
{
  BinTree que[N],p;    
 int f,r;   //���е�ͷָ�� �� βָ��    
 f = -1; r = -1;    
 que[++r] = T;  //���ڵ����    
 while(f!=r)    {        
 f = (f + 1)% N; //��ֹ�����        
 p = que[f]; //����ͷ��� ����        
 printf("%c -> ",p->data);        
 if(p->lchild !=NULL)  // �������� ѹ�����        
 {            
 r = (r + 1 )% N;            
 que[r] = p->lchild;        
 }        
 if(p->rchild !=NULL)  // �����Һ��� ѹ�����        
 {            
 r = (r + 1 )% N;            
 que[r] = p -> rchild;        
 }    
 }



}

/********************************/
/*       ��Ҷ�ӽڵ����         */
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
/*       ��������         */
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

