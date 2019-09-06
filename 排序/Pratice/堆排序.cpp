#include<stdio.h>

void swap(int *a, int *b)
{
    int p;
    p = *a;
    *a = *b;
    *b = p;
}

void adjustheap(int arr[], int i, int len)
{
    int j = i*2+1;
    //printf("%d\t",j);
    while(j < len)
    {

        if(j+1<len && arr[j] < arr[j+1]) //建立大堆,若左孩子小于右孩子,将j取值为右孩子的下标,右孩子再与父结点比较
        {
            j++;
        }
        //将左右孩子中，数值最大的与父结点进行比较,若孩子结点比父结点小,说明父结点的数值比左右孩子都大,不需要交换
        if(arr[i] > arr[j])
        {
                break;//说明该父结点和其孩子结点调整结束，退出循环，从下一个父结点调整

        }
        //else
                swap(&arr[i], &arr[j]);
        //交换之后还要考虑该目前j结点与自己的孩子结点的数值比较，还要进行调整,将i当前结点换成j结点所在位置，向下跑
        //printf("1");
        i = j;
        j = 2*i+1;
    }
}

//void makeheap(int arr[], int n)
//{
 //   int i;
//    printf("%d\n",n);
//    for(i=n/2-1; i>=0; i--)//要从最后一个父节点开始调整堆
//    {
//        printf("%d\t",i);
//        adjustheap(arr, i, n);
//    }
//}

void heapsort(int arr[], int len)
{
    int i = 0;
    //makeheap(arr, len);
    int j = 0;
   // printf("%d\n",len);
    for(i=len/2-1; i>=0; i--)//要从最后一个父节点开始调整堆
    {
        //printf("%d\t",i);
        adjustheap(arr, i, len);
    }

    //初次堆调整完成
    //每次排出最大的一个元素之后，将该元素排除在堆外,调整堆后交换堆顶元素和堆的最后一个元素
    for(j=len-1; j>0; j--)//所以要从元素最后一个开始
    {
        swap(&arr[j], &arr[0]);
        /*交换好堆后,重新调整堆*/

        //printf("%d\n",j);
        adjustheap(arr, 0, j);
    }
}

int main()
{
    int a[]={3,2,5,6,8,4,7,9,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d\t",n);
    heapsort(a, n);
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d",9/2-1);
    return 0;
}
