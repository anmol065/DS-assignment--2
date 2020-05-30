#include<stdio.h>
void swap(int *a,int*b);
void bubblesort(int a[],int n);
int main()
{int i;
    int a[]={23,45,21,1,2,3,5,65,78,90};
    printf("\narray before bubble sort is:\t");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    bubblesort(a,10);
     printf("\narray after bubble sort is:\t");
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
void bubblesort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {int flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag=1;
            }}
            if(flag==0)
                break;

    }
}
