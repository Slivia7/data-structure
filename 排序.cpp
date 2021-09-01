#include"stdio.h"
#include"stdlib.h"
#define Max 100							//�����ļ�����
typedef struct
{										//�����¼����
int key;								//�ؼ�����
} RecType;
typedef RecType SeqList[Max+1];			//SeqListΪ˳������е�0��Ԫ����Ϊ�ڱ�
int n;									//˳���ʵ�ʵĳ���
void Heapify( SeqList R,int low,int high);
void Merge(SeqList R,int low,int m,int high);

/*****************************/
/*        ����˳���         */
/*****************************/
void input_int(SeqList R)
{ 
int i;
printf("Please input num(int):");
scanf("%d", &n);
printf("Plase input %d integer:", n);
for(i=1; i<=n; i++)
scanf("%d", &R[i].key);
}

/*****************************/
/*        ���˳���         */
/*****************************/
void output_int(SeqList R)
{
int i;
for(i=1; i<=n; i++)
printf("%d", R[i].key);
}
/*****************************/
/*    No.1 ֱ�Ӳ�������      */
/*****************************/
void InsertSort(SeqList L){	
int i,j;	
for(i=1;i<=n;i++)	{
	if(L[i].key<L[i-1].key)		
	{			
		L[0].key=L[i].key;			
		for(j=i-1;L[j].key>L[0].key;j--)			
		{				
		  L[j+1].key=L[j].key;			
		}			
	   	L[j+1].key=L[0].key;		
	}	
	}

}


/*****************************/
/*      No.2 ð������       	*/
/*****************************/

typedef enum {FALSE, TRUE} Boolean;	//FALSEΪ0��TRUEΪ1

void BubbleSort(SeqList R)  

{  

    int i, j, tmp;
	 
    for (i=1;i<=n-1;i++) {  

        for (j=1;j<=n-i;j++) {  
          
            if (R[j].key > R[j+1].key) {  

                tmp = R[j].key;  

                R[j].key = R[j+1].key;  

                R[j+1].key= tmp;  
                 
            }  

        }  

    }  

}  

/**********************************************/
/*      No.3 ��������һ�λ������������   */
/**********************************************/
int Partition(SeqList L,int low,int high)

{

	int pivotkey;

	int m=low+(high-low);//����ȡ�з�ѡȡ����ֵ 

	if(L[low].key>L[high].key){
	int temp=L[low].key;

	L[low].key=L[high].key;

	L[high].key=temp;
	}

	// ����������Ҷ����ݣ���֤��˽�С 

	if(L[m].key>L[high].key){
	int temp=L[high].key;

	L[high].key=L[m].key;

	L[m].key=temp;
	}

//�����м����Ҷ����ݣ���֤�м��С 

	if(L[m].key>L[low].key){
	int temp=L[m].key;

	L[m].key=L[low].key;

	L[low].key=temp;
	}

	//�����м���������ݣ���֤�м��С 

	pivotkey=L[low].key;

	L[0].key=pivotkey;//������ؼ��ֱ��ݵ�0λ 

	while(low<high)

	{

		while(low<high&&L[high].key>=pivotkey)

			high--;

		L[low].key=L[high].key;

		while(low<high&&L[low].key<=pivotkey)

			low++;

		L[high].key=L[low].key;

	}

	L[low].key=L[0].key;

	return low; 

}
void QuickSort(SeqList L,int low,int high)

{

	int pivot;

	while(low<high)

	{

		pivot=Partition(L,low,high);//������һ��Ϊ�����������ֵpivot 

		QuickSort(L,low,pivot-1);//�Ե��ӱ�ݹ����� 

		low=pivot+1;//β4�ݹ� 

	}

}

/***********************************/
/*     No.4 ֱ��ѡ������           */
/***********************************/
void SelectSort(SeqList L)

{

	int i,j,min;

	for(i=1;i<n+1;i++)

	{

		min=i;

		for(j=i+1;j<n+1;j++)

		{

			if(L[min].key>L[j].key)

				min=j;

		}

		if(i!=min){
			int temp=L[i].key;
			L[i].key=L[min].key;
			L[min].key=temp;
		}

		

	}

}
/************************************/
/*         No.4. ������             */
/************************************/
//1.========��������=====
void BuildHeap(SeqList R)
{
	//����ʼ�ļ�R[1..n]����Ϊ��
	int i;
	for(i=n/2; i>0; i--)
	Heapify(R,i,n);						//��R[i..n]����Ϊ�����
}

