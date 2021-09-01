#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"


typedef struct node          //������
 {
char data[10];             //����������Ϊ�ַ���
struct node *next;      //����ָ����
 }ListNode;

typedef ListNode * LinkList;

LinkList CreatListR1();              //��������β���뷨������ͷ���ĵ�����
LinkList CreatList(void);            //��������ͷ���뷨������ͷ���ĵ�����
ListNode *LocateNode(LinkList head, char *key);
void DeleteList(LinkList head, char *key);                 //������ɾ��ָ��ֵ�Ľ��
 void printList(LinkList head);                   //��������ӡ�����е�����ֵ
 void DeleteAll(LinkList head);                   //������ɾ�����н�㣬�ͷ��ڴ�
 ListNode * AddNode(LinkList head);                      //�޸ĳ������ӽڵ㡣��ͷ�巨������ͷָ��


/*****************************/
/*          ������           */
/*****************************/
int main()
{
	char ch[10], num[5];
	LinkList head;
	head = CreatListR1();             //��ͷ���뷨��������������ͷָ��
	printList(head);              //�������������ֵ
	printf(" Delete node (y/n):");    //����"y"��"n"ȥѡ���Ƿ�ɾ�����
	scanf("%s", num);
	if (strcmp(num, "y") == 0 || strcmp(num, "Y") == 0) {
		printf("Please input Delete_data:");
		scanf("%s", ch);	        //����Ҫɾ�����ַ���
		DeleteList(head, ch);
		printList(head);
	}
	printf(" Add node ? (y/n):");   //����"y"��"n"ȥѡ���Ƿ����ӽ��
	scanf("%s", num);
	if (strcmp(num, "y") == 0 || strcmp(num, "Y") == 0)
	{
		head = AddNode(head);
	}

	printList(head);
	DeleteAll(head);            //ɾ�����н�㣬�ͷ��ڴ�
	return 0;
}

/********************************/
/* ͷ���뷨������ͷ���ĵ����� */
/********************************/
LinkList CreatList(void)
{
 char ch[10];
    LinkList head=(LinkList)malloc(sizeof(ListNode)); //����ͷ���
   ListNode *s,*r,*pp;
    r=head;
   r->next=NULL;
     printf("Input # to end  ");  //����"#"�����������
    printf("\nPlease input Node_data:");
   scanf("%s",ch);           //����������ַ���
     while(strcmp(ch,"#")!=0) {        
               pp=LocateNode(head,ch);      //��ֵ���ҽ�㣬���ؽ��ָ��
              if(pp==NULL) {            //û���ظ����ַ��������뵽������
                    s=(ListNode *)malloc(sizeof(ListNode));
                     strcpy(s->data,ch);
                      r->next=s;
                     r=s;
                     r->next=NULL;
              }
              printf("Input # to end  ");
              printf("Please input Node_data:");
               scanf("%s",ch);
    }
	return head;
}

/********************************/
/* β���뷨������ͷ���ĵ����� */
/********************************/
LinkList CreatListR1(void)
{
	char ch[10];
	LinkList head, p,rear;
	head = (LinkList)malloc(sizeof(ListNode));
	head->next = NULL;
	rear = head;
	printf("Input # to end  ");  //����"#"�����������
	printf("\nPlease input Node_data:");
	scanf("%s", ch);           //����������ַ���
	while (strcmp(ch, "#") != 0)
	{
		p=(ListNode *)malloc(sizeof(ListNode));
		strcpy(p->data, ch);
		rear->next = p;
		rear = p;
		printf("Input # to end\n  ");
	    printf("Please input Node_data:");
		scanf("%s",&ch);
	}
	rear->next = NULL;
	return(head);
}

/******************************************************/
/*��ֵ���ҽ�㣬�ҵ��򷵻ظý���λ�ã����򷵻�NULL */
/*******************************************************/
ListNode* LocateNode(LinkList head, char *key)
{
ListNode *p=head->next; //�ӿ�ʼ���Ƚ�
    while(p!=NULL && strcmp(p->data,key)!=0)  //ֱ��pΪNULL��p->dataΪkeyֹ
	      p=p->next;        //ɨ����һ�����
    return p;    //��p=NULL�����ʧ�ܣ�����pָ���ҵ���ֵΪkey�Ľ��
}



	/********************************/
	/*      �޸ĳ������ӽڵ�      */
	/********************************/
	ListNode * AddNode(LinkList head)
	{
		char ch[10];
		ListNode *p,*t;
		printf("\nPlease input a New Node_data:");
		scanf("%s", ch);         //����������ַ���
		t = LocateNode(head, ch);      //��ֵ���ҽ�㣬���ؽ��ָ��
		printf("ok2\n");

		if (t == NULL) {            //û���ظ����ַ��������뵽������
			p = (ListNode *)malloc(sizeof(ListNode));
			strcpy(p->data, ch);
			printf("ok3\n");

			p->next = head->next;
			head->next = p;

		}

		return head;
	}
	//==========ɾ����ͷ���ĵ������е�ָ�����=======
	 void DeleteList(LinkList head, char *key)
{
	   ListNode *p, *r, *q = head;
       p = LocateNode(head, key);    //��keyֵ���ҽ���
	
	   if (p == NULL) {            //��û���ҵ���㣬�˳�
		   
		   printf("position error");
           exit(0);
			
		}
		  while (q->next != p)        //pΪҪɾ���Ľ�㣬qΪp��ǰ���
			  q = q->next;
		    r = q->next;
		    q->next = r->next;
             free(r);                //�ͷŽ��
	 }
	//===========��ӡ����=======
void printList(LinkList head)
 {
	  ListNode *p = head->next;       //�ӿ�ʼ����ӡ
	  while (p) {
		 printf("%s," ,p->data);
		 p = p->next;
			
		}
		     printf("\n");
}
	 //==========ɾ�����н�㣬�ͷſռ�===========
void DeleteAll(LinkList head)
{
	ListNode *p = head, *r;
	while (p->next) {
		r = p->next;
		free(p);

		p = r;

	}
	free(p);
}

