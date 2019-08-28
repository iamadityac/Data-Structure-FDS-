#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int rno,marks,del;
	char name[20];
};

int size();
void create(int,struct student []);
void add(int,struct student []);
void display(int,struct student []);
void search(int,int,struct student []);
void update(int,int,struct student []);
void delet(int,int,struct student []);
int p_delet(int,int,struct student []);
int bin(int,struct student []);

int main()
{
	int i,j,n,key,ch;
	char str[10]; 
	struct student s[10];
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	printf("\n\t\t**STUDENT DATABASE**\n");
	n=size();
	create(n,s);
	
	do 
	{
	    printf("\n\n_______________________________**MENU**___________________________________");
	    printf("\n\t1:ADD\n\t2:Display\n\t3:Search\n\t4:Update\n\t5:Delete\n\t6:Tempararily deleted Records\n\t0:EXIT\t");
	    scanf("%d",&ch);
	
	    switch(ch)
	    {
	        case 1:
		        n=n+1;
		        add(n,s);
		        break;
		    
	        case 2:
		        printf("\n\tRoll no.   Name \tMarks");
		        display(n,s);
		        break;
		    
	        case 3:
		        printf("\n\tEnter the roll no. of student u eant 2 search : \t");
		        scanf("%d",&key);
		        search(n,key,s);
		        break;
		    
	        case 4:
		        printf("\n\tEnter the roll no. of student u eant 2 update : \t");
		        scanf("%d",&key);
		        update(n,key,s);
		        break;
		    
	        case 5:
		        printf("\n\tEnter the roll no. of student u eant 2 delete : \t");
		        scanf("%d",&key);
		        for(i=0;i<n;i++)
		        {
		    	    if(s[i].del==0&&key==s[i].rno)
		    	    break;
		        }
		        if(i==n)
		        {
		        	    printf("\n\tRoll NO. is not present data.");
		        }
		        else
		        {
		            printf("\n\tDo u want 2 delete :");
		    	    printf("\n\t1.Logicaly\n\t2.Permanently :\t");
	        	    scanf("%d",&ch);
	    		    if(ch==1)
	    			    delet(n,key,s);
	    		    if(ch==2)
	    		    {
	    			    if(p_delet(n,key,s)==1)
	    			        n--;
	    		    }
	    	    }
	    	    break;
		    
	        case 6:
	    	    printf("\n\tRoll no.   Name \tMarks");
	    	    if(bin(n,s)==1)		
	    		    n--;
	    	    break; 
	    }
	}while(ch!=0);
	printf("\n");
	return 0;
}

int size()
{
	int n;
	printf("\n\tEnter the no. of students : \t");
	scanf("%d",&n);
	if(n<=0||n>10)
	{
		printf("\n\tINVALID Size");
		n=size();
	}
	return n;
}
void create(int n,struct student s[10])
{
	int i,j;
	for (i=0;i<n;i++)
	{
	    s[i].del=0;
	    printf("\n\tEnter the roll no. : \t");
	    scanf("%d",&s[i].rno);
	    for (j=0;j<i;j++)
	    {
	        if (s[i].rno==s[j].rno)
	        {
	  	        printf("\n\tRoll no. already assigned. Please enter new roll no. : \t");
	  	        scanf("%d",&s[i].rno);
	  	        j=-1;
	        }
	    }
	    printf("\n\tEnter Name : \t");
	    scanf("%s",s[i].name);
	    printf("\n\tEnter Marks : \t");
	    scanf("%d",&s[i].marks);
	}
}

void add(int n,struct student s[10])
{
	int i,j;
	for (i=n-1;i<n;i++)
	{
	    s[i].del=0;
	    printf("\n\tEnter the roll no. : \t");
	    scanf("%d",&s[i].rno);
	    for (j=0;j<i;j++)
	    {
	        if (s[i].rno==s[j].rno)
	        {
	  	        printf("\n\tRoll no. already assigned. Please enter new roll no. : \t");
	  	        scanf("%d",&s[i].rno);
	  	        j=-1;
	        }
	    }
	    printf("\n\tEnter Name : \t");
	    scanf("%s",s[i].name);
	    printf("\n\tEnter Marks : \t");
	    scanf("%d",&s[i].marks);
	}
	printf("\n____________________________________________________________________\n");
	printf("\n\tRoll no.   Name \tMarks");
	display(n,s);
}

void display(int n,struct student s[10])
{
	int i;
	for (i=0;i<n;i++)
	{
	    if (s[i].del==0)
		    printf("\n\t%d\t   %s\t%d",s[i].rno,s[i].name,s[i].marks);
	}
}

void search(int n,int key,struct student s[10])
{
	int i;
	for (i=0;i<n;i++)
	{
	    if (s[i].del==0)
	    {
		    if (key==s[i].rno)
		    {
		        printf("\n\tRoll no.   Name \tMarks");
		        printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		        break;
		    }
	    }
	}
	if (i==n)
	    printf("\n\tRecords not found\n");
}

