#include<stdio.h>

struct student
{
	int rno,marks;
	char name[20];
};

void accept(int );
void display();
void search();
void update();
void delet();

int main()
{
	int choice;
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	printf("\n\t\t**File handling**\n\n");
	accept(1);
	do 
	{
	    printf("\n\n----------------------------MENU-----------------------------");
	    printf("\n\t1:Add\n\t2:Display\n\t3:Search\n\t4:Update\n\t5:Delete\n\t0:Exit \t");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	        case 1:
		        accept(0);
		        break;
		        
	        case 2:
		        display();
		        break;
		        
	        case 3:
		        search();
		        break;
		        
	        case 4:
		        update();
		        display();
		        break;
		        
	        case 5:
		        delet();
		        display();
		        break;
	    }
	}while(choice!=0);
	printf("\n");
	return 0;
}

void accept(int flag)
{
	FILE *fp;
	struct student s;
	int i,n;
	
	if(flag==1)
	    fp=fopen("rec.txt","w");	
	else
	    fp=fopen("rec.txt","a");	
	
	printf("\n\tEnter the no. of students >");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the Roll No. : \t");
		scanf("%d",&s.rno);
		printf("\tEnter Name : \t");
		scanf("%s",s.name);
		printf("\tEnter Marks :\t");
		scanf("%d",&s.marks);
	
		fprintf(fp,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
	}
	fclose(fp);
}

void display()
{
	FILE *fp;
	struct student s;
	
	fp=fopen("rec.txt","r");

	while(!feof(fp))
	{
		fscanf(fp,"\n\t%d\t\t%s\t\t%d",&s.rno,s.name,&s.marks);
		printf("\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
	}
	fclose(fp);
}

void search()
{
	FILE *fp;
	struct student s;
	int key,flag=0;
	
	fp=fopen("rec.txt","r");

	printf("\n\tEnter the Roll No. u want to Search : \t");
	scanf("%d",&key);
	while(!feof(fp))
	{
		fscanf(fp,"\n\t%d\t\t%s\t\t%d",&s.rno,s.name,&s.marks);
		if(s.rno==key)
		{
			printf("\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
			flag=1;
		}
	}
	if(flag!=1)
		printf("\n\tRecord not found");
	
	fclose(fp);
}

void update()
{
	FILE *fp,*ft;
	struct student s;
	int key,flag=0;
	
	fp=fopen("rec.txt","r");
	ft=fopen("temp.txt","w");

	printf("\n\tEnter the Roll No. u want to Update : \t");
	scanf("%d",&key);
	while(!feof(fp))
	{
		fscanf(fp,"\n\t%d\t\t%s\t\t%d",&s.rno,s.name,&s.marks);
		if(s.rno==key)
		{
			flag=1;
			printf("\n\tEnter the RollNo. : \t");
			scanf("%d",&s.rno);
			printf("\tEnter Name : \t");
			scanf("%s",s.name);
			printf("\tEnter Marks : \t");
			scanf("%d",&s.marks);
	
			fprintf(ft,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
			continue;
		}
		fprintf(ft,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
	}
	if(flag!=1)
		printf("\n\tRecord not found");
		
	fclose(fp);
	fclose(ft);
	
	remove("rec.txt");
	rename("temp.txt","rec.txt");
}

void delet()
{
	FILE *fp,*ft;
	struct student s;
	int key,flag=0;
	
	fp=fopen("rec.txt","r");
	ft=fopen("temp.txt","w");

	printf("\n\tEnter the Roll No. u  want to Delete : \t");
	scanf("%d",&key);
	while(!feof(fp))
	{
		fscanf(fp,"\n\t%d\t\t%s\t\t%d",&s.rno,s.name,&s.marks);
		if(s.rno==key)
		{
			flag=1;
			continue;
		}	
		fprintf(ft,"\n\t%d\t\t%s\t\t%d",s.rno,s.name,s.marks);
	}
	if(flag!=1)
		printf("\n\tRecord not found");
		
	fclose(fp);
	fclose(ft);
	
	remove("rec.txt");
	rename("temp.txt","rec.txt");
}

