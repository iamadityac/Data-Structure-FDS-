#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    float degree,co;
    struct node *next;
};

struct node *create(struct node*,struct node*,struct node*);
void disp(struct node*,struct node*);
struct node *add(struct node*,struct node*);
void evalue(struct node*,struct node*,struct node*,struct node*);
struct node *multi(struct node*,struct node*);

int main()
{
    struct node *head,*head1,*nodeptr,*prev,*addp,*multip;
    int ch;
    printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
    printf("\n\t\t**Circular linked list**\n");
    printf("\n\tEquation 1 :");
    head=create(head,nodeptr,prev);
    printf("\n\tEquation 2 :");
    head1=create(head1,nodeptr,prev);
    
    do
    {
        printf("\n-----------------------------------------------------");
        printf("\n\t\t**Menu**");
        printf("\n\t1.Display\n\t2.Addition\n\t3.Multiplication\n\t4.Evaluate\n\t0.exit  \t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n\tEquation 1 : \n\t");
                disp(head,nodeptr);
                printf("\n\n\tEquation 2 : \n\t");
                disp(head1,nodeptr);
                break;
            
            case 2:
                addp=add(head,head1);
                disp(addp,nodeptr);
                break;
                
            case 3:
                multip=multi(head,head1);
                disp(multip,nodeptr);
                   break;
                
            case 4:
                evalue(head,head1,addp,multip);
                break;
        }
    }while(ch!=0);
}

struct node *create(struct node *head,struct node *nodeptr,struct node *prev)
{
    int fl=0,n,i;
    printf("\n\tEnter the highest degree of polynomial equation : \t");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        nodeptr=(struct node *)malloc(sizeof(struct node));
        if(nodeptr!=NULL)
        {
            if(fl==0)
            {
                head=prev=nodeptr;
                nodeptr->next=head;
                printf("\n\tEnter the coefficient of degree %d : \t",n-i);
                scanf("%f",&nodeptr->co);
                nodeptr->degree=n-i;
                fl=1;
            }
            else
            {
                nodeptr->next=head;
                printf("\n\tEnter the coefficient of degree %d : \t",n-i);
                scanf("%f",&nodeptr->co);
                prev->next=nodeptr;
                prev=nodeptr;
                nodeptr->degree=n-i;
            }
        }
        else
            printf("\n\tMemory is not available.Please free the memory.");
    }
    return head;
}

void disp(struct node *head,struct node *nodeptr)
{
    for(nodeptr=head;nodeptr->next!= head;nodeptr=nodeptr->next)
    {
        if(nodeptr->co!=0)
            printf("%0.0fx^%0.0f + ",nodeptr->co,nodeptr->degree);
    }
    printf("%0.0f ",nodeptr->co);
}    

struct node *add(struct node *head,struct node *head1)
{
    struct node *nodeptr=head,*nodeptr1=head1;
    struct node *addp,*sumptr,*prev;
    
    int i,n=(nodeptr->degree > nodeptr1->degree ? nodeptr->degree : nodeptr1->degree);
    
    printf("\n\tAddition is : \n\t");
    
    for(i=0;i<n;i++)
    {
        if(i==0)
            addp=prev=sumptr=(struct node *)malloc(sizeof(struct node));
        else 
            sumptr=(struct node *)malloc(sizeof(struct node));    
            
        sumptr->next=addp;
        if(nodeptr->degree > nodeptr1->degree)
        {
            sumptr->co=nodeptr->co;    
            sumptr->degree=nodeptr->degree;
            nodeptr=nodeptr->next;
            prev->next=sumptr;
            prev=sumptr;
        }
        else if(nodeptr->degree < nodeptr1->degree)
        {
            sumptr->co=nodeptr1->co;
            sumptr->degree=nodeptr1->degree;
            nodeptr1=nodeptr1->next;
            prev->next=sumptr;
            prev=sumptr;
        }
        else if(nodeptr->degree == nodeptr1->degree)
        {
            sumptr->co=nodeptr->co + nodeptr1->co;
            sumptr->degree=nodeptr->degree;
            nodeptr=nodeptr->next;
            nodeptr1=nodeptr1->next;
            prev->next=sumptr;
            prev=sumptr;
        }
    }
    sumptr=(struct node *)malloc(sizeof(struct node));    
    sumptr->next=addp;
    sumptr->co=nodeptr->co+nodeptr1->co;
    prev->next=sumptr;
    prev=sumptr;
    return addp;
}    

struct node *multi(struct node *head,struct node *head1)
{
    int i,j,var,sum;
    struct node *nodeptr=head,*nodeptr1=head1;
    struct node *multip,*sumptr,*prev;
    printf("\n\tMultiplication is : \n\t");
    for(var=head->degree+head1->degree ; var>=0 ; var--)
    {
        if(var==head->degree+head1->degree)
            multip=prev=sumptr=(struct node *)malloc(sizeof(struct node));    
        else
            sumptr=(struct node *)malloc(sizeof(struct node));    
        
        sum=0;
        for(i=0;i<=head->degree;i++)
        {
            for(j=0;j<=head1->degree;j++)
            {
                if(var==nodeptr->degree+nodeptr1->degree)
                    sum+=nodeptr->co*nodeptr1->co;
                nodeptr1=nodeptr1->next;
            }
            nodeptr=nodeptr->next;
        }

        sumptr->next=multip;
        sumptr->co=sum;
        sumptr->degree=var;
        prev->next=sumptr;
        prev=sumptr;
    }
    return multip;
}

void evalue(struct node *head,struct node *head1,struct node *addp,struct node *multip)
{
    struct node *nodeptr=head,*nodeptr1=head1,*nodeptr2=addp,*nodeptr3=multip;
    int i,value,sum;
    printf("\n\tEnter the value of 'x' for the evalueation of equation : \t");
    scanf("%d",&value);
    sum=0;
    for(i=0;i<=head->degree;i++)
    {
        sum+=(nodeptr->co*pow(value,nodeptr->degree));
        nodeptr=nodeptr->next;
    }
    printf("\n\tSolution of equation 1 is : %d ",sum);
    
    sum=0;
    for(i=0;i<=head1->degree;i++)
    {
        sum+=(nodeptr1->co*pow(value,nodeptr1->degree));
        nodeptr1=nodeptr1->next;
    }
    printf("\n\n\tSolution of equation 2 is : %d ",sum);
    
    sum=0;
    for(i=0;i<=addp->degree;i++)
    {
        sum+=(nodeptr2->co*pow(value,nodeptr2->degree));
        nodeptr2=nodeptr2->next;
    }
    printf("\n\n\tSolution of  addition equation is : %d ",sum);
    
    sum=0;
    for(i=0;i<=multip->degree;i++)
    {
        sum+=(nodeptr3->co*pow(value,nodeptr3->degree));
        nodeptr3=nodeptr3->next;
    }
    printf("\n\n\tSolution of  multiplication equation is : %d ",sum);
}