//2.========����ѵ���=====
void Heapify( SeqList R,int low,int high)
{
	int temp,j;

	temp=R[low].key;

	for(j=2*low;j<=high;j*=2)

	{

		if(j<high&&R[j].key<R[j+1].key)

			++j;

		if(temp>=R[j].key)

			break;

		R[low].key=R[j].key;

		low=j;

	}

       R[low].key=temp;
}

//3.========������=====
void HeapSort(SeqList R)
{
	//��R[1..n]���ж����򣬲�����R[0]���ݴ浥Ԫ
	int i;
	BuildHeap(R);						//��R[1..n]����Ϊ��ʼ�����
	for(i=n; i>1; i--)
	{	//�Ե�ǰ������R[1..i]���ж����򣬹���n-1�ˡ�
		R[0]=R[1];
		R[1]=R[i];
		R[i]=R[0];						//���Ѷ��Ͷ������һ����¼����
		//��R[1..i-1]���µ���Ϊ�ѣ�����R[1]����Υ�������ʡ�
		Heapify(R, 1, i-1);
	}
}

/************************************/
/*       No.5 ����·�鲢����        */
/************************************/
//1.========��һ�˹鲢����=====
void MergePass(SeqList R, int length)
{
	  int i;
      for(i=1;i+2*length-1<=n;i=i+2*length)
      Merge(R,i,i+length-1,i+2*length-1);
           //�鲢����Ϊlength�������������ļ�
      if(i+length-1<n) //�����������ļ������к�һ������С��length
         Merge(R,i,i+length-1,n); //�鲢����������ļ�

}

//2.========��·�鲢����=====
void MergeSort(SeqList R)
{
	int length;
	for (length=1; length<n; length*=2)		//��[lgn]������
		MergePass(R,length);					//���򳤶ȡ�nʱ��ֹ
}

 void Merge(SeqList R,int low,int m,int high)
    {//��������������ļ�R[low..m)��R[m+1..high]�鲢��һ�������
     //���ļ�R[low..high]
     int i=low,j=m+1,p=0; //�ó�ʼֵ
     RecType *R1; //R1�Ǿֲ���������p����Ϊ������ָ���ٶȸ���
     R1=(RecType *)malloc((high-low+1)*sizeof(int));
    
     while(i<=m&&j<=high) //�����ļ��ǿ�ʱȡ��С�������R1[p]��
	 
       R1[p++]=(R[i].key<=R[j].key)?R[i++]:R[j++];
     while(i<=m) //����1�����ļ��ǿգ�����ʣ���¼��R1��
       R1[p++]=R[i++];
     while(j<=high) //����2�����ļ��ǿգ�����ʣ���¼��R1��
       R1[p++]=R[j++];
     for(p=0,i=low;i<=high;p++,i++)
       R[i]=R1[p];//�鲢��ɺ󽫽�����ƻ�R[low..high]
    } //Merge


/*****************************/
/*          ������           */
/*****************************/
int main()
{
int i;
SeqList R;
input_int(R);
printf("\t******** Select **********\n");
printf("\t1: Insert Sort\n");
printf("\t2: Bubble Sort\n");
printf("\t3: Quick Sort\n");
printf("\t4: Straight Selection Sort\n");
printf("\t5: Heap Sort\n");
printf("\t6: Merge Sort\n");
printf("\t7: Exit\n");
printf("\t***************************\n");
scanf("%d", &i);						//��������1-7��ѡ������ʽ
switch (i)
{
case 1: InsertSort(R); break;		//ֵΪ1��ֱ�Ӳ�������
case 2: BubbleSort(R); break;		//ֵΪ2��ð�ݷ�����
case 3: QuickSort(R,1,n); break;	//ֵΪ3����������
case 4: SelectSort(R); break;		//ֵΪ4��ֱ��ѡ������
case 5: HeapSort(R); break;		//ֵΪ5��������
case 6: MergeSort(R); break;		//ֵΪ6���鲢����
case 7: exit(0);					//ֵΪ7����������
}
printf("Sort reult:");
output_int(R);
}

