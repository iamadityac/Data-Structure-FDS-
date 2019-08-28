#include<stdio.h>
#include<stdlib.h>

struct node
{
	float data;
	struct node *next;
};

struct node *create(struct node*,struct node*,struct node*);
void disp(struct node*,struct node*);
struct node *insert(struct node*,struct node*,struct node*);
float search(struct node*,struct node*,float);
struct node *delete(struct node*,struct node*,struct node*);
struct node reverse(struct node*,struct node*,struct node*);
struct node *revert(struct node*,struct node*,struct node*);
int size(struct node *);

int main()
{
	int ch;
	float key;
	struct node *head,*nodeptr,*prev;
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n\n");
  
	printf("\n\t\t**Linked list**\n");
	head=create(head,nodeptr,prev);
	
	do
	{
		printf("\n-----------------------------------------------------");
		printf("\n\t\t**Menu**");
		printf("\n\t1.Display\n\t2.Insert\n\t3.Search\n\t4.Delete\n\t5.Reverse(using additional DS)\n\t6.Revert\n\t0.exit \t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				disp(head,nodeptr);
				break;
			
			case 2:
			    head=insert(head,nodeptr,prev);
			    disp(head,nodeptr);
				break;
				
			case 3:
			    printf("\n\tEnter the data of node u want to search : \t");
			    scanf("%f",&key);
			    key=search(head,nodeptr,key);
			    if(key==1)
			        printf("\n\tEntered node is present");
			    else
			        printf("\n\tEntered node is not present");
			    break;
			    
			case 4:
			    head=delete(head,nodeptr,prev);
			    disp(head,nodeptr);
			    break;
			    
			case 5:
				reverse(head,nodeptr,prev);
			    break;
			    
			case 6:
			    head=revert(head,nodeptr,prev);
			    disp(head,nodeptr);
			    break;
		}
	}while(ch!=0);			
}


int size(struct node *head)
{
	int n=0;
	struct node *nodeptr;
	
	for(nodeptr=head;nodeptr!=0;nodeptr=nodeptr->next)
		n++;
		
	return n;
}

struct node *create(struct node *head,struct node *nodeptr,struct node *prev)
{
	int fl=0,n,i;
	printf("\n\tHow many nodes u want to create? \t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		nodeptr=(struct node *)malloc(sizeof(struct node));
		if(nodeptr!=NULL)
		{
			if(fl==0)
			{
				head=prev=nodeptr;
				nodeptr->next=NULL;
				printf("\n\tEnter the data of node : \t");
				scanf("%f",&nodeptr->data);
				fl=1;
			}
			else
			{
				nodeptr->next=NULL;
				printf("\n\tEnter the data of node : \t");
				scanf("%f",&nodeptr->data);
				prev->next=nodeptr;
				prev=nodeptr;
			}
		}
		else
			printf("\n\tMemory is not available.Please free the memory.");
	}
	return head;
	
}

void disp(struct node *head,struct node *nodeptr)
{
	printf("\n\tLinked list is : \n\t");
	for(nodeptr=head;nodeptr != NULL;nodeptr=nodeptr->next)
		printf("%0.0f--> ",nodeptr->data);
	printf(" END");
}	
	
struct node *insert(struct node *head,struct node *nodeptr,struct node *prev)
{
	int ch,pos,i;
	nodeptr=(struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter the data of node : \t");
	scanf("%f",&nodeptr->data);
	do
	{
		printf("\n\tWhere u want to insert a new node?");
		printf("\n\t1.At Start LL\n\t2.In between two nodes\n\t3.At End of LL\n\t0.Exit \t");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
				nodeptr->next=head;
				head=nodeptr;
				return head;
				break;
				
			case 2:
			    printf("\n\tAt which position u want to add new node? \t");
			    scanf("%d",&pos);
			    nodeptr->next=NULL;
			    if(pos==1)
			    {
			        nodeptr->next=head;
			        return nodeptr;
			    }
			    prev=head;
			    for(i=1;i<pos-1;i++)
			        if(prev!=NULL)
			            prev=prev->next;
			    nodeptr->next=prev->next;
			    prev->next=nodeptr;
			    return head;
			    break;
				
			case 3:
			    nodeptr->next=NULL;
			    if(head==NULL)
			        return nodeptr;
			    prev=head;
			    while(prev->next!=NULL)
			        prev=prev->next;
			    prev->next=nodeptr;
			    return head;
				break;
				
		}
	}while(ch!=0);
}

float search(struct node *head,struct node *nodeptr,float key)
{
    nodeptr=head;
    while(nodeptr!=NULL)
    {
        if(nodeptr->data==key)
            return 1;
        else 
            return 0;
        nodeptr=nodeptr->next;
    }
}

struct node *delete(struct node *head,struct node *nodeptr,struct node *prev)	
{
    int ch,i;
    float key;
	do
	{
		printf("\n\tWhich node u want to delete?");
		printf("\n\t1.First node\n\t2.Any node\n\t3.Last node\n\t0.Exit \t");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
				nodeptr=head;
				head=head->next;
				free(nodeptr);
				return head;
				break;
				
			case 2:
			    printf("\n\tEnter the data of node u want to delete? \t");
			    scanf("%f",&key);
			    if(head->data==key)
			    {
			        nodeptr=head;
			        head=head->next;
			        free(nodeptr);
			        return head;
			    }
			    else
			    {
				    for(nodeptr=head;nodeptr!=NULL;nodeptr=nodeptr->next)
				    {
					    if(key==nodeptr->data)
					    {
					        prev->next=nodeptr->next;
					        free(nodeptr);
					        break;
					    }
					    prev=nodeptr;
				    }
				    if(nodeptr==NULL)
					printf("\n\tEntered node is not Present \n");
			    }
			    return head;
			    break;
				
			case 3:
			    if(head->next==NULL)
			    {
			        free(head);
			        head=NULL;
			        return head;
			    }
			    prev=head;
			    while(prev->next->next!=NULL)
			        prev=prev->next;
			    nodeptr=prev->next;
			    free(nodeptr);
			    prev->next=NULL;
			    return head;
				break;
		}
	}while(ch!=0);
}   

struct node reverse(struct node *head,struct node *nodeptr,struct node *prev)
{
	int *a,n,i;
	n=size(head);
	printf("\n\t");
	a=(int *)malloc(sizeof(int)*n);
	nodeptr=head;
	for(i=0;i<n;i++)
	{
		*(a+i)=nodeptr->data;
		nodeptr=nodeptr->next;
	}
	printf("Linked list is : \n\t");
	for(i=n-1;i>=0;i--)
		printf("%d--> ",*(a+i));
	printf(" END");	
}

struct node *revert(struct node *head,struct node *nodeptr,struct node *prev)
{
    struct node *rev;
    nodeptr=NULL;
    prev=head;
    rev=prev->next;
    while(prev!=NULL)
    {
        prev->next=nodeptr;
        nodeptr=prev;
        prev=rev;
        if(rev!=NULL)
            rev=rev->next;
    }
    return nodeptr;
}




