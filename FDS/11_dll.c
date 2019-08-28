#include<stdio.h>
#include<stdlib.h>

struct node
{
	int rolln;
	char name[10];
	struct node *prev,*next;
};

void display(struct node *);
void r_display(struct node *);
struct node * accept(struct node *);
struct node * insert(struct node *);
struct node * delet(struct node *);

int main()
{
	struct node *head;
	int choice;
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	printf("\n\t\t**Doubly Linked List\n");
	head=accept(head);
	do
	{
	    printf("\n------------------------------MENU---------------------------------------");
	    printf("\n\t1:Display\n\t2:Display(Reverse)\n\t3:Insert\n\t4:Delete\n\t0:Exit \t");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	        case 1:
	        	display(head);
	        	break;
	        	
	        case 2:
	        	r_display(head);
	        	break;
	        	
	        case 3:
	        	head=insert(head);
	        	break;
	        	
	        case 4:
	        	head=delet(head);
	        	break;
	    }	
	}while(choice!=0);
    printf("\n");
	return 0;
}

void display(struct node *head)
{
	struct node *nodeptr;

	for(nodeptr=head;nodeptr!=NULL;nodeptr=nodeptr->next)
		printf("\n\t%d\t%s",nodeptr->rolln,nodeptr->name);
		                                                                          
}

void r_display(struct node *head)
{
	struct node *nodeptr;

	for(nodeptr=head;nodeptr->next!=NULL;nodeptr=nodeptr->next);
	    for(;nodeptr!=NULL;nodeptr=nodeptr->prev)
	    	printf("\n\t%d\t%s",nodeptr->rolln,nodeptr->name);
		                                                                          
}

struct node * accept(struct node *head)
{
	int i,n,flag=0;
	struct node *last,*nodeptr;
	
	printf("\n\tEnter the No. of students u want to add : \t");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	    nodeptr=(struct node *)malloc(sizeof(struct node));
	    if(nodeptr!=NULL)
  	    {
		    if(flag==0)
		    {
		        head=last=nodeptr;
		        nodeptr->prev=NULL;
		        nodeptr->next=NULL;
		        printf("\n\tEnter Roll no. : \t ");
		        scanf("%d",&nodeptr->rolln);
		        printf("\n\tEnter the Name : \t");
		        scanf("%s",nodeptr->name);
		        flag=1;
		    }
		    else
		    {
		        nodeptr->next=NULL;
		        printf("\n\tEnter Roll no. : \t");
		        scanf("%d",&nodeptr->rolln);
		        printf("\n\tEnter the Name : \t");
		        scanf("%s",nodeptr->name);
		        last->next=nodeptr;
		        nodeptr->prev=last;
		        last=nodeptr;
		    }
	    }
	    else 
		    printf("\n\tMemory is full........");
	}
	return head;
} 

struct node * insert(struct node *head)
{
	int choice;
	struct node *nodeptr,*last;
	printf("\n\tDo u want to insert at ...");
	printf("\n\t1:head\n\t2:In-between\n\t3:Last : \t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			nodeptr=(struct node *)malloc(sizeof(struct node));
			
			printf("\n\tEnter Roll no. : \t ");
			scanf("%d",&nodeptr->rolln);
			printf("\n\tEnter the Name : \t");
			scanf("%s",nodeptr->name);
			
			head->prev=nodeptr;
			nodeptr->prev=NULL;
			nodeptr->next=head;
			head=nodeptr;
			break;
			
		case 2:
			printf("\n\tAdd after this Roll no : \t");
			scanf("%d",&choice);
			for(nodeptr=head;nodeptr!=NULL;nodeptr=nodeptr->next)
			{
			    if(nodeptr->rolln==choice&&nodeptr->next!=NULL)
			    {
				    last=nodeptr;
			
				    nodeptr=(struct node *)malloc(sizeof(struct node));
				    printf("\n\tEnter Roll no. : \t ");
				    scanf("%d",&nodeptr->rolln);
				    printf("\n\tEnter the Name : \t");
				    scanf("%s",nodeptr->name);
				    
				        nodeptr->prev=last;
				    nodeptr->next=last->next;
				    nodeptr->next->prev=nodeptr;				
				    last->next=nodeptr;	
				    
				    break;
			    }
			    else if(nodeptr->rolln==choice&&nodeptr->next==NULL)
			    {
				    last=nodeptr;
			    
				    nodeptr=(struct node *)malloc(sizeof(struct node));
				    printf("\n\tEnter Roll no. : \t ");
				    scanf("%d",&nodeptr->rolln);
				    printf("\n\tEnter the Name : \t");
				    scanf("%s",nodeptr->name);
				    
				    nodeptr->prev=last;
				    nodeptr->next=NULL;				
				    last->next=nodeptr;	
				    
				    break;			
			    }   
			}   
			if(nodeptr==NULL)
				printf("\n\tEntered Roll NO. is Not Present");
			break;
			
		case 3:
			for(nodeptr=head;nodeptr->next!=0;nodeptr=nodeptr->next);
			last=nodeptr;
			nodeptr=(struct node *)malloc(sizeof(struct node));
			nodeptr->next=NULL;
			nodeptr->prev=last;
	
			printf("\n\tEnter Roll no. : \t ");
			scanf("%d",&nodeptr->rolln);
			printf("\n\tEnter the Name : \t");
			scanf("%s",nodeptr->name);
			
			last->next=nodeptr;
			break;	
	}	
	display(head);
	return head;
}

struct node * delet(struct node *head)
{
	int choice;
	struct node *nodeptr,*last;
	printf("\n\tWhich data u want to delete?");
	printf("\n\t1:First\n\t2:Last\n\t3:Any : \t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			nodeptr=head;
			head=head->next;
			head->prev=NULL;
			free(nodeptr);
			break;
			
		case 2:
			for(nodeptr=head;nodeptr->next!=NULL;nodeptr=nodeptr->next)
				last=nodeptr;
			last->next=NULL;
			free(nodeptr);
			break;
			
		case 3:
			printf("\n\tEnter the Roll No. u want to delete : \t");
			scanf("%d",&choice);
			if(head->rolln==choice)
			{
				nodeptr=head;
				head=head->next;
				head->prev=NULL;
				free(nodeptr);
			}
			else
			{
				for(nodeptr=head->next;nodeptr!=NULL;nodeptr=nodeptr->next)
				{
					if(choice==nodeptr->rolln&&nodeptr->next!=NULL)
					{
					    nodeptr->prev->next=nodeptr->next;
					    nodeptr->next->prev=nodeptr->prev;
					    free(nodeptr);
					    break;
					}
					else if(choice==nodeptr->rolln&&nodeptr->next==NULL)
					{
					    nodeptr->prev->next=NULL;
					    free(nodeptr);
					    break;					
					}
				}
				if(nodeptr==NULL)
					printf("\n\tEntered Roll NO. is Not Present");
			}
			break;
	}
	display(head);
	return head;
}
