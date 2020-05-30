#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    struct node**a;
};
struct node
{
    struct node*lchild;
    char data;
    struct node*rchild;
};

struct node*root=NULL;

void create(struct queue*a,int size);
void enqueue(struct queue*q,struct node*x);
struct node* dequeue(struct queue*q);
int isempty(struct queue q);


void binarytree();
void levelorder(struct node*root);


int main()
{
    printf("\n use ascii value when asked for entering and -1 for leaf nodes\n");
    printf(" we will use level order traversal for printing names using binary tree\n");
    binarytree();

    printf("\nlevelorder is\n");
    levelorder(root);

}
void create(struct queue*q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->a=(struct node**)malloc(q->size*sizeof(struct node*));
}
void enqueue(struct queue*q,struct node*x)
{
    if((q->rear+1)%q->size==q->front)
    printf("no more space");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=x;
    }
}

struct node*dequeue(struct queue*q)
{
    struct node*x;
    if(q->front==q->rear)
    printf("empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    if(q.front==q.rear)
    return 1;
    else return 0;
}

void binarytree()
{
    struct queue q;
    struct node*p;
    struct node*t;
    create(&q,20);
    int x=-1;
    printf("enter root element");
    scanf("%d",&x);
    root=(struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {
	    p=dequeue(&q);
        printf("enter lchild of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("enter rchild of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void levelorder(struct node *p)
{
    struct queue q;
    create(&q,20);
    printf("%c",root->data);
    enqueue(&q,root);
    while(!isempty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%c",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%c",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    } 
}
