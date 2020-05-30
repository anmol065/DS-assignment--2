#include<stdio.h>
int partition(int a[],int l,int h);
void quicksort(int a[],int l, int h);
void swap(int *a,int *b);
int main()
{int l=0,h=10;
    int a[]={12,21,34,43,65,56,76,78,1,87,6556};
    printf("array before quick sort:\t");
    int i;
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    quicksort(a,0,10);
    printf("\narray after quick sort:\t");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int h)
{
    int i=l,j=h;
    int pivot=a[l];

    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
		   swap(&a[i],&a[j]);
		}
    }
	while(i<j);
    swap(&a[l],&a[j]);
    return j;
}
void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
