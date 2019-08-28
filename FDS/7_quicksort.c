#include<stdio.h>

typedef struct stack
{
	
	int data[20]; 
	int top;
}stack;
int p=1;
int quick_sort_r(int a[],int,int,int);

int empty(stack *);
void init(stack *);
void push(stack *,int);
int pop(stack *);
int partition(int[],int,int);
void quick_sort(int[],int,int);

int main()
{
    int a[10],n,i,first,last,ch;
    printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
    printf("\n\t\t**Quick sort**\n");
    printf("\n\tenter the size of array : \t");
    scanf("%d",&n);
    
    printf("\n\tEnter the elements of array : \t");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    printf("\n\tEntered array elements are : \t");
    for(i=0;i<n;i++)
        printf("  %d",a[i]);
    
    do
    {
    	printf("\n-------------------------------------------------------------------------");
    	printf("\n\t\t**Menu**");
    	printf("\n\tDo u want to perform ");
    	printf("\n\t1.With recurtion\n\t2.Without recurtion\n\t0.Exit \t");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("\n\t**With recurtion**");
    			quick_sort_r(a,0,n-1,n);
    			break;
    			
    		case 2:
    		    printf("\n\t**Without recurtion**");
    			quick_sort(a,0,n-1);
    			printf("\n\tSorted data is : \t");
	            for(i=0;i<n;i++)
	                printf("   %d",a[i]);
	            printf("\n");
    			break;
    	}
    }while(ch!=0);
    printf("\n");
    return 0;
}

int quick_sort_r(int a[],int first,int last,int n)
{
    int pivot,i,j,k,temp;
    
    if(first<last)
    {
        i=pivot=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
                i++;
                while(a[j]>a[pivot])
                    j--;
                    if(i<j)
                    {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        
        printf("\n\tPASS #%d :",p++);
        for(k=0;k<n;k++)
    	{
    		printf("   %d",a[k]);
   		}
   		
        quick_sort_r(a,first,j-1,n);
        quick_sort_r(a,j+1,last,n);
    }
    return 0;
}

void quick_sort(int a[],int l,int u)
{
	stack s;
	int i,j,i1;
	init(&s);
	while(l<u)
	{
		j=partition(a,l,u);
		push(&s,j+1);
		push(&s,u);
		u=j-1;
		printf("\n\tPartition point :%d",j);
		printf("   List :");
		for(i1=l;i1<=u+1;i1++)
		    printf("   %d",a[i1]);
	}
	while(!empty(&s))
	{
		l=pop(&s);
		u=pop(&s);
		while(l<u)
		{
			j=partition(a,l,u);
			push(&s,j+1);
			push(&s,u);
			u=j-1;
			printf("\n\tPartition point :%d",j);
			printf("   List :");
			for(i1=l;i1<=u+1;i1++)
			    printf("   %d",a[i1]);
		}
	}
}

void init(stack *s)
{
	s->top=-1;
}

int empty(stack *s)
{
	if(s->top==-1)	
		return 1;
	else
		return 0;
}

void push(stack *s,int x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

int pop(stack *s)
{
	int x;
	x=s->data[s->top];
	s->top=s->top-1;
	return x;
}

int partition(int a[],int l,int u)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	do
	{
		do
	        i++;
		while(a[i]<v&&i<=u);
		do
		    j--;
		while(v<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=v;
	return j;
}          
