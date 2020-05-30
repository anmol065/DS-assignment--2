#include<stdio.h>
void imergesort(char a[],int n);
void rmergesort(char a[],int l,int h);
void merge(char a[],int l,int m,int h);
int main()
{int i;
    char a[]={'p','o','l','y','n','o','m','i','a','l'};
    printf("\n\n test case 1 (polynomial)");
    printf("\n before merge sort:");
    for(i=0;i<10;i++)
    printf("%c",a[i]);
    imergesort(a,10);

    printf("\n  using iterative merge sort:");
    for(i=0;i<10;i++)
    printf("%c",a[i]);
    rmergesort(a,0,9);

    printf("\n  using recursive merge sort:");
    for(i=0;i<10;i++)
    printf("%c",a[i]);
    printf("\n\n\n" );
    char b[]={'t','e','s','t',' ','c','a','s','e'};
    printf("\n\n test case 2 (test case)");
    printf("\n before merge sort:");
    for(i=0;i<9;i++)
    printf("%c",b[i]);
    imergesort(b,9);

    printf("\n  using iterative merge sort:");
    for(i=0;i<9;i++)
    printf("%c",b[i]);
    rmergesort(b,0,8);

    printf("\n  using recursive merge sort:");
    for(i=0;i<9;i++)
    printf("%c",b[i]);
    printf("\n\n\n" );
}
void imergesort(char a[],int n)
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
    merge(a,0,(p/2)-1,n-1);
}
void rmergesort(char a[],int l,int h)
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
void merge(char a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    char b[20];
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