void update(int n,int key,struct student s[10])
{
	int i,j;
	for (i=0;i<n;i++)
	{
	    if (s[i].del==0)
	    {
		    if (key==s[i].rno)
		    {
		        printf("\n\tRoll no.   Name \tMarks");
		        printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		        printf("\n\tEnter the Roll no. , Name & Marks of student :\n\t");
		        s[i].del=0;
		        scanf("%d%s%d",&s[i].rno,s[i].name,&s[i].marks);
		        for (j=0;j<n;j++)
	            {
	                if (j!=i)
	  	                if (s[i].rno==s[j].rno)
	  	                {
	  	                    printf("\n\tRoll no. already assigned. Please enter new roll no. : \t");
	  	                    scanf("%d",&s[i].rno);
	  	                    j=-1;
	                    }
	            }  
		        break;
		    }
	    }
	}
	if (i==n)
	    printf("\n\tRecords not found to update\n");
	    
    printf("\n_________________________________________________________\n");
	printf("\n\tRoll no.   Name \tMarks");
	display(n,s);
}

void delet(int n,int key,struct student s[10])
{
	int i;
	for (i=0;i<n;i++)
	{
	    if (s[i].del==0)
	    {
	    	if (key==s[i].rno)
		    {
		        printf("\n\t-----------------------------");
		        printf("\n\tRoll no.   Name \tMarks");
		        printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		        printf("\n\t-----------------------------");
		        printf("\n\tAre u sure? u want to delete ?");
		        printf("\n\t1.YES\n\t2.NO \t");
		        scanf("%d",&s[i].del);
		        if (s[i].del==1)
		            s[i].del=1;
		        else
		            s[i].del=0;
		            break;
		    }
	    }
	}
}

int p_delet(int n,int key,struct student s[10])
{
	int i,j,r=0;
	for (i=0;i<n;i++)
	{
	    if(s[i].del==0)
	    {
		    if (key==s[i].rno)
		    {
		        printf("\n\t-----------------------------");
		        printf("\n\tRoll no.   Name \tMarks");
		        printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		        printf("\n\t-----------------------------");
		        printf("\n\tAre u sure? u want to delete ?");
		        printf("\n\t1.YES\n\t2.NO \t");
		        scanf("%d",&j);
		        if (j==1)
		        {
		            r=1;
			        for(j=i;j<n-1;j++)
			        {
			            s[j].rno=s[j+1].rno;
			            strcpy(s[j].name,s[j+1].name);
			            s[j].marks=s[j+1].marks;
			            s[j].del=s[j+1].del;
			        }
		        }
		        break;
		    }
	    }
	}
	return r;
}

int bin(int n,struct student s[10])
{
	int i,j,r=0,key;
	for (i=0;i<n;i++)
	{
	    if (s[i].del==1)
		    printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
	}
	printf("\n\tDo u want to : ");
	printf("\n\t1.Restore details\n\t2.Delete permanently\n\t0.Exit \t ");
	scanf("%d",&i);
	
    if(i==1)		
    {
	    printf("\n\tEnter roll no. u want to restore : \t");
	    scanf("%d",&key);
	    for (i=0;i<n;i++)
	    {
	        if (s[i].del==1)
	        {
	    	    if (key==s[i].rno)
		        {
		            printf("\n\t------------------------------");
		            printf("\n\tRoll no.   Name \tMarks");
		            printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		            printf("\n\t------------------------------");
		            printf("\n\tAre u sure? u want to restore ?");
		            printf("\n\t1.YES\n\t2.NO \t");
		            scanf("%d",&s[i].del);
		            if (s[i].del==1)	
		                s[i].del=0;
		            else 				
		                s[i].del=1;
		                break;
		        }
	        }
	    }
	    if (i==n)
		    printf("\n\tRoll NO. is not present for restoring.");
    }
    
    else if(i==2)
    {
	    for (i=0;i<n;i++)
	    {
	        if(s[i].del==1)
	        {
		        if (key==s[i].rno)
		        {
		            printf("\n\t-----------------------------");
		            printf("\n\tRoll no.   Name \tMarks");
		            printf("\n\t%d\t   %s\t  %d",s[i].rno,s[i].name,s[i].marks);
		            printf("\n\t-----------------------------");
		            printf("\n\tAre u sure? u want to delete ?");
		            printf("\n\t1.YES\n\t2.NO \t");
		            scanf("%d",&j);
		            if (j==1)
		            {
			            r=1;
			            for(j=i;j<n-1;j++)
			            {
			                s[j].rno=s[j+1].rno;
			                strcpy(s[j].name,s[j+1].name);
			                s[j].marks=s[j+1].marks;
			                s[j].del=s[j+1].del;
			            }
		            }
		            break;
		        }
	        }
	    }
    }
    return r;
}
