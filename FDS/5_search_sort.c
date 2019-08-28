#include<stdio.h>
#include<string.h>

struct string
{
	char str[10];
};

int size();
void disp(struct string[],int);
void sel_sort(struct string [],int,int);
void bub_sort(struct string [],int,int);
void bin_search(struct string [],int ,int ,char [],int);
void r_bin_search(struct string [],int ,int ,char [],int);

int main()
{
	int cnt,n,min,max,ch,fl;	
	struct string s[10];
	char key[10];
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	printf("\n\t\t\t**Searching & Sorting**\n\n");
	n=size();
	
	for (cnt=0;cnt<n;cnt++)
	{
		printf("\n\tEnter the string %d : \t",cnt+1);
		scanf("%s",s[cnt].str);
	}
									
	do
	{
	    printf("\n------------------------------------------------------------------");
		printf("\n\tDo u want perform :");
		printf("\n\t1.Sort\n\t2.Search\n\t0.Exit \t");
		scanf("%d",&ch);
		if(ch==1)
			fl=1;
		else
			fl=0;
		switch(ch)
		{
			case 1:
				do
				{
				    printf("\n------------------------------------------------------------------");
					printf("\n\n\tWhich sort u want 2 perform : ");
					printf("\n\t1:ASCENDING order using Bubble sort\n\t2:DESCENDING order using Selection sort\n\t0.Exit : \t");
					scanf("%d",&cnt);
					switch(cnt)
					{
						case 1:
							printf("\n\t\t**Bubble sort**\n");
							printf("\n\tData is sorted in ASCENDING order :\n");
							bub_sort(s,n,fl);
							break;
						
						case 2:
							printf("\n\t\t**Selection sort**\n");
							printf("\n\tData is sorted in DESCENDING order :\n");
							sel_sort(s,n,fl);
							break;
					}
				}while(cnt!=0);
				break;
				
			case 2:
				do
				{
				    printf("\n--------------------------------------------------------------------");
					printf("\n\n\tWhich search u want to perform : ");
					printf("\n\t1:Binary_search using ASCENDING ordered data\n\t2:Recursive_Binary_search using DESCENDING ordered data\n\t0.Exit : \t");
					scanf("%d",&cnt);
					min=0;	max=n-1;
					switch(cnt)
					{
						case 1:
						    printf("\n\t\t**Binary search**\n");
						    printf("\n\tEnter the string u want to search : \t");	
					        scanf("%s",key);
					        bub_sort(s,n,fl);
					        disp(s,n);
							bin_search(s,min,max,key,n);
							break;
				
						case 2:
						    printf("\n\t\t**Recursive Binary search**\n");
						    printf("\n\tEnter the string u want to search : \t");	
					        scanf("%s",key);
					        sel_sort(s,n,fl);
					        disp(s,n);
							r_bin_search(s,min,max,key,n);
							break;
					}
				}while(cnt!=0);
				break;
		}
	}while(ch!=0);
}

int size()
{
	int n;
	printf("\n\tEnter No. of strings u want to enter : \t");
	scanf("%d",&n);
	if(n<=0||n>10)
	{
		printf("\tINVALID Size\n");
		n=size();
	}
	return n;
}

void disp(struct string s[10],int n)
{
	int i; 
	printf("\n\tData is sorted as follows : \n\t");
	for(i=0;i<n;i++)
		 printf("  %s",s[i].str);
}

void sel_sort(struct string s[10],int n,int fl)
{
	int i,j,cnt,min;
	char temp[10];
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(strcmp(s[min].str,s[j].str)<0)
			{
				min=j;
			}
		}
		if(i!=min)
		{
			strcpy(temp,s[min].str);
			strcpy(s[min].str,s[i].str);
			strcpy(s[i].str,temp);
		}
		if(fl==1)
		{
			printf("\n\tPass #%d :",i+1);
			for(cnt=0;cnt<n;cnt++)
	  		printf("  %s",s[cnt].str);
	  	}
	}
}

void bub_sort(struct string s[10],int n,int fl)
{
	int i,j,cnt;
	char temp[10];
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(s[j].str,s[j+1].str)>0)
			{
				strcpy(temp,s[j].str);
				strcpy(s[j].str,s[j+1].str);
				strcpy(s[j+1].str,temp);
			}
		}
		if(fl==1)
		{
			printf("\n\tPass #%d :",i);
			for(cnt=0;cnt<n;cnt++)
	  		printf("  %s",s[cnt].str);
	  	}
	}
}

void bin_search(struct string s[10],int min,int max,char key[10],int n)
{
	int mid;
	
	for(;min<=max;)
	{
		mid=(min+max)/2;
		if(strcmp(s[mid].str,key)==0)
		{
			printf("\n\n\tstring '%s' is present at position %d",key,mid+1);
			break;
		}
		else if(strcmp(s[mid].str,key)>0)
			max=mid-1;
		else if(strcmp(s[mid].str,key)<0)
			min=mid+1;
	}
	if(min>max)
		printf("\n\n\tString is not Present");	
}

void r_bin_search(struct string s[10],int min,int max,char key[10],int n)
{
    int mid;
	
	mid=(min+max)/2;
	
	if(min>max)			
	{
		printf("\n\n\tString is not Present");
		return;
	}
	if(strcmp(s[mid].str,key)==0)	
	{
		printf("\n\n\tString '%s' is Present at position %d",key,mid+1);
		return;
	}
	else if(strcmp(s[mid].str,key)<0)	
	{
		r_bin_search(s,min,mid-1,key,n);
		return;
	}
	else if(strcmp(s[mid].str,key)>0)	
	{
		r_bin_search(s,mid+1,max,key,n);
		return;
	}
}



