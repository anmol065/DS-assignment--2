#include<stdio.h>
void swap(int *a,int *b);
void selectionsort(int a[],int n);
int main()
{int i;
    int a[]={10,9,8,7,6,5,4,3,2,1};
    printf("\narray before selection sort is:\t");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    selectionsort(a,10);
    printf("\narray after selection sort is:\t");
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
void selectionsort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[k]>a[j])
            k=j;
        }
        swap(&a[i],&a[k]);
    }
}
