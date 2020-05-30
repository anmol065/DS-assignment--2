#include<stdio.h>
void imergesort(int a[],int n);
void rmergesort(int a[],int l,int h);
void merge(int a[],int l,int m,int h);
int main()
{int i;
    int a[]={10,9,8,7,6,5,4,3,2};
    printf("\narray before merge sort:");
    for(i=0;i<9;i++)
    printf("%d ",a[i]);
    imergesort(a,9);
    //rmergesort(a,0,8);
    printf("\narray after merge sort:");
    for(i=0;i<9;i++)
    printf("%d ",a[i]);
}
void imergesort(int a[],int n)
{
    int h,l,m,i,p;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<=n;i=i+p)
        {
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            merge(a,l,m,h);
        }
    }
    if(p/2<n)
    merge(a,0,p/2-1,n-1);
}
void rmergesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        rmergesort(a,l,mid);
        rmergesort(a,mid+1,h);
        merge(a,l,mid,h);

    }
}
void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int b[20];
    while(i<=mid&&j<=h)
    {
        if(a[i]<a[j])
        {
		    b[k++]=a[i++];
		}
        else
        {
		    b[k++]=a[j++];
		}
    }
    for(;i<=mid;i++)
    b[k++]=a[i];
    for(;j<=h;j++)
    b[k++]=a[j];
    for(i=l;i<=h;i++)
    a[i]=b[i];
}
