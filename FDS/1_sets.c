#include<stdio.h>
int size();
void accept(int [],int);
void display(int [],int);
int member(int set[],int x,int n);
void un(int set1[],int set2[],int a,int b);
void inter(int set1[],int set2[],int a,int b);
int diff(int set1[],int set2[],int set [],int a,int b);

void main()
{
  int a[10],b[10],u,d1[10],d2[10],n1,n2,i,j,c,flag=0,s,c1=0,c2=0;
  printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
        
  for (s=2;s==2;)
  {
    printf("\n\t\tSET OPERATIONS\n");

	printf("\n\tSet A :");
	n1=size();
    accept(a,n1);
    
    printf("\n\tSet B :");
    n2=size();
    accept(b,n2);
    
    printf("\n\tThe Entered Sets are:\n\tA:- {");
    display(a,n1);
    printf("}\n");
    
    printf("\tB:- {");
    display(b,n2);
    printf("}\n");

    do
    {
        printf("\n\tChoose the operation u want to perform.....");
        printf("\n\t1.Union\n\t2.Intersection\n\t3.Difference\n\t4.Symmetrical Difference.");
        printf("\n\tEnter your choice:  ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
        printf("\tUNION of Two sets {A U B} is:\t{");
        un(a,b,n1,n2);
        printf("}\n");
        break;

        case 2:
        printf("\tINTERSECTION of the Two Sets is:\t{");
        inter(a,b,n1,n2);
        printf("}\n");
        break;

        case 3:
        do
        {
            printf("\n\tWhich difference u want : \n\t1.A-B\n\t2.B-A\t");
            scanf("%d",&s);
            if(s==1)
            {
                printf("\n\tDIFFERENCE {A-B} is:\t{");
                c1=diff(a,b,d1,n1,n2);
		        display(d1,c1);        
		        printf("}\n");
            }
            else
            {
                printf("\n\tDIFFERENCE {B-A} is:\t{");
                c2=diff(b,a,d2,n2,n1);
	            display(d2,c2);
                printf("}\n");
            }
            printf("\n\tDo u want difference of another sets :\n\t1.Yes\n\t2.No\t");
            scanf("%d",&s);
        }while(s==1);
        break;
    
        case 4:
        printf("\tThe Symmetrical Difference of sets A and B is:\t{");
	    c1=diff(a,b,d1,n1,n2);
        c2=diff(b,a,d2,n2,n1);
 		un(d1,d2,c1,c2);
		printf("}\n");
        break;
        }
        printf("\n\tEnter\n\t1.Perform another opreration\n\t2.New Sets\n\t0.EXIT\t");
        scanf("%d",&s);
    }while(s==1);
  }
}




int size()
{
    int i,j,n;
    printf("\n\tEnter the size of set : ");
    scanf("%d",&n);
    for(i=0;;i++)
    {
        if(n<0 || n>10)
        {
            printf("\tInvalid Entry.\n\tEnter Other Number:\t");
            scanf("%d",&n);
        }
        else if(n==0)
        {    
            printf("\n\tentered set is null set.\n\tenter size again:\t");
            scanf("%d",&n);
        }
        else 
        break;
    }
    return n;
}
void accept(int c[10],int n)
{
    int i,j;

    printf("\n\tEnter the Elements of set : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        for(j=0;j<i;j++)
        {
            if (c[j]==c[i])
             {
                printf("\tInvalid Entry.\n\tEnter Other Number:\t");
                i--;
             }
        }
    } 
}
  
void display(int c[10],int n)
{
	int i,j;
    for(i=0;i<n;i++)
    {
	    if(i!=(n-1))
		    printf("%d,",c[i]);
	    else
		    printf("%d",c[i]);
    }
}

int member(int set[],int x,int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
    {
	    if(x==set[i])
		{
			flag=0;	
			break;
		}
        else
		{
		  flag=1;
	    }
    }
    if(flag==0)
    { 
        return 0;
    }
    else 
	    return 1;
}

void un(int a[],int b[],int n1,int n2)
{
    int i,j,flag=0;
    for(i=0;i<n1;i++)
    { 
    	if (i==0)
    	printf(" %d",a[i]);
    	else
        printf(",%d",a[i]);
    }
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n1;j++)
        {
            if(b[i]==a[j])
            {
                flag=1;
                break;
            } 
            else 
            flag=0;
        }
        if (flag==0)
        printf(",%d",b[i]);
    }
}

void inter(int a[],int b[],int n1,int n2)
{
    int c,in[10],i,j;
    c=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(a[i]==b[j])
  	        {
  	            in[c]=a[i];
			    c++; 		
 		    }
        }
    }
    for(i=0;i<c;i++)
    {
	    if(i==(c-1))
	        printf("%d",in[i]);
	    else
	        printf("%d,",in[i]);
    }
}

int diff(int a[],int b[],int d[],int n1,int n2) 
{
    int c1,d1[10],i,j;
    c1=0;
    for(i=0;i<n1;i++)
    {
        if(member(b,a[i],n2))
        {
            d[c1]=a[i];
            c1++;
        }
    }
    return c1; 
}
