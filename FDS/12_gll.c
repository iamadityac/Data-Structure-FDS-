#include<stdio.h>
#include<stdlib.h>

struct GLL
{
	int flag;
	union
	{
		char text[10];
		struct GLL *link;
	}data;
	struct GLL *next;
};

void display(struct GLL *head,int n);
struct GLL * create(struct GLL *head);

int main()
{
	int choice,flag=1;
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	printf("\n\t\t**Generalised linked list**\n");
	struct GLL *head,*ptr,*last;
	
	do
	{
	    printf("\n------------------------BOOK INDEX------------------------");
	    printf("\n\t1:Create\n\t2:Display\n\t0:EXIT : \t");
	    scanf("%d",&choice);
	    if(flag==1&&choice!=0)
		    choice=1;
	
	    switch(choice)
	    {
		    case 1:
		    	head=create(head);
		    	break;
		    	
		    case 2:
			    printf("\n----------INDEX----------\n");
			    display(head,0);
			    printf("\n-------------------------\n");
			    break;
	    }
	    flag=0;
	}while(choice!=0);
    printf("\n");
	return 0;
}

void display(struct GLL *head,int n)
{
	int i=1;
	struct GLL *ptr=head;
	
	while (ptr!=NULL)
	{
	    if(ptr->flag==1)
		    printf("\n\t%d%d - %s\n",n,i++,ptr->data.text);
	    else
	    {
		    printf("\n\t%d%d - ",n,i);
		    display(ptr->data.link,i++);
	    }
	    ptr=ptr->next;
	}
}

struct GLL * create(struct GLL *head)
{
	struct GLL *ptr,*last,*temp;
	int i,n;
	
	printf("\n\tEnter how many pts. u want to enter : \t ");
	scanf("%d",&n);
		
	for(i=0;i<n;i++)
	{
	    ptr=(struct GLL *)malloc(sizeof(struct GLL));
		if(ptr!=NULL)
	    {
		    if(i==0)
			    head=last=ptr;
			
			printf("\n\tPoint:%d-> 1:Only main point\n\t\t  2:Having Subpoints(link) :\t",i+1);
		    scanf("%d",&ptr->flag);
		    ptr->next=NULL;
		    if(ptr->flag==1)
		    {
			    printf("\n\tEnter the Point's data : \t ");
			    scanf("%s",ptr->data.text);
		    }
		    else
			    ptr->data.link=create(temp);
		
		    if(i!=0)
		    {
		        last->next=ptr;
		        last=ptr;
		    }
	    }
	    else
		    printf("\n\tMemory is not available for creating nodes.......");
	}
	printf("\n");
	return head;
}




