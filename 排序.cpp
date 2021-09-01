#include"stdio.h"
#include"stdlib.h"
#define Max 100							//假设文件长度
typedef struct
{										//定义记录类型
int key;								//关键字项
} RecType;
typedef RecType SeqList[Max+1];			//SeqList为顺序表，表中第0个元素作为哨兵
int n;									//顺序表实际的长度
void Heapify( SeqList R,int low,int high);
void Merge(SeqList R,int low,int m,int high);

/*****************************/
/*        输入顺序表         */
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
/*        输出顺序表         */
/*****************************/
void output_int(SeqList R)
{
int i;
for(i=1; i<=n; i++)
printf("%d", R[i].key);
}
/*****************************/
/*    No.1 直接插入排序      */
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
/*      No.2 冒泡排序       	*/
/*****************************/

typedef enum {FALSE, TRUE} Boolean;	//FALSE为0，TRUE为1

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
/*      No.3 快速排序（一次划分与快速排序）   */
/**********************************************/
int Partition(SeqList L,int low,int high)

{

	int pivotkey;

	int m=low+(high-low);//三数取中法选取枢轴值 

	if(L[low].key>L[high].key){
	int temp=L[low].key;

	L[low].key=L[high].key;

	L[high].key=temp;
	}

	// 交换左端与右端数据，保证左端较小 

	if(L[m].key>L[high].key){
	int temp=L[high].key;

	L[high].key=L[m].key;

	L[m].key=temp;
	}

//交换中间与右端数据，保证中间较小 

	if(L[m].key>L[low].key){
	int temp=L[m].key;

	L[m].key=L[low].key;

	L[low].key=temp;
	}

	//交换中间与左端数据，保证中间较小 

	pivotkey=L[low].key;

	L[0].key=pivotkey;//将枢轴关键字备份到0位 

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

		pivot=Partition(L,low,high);//将数组一分为二并算出枢轴值pivot 

		QuickSort(L,low,pivot-1);//对低子表递归排序 

		low=pivot+1;//尾4递归 

	}

}

/***********************************/
/*     No.4 直接选择排序           */
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
/*         No.4. 堆排序             */
/************************************/
//1.========构造大根堆=====
void BuildHeap(SeqList R)
{
	//将初始文件R[1..n]构造为堆
	int i;
	for(i=n/2; i>0; i--)
	Heapify(R,i,n);						//将R[i..n]调整为大根堆
}

//2.========大根堆调整=====
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

//3.========堆排序=====
void HeapSort(SeqList R)
{
	//对R[1..n]进行堆排序，不妨用R[0]做暂存单元
	int i;
	BuildHeap(R);						//将R[1..n]构造为初始大根堆
	for(i=n; i>1; i--)
	{	//对当前无序区R[1..i]进行堆排序，共做n-1趟。
		R[0]=R[1];
		R[1]=R[i];
		R[i]=R[0];						//将堆顶和堆中最后一个记录交换
		//将R[1..i-1]重新调整为堆，仅有R[1]可能违反堆性质。
		Heapify(R, 1, i-1);
	}
}

/************************************/
/*       No.5 做二路归并排序        */
/************************************/
//1.========做一趟归并排序=====
void MergePass(SeqList R, int length)
{
	  int i;
      for(i=1;i+2*length-1<=n;i=i+2*length)
      Merge(R,i,i+length-1,i+2*length-1);
           //归并长度为length的两个相邻子文件
      if(i+length-1<n) //尚有两个子文件，其中后一个长度小于length
         Merge(R,i,i+length-1,n); //归并最后两个子文件

}

//2.========二路归并排序=====
void MergeSort(SeqList R)
{
	int length;
	for (length=1; length<n; length*=2)		//做[lgn]趟排序
		MergePass(R,length);					//有序长度≥n时终止
}

 void Merge(SeqList R,int low,int m,int high)
    {//将两个有序的子文件R[low..m)和R[m+1..high]归并成一个有序的
     //子文件R[low..high]
     int i=low,j=m+1,p=0; //置初始值
     RecType *R1; //R1是局部向量，若p定义为此类型指针速度更快
     R1=(RecType *)malloc((high-low+1)*sizeof(int));
    
     while(i<=m&&j<=high) //两子文件非空时取其小者输出到R1[p]上
	 
       R1[p++]=(R[i].key<=R[j].key)?R[i++]:R[j++];
     while(i<=m) //若第1个子文件非空，则复制剩余记录到R1中
       R1[p++]=R[i++];
     while(j<=high) //若第2个子文件非空，则复制剩余记录到R1中
       R1[p++]=R[j++];
     for(p=0,i=low;i<=high;p++,i++)
       R[i]=R1[p];//归并完成后将结果复制回R[low..high]
    } //Merge


/*****************************/
/*          主函数           */
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
scanf("%d", &i);						//输入整数1-7，选择排序方式
switch (i)
{
case 1: InsertSort(R); break;		//值为1，直接插入排序
case 2: BubbleSort(R); break;		//值为2，冒泡法排序
case 3: QuickSort(R,1,n); break;	//值为3，快速排序
case 4: SelectSort(R); break;		//值为4，直接选择排序
case 5: HeapSort(R); break;		//值为5，堆排序
case 6: MergeSort(R); break;		//值为6，归并排序
case 7: exit(0);					//值为7，结束程序
}
printf("Sort reult:");
output_int(R);
}

