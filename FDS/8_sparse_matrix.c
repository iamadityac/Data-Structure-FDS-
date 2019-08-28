#include<stdio.h>
#define max 20

void acc(int [10][10],int ,int );
void disp(int [max][3]);
void convert(int [10][10],int ,int ,int [max][3]);
void trans(int [][3]);
void fast_trans(int [][3]);
void add(int [max][3],int [max][3]);

void main()
{
    int a[10][10],b[max][3],r,c,a1[10][10],b1[max][3],r1,c1,ch;
    printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
    printf("\n\t\t\t**Sparse Matrix**\n\n");
    
    printf("\n\tMatrix 1 :");
    printf("\n\tEnter the size of row & column: \t");
    scanf("%d%d",&r,&c);
    acc(a,r,c);
    convert(a,r,c,b);
    
    printf("\n\tMatrix 2 :");
    printf("\n\tEnter the size of row & column: \t");
    scanf("%d%d",&r1,&c1);
    acc(a1,r1,c1);
    convert(a1,r1,c1,b1);
    
    printf("\n\tSparse Matrix 1 : \n\t");
    disp(b);
    printf("\n\tSparse Matrix 2 : \n\t");
    disp(b1);
    
    do
    {
        printf("\n-------------------------------------------------------------\n");
		printf("\n\tWhich operation u want to perform?");
		printf("\n\t1.Addition\n\t2.Transpose\n\t0.Exit \t");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1:
		        if(r==r1 && c==c1)
		        {
		            printf("\n\tAddition of 2 sparse matrix is : \n\t");
		            add(b,b1);
		        }
		        else
		            printf("\n\tAddition cant be performed on given matrices...");
		        break;
		        
		    case 2:
		        printf("\n\tDo u want to perform : \n\t1.Simple/Slow transpose\n\t2.Fast transpose \t");
		        scanf("%d",&ch);
		        if(ch==1)
		        {
		            printf("\n\tWhich matrix's transpose u want :\n\t1.Sparse Matrix 1\n\t2.Sparse Matrix 2\t");
                    scanf("%d",&ch);
                    if(ch==1)
                    {
                        printf("\n\tTranspose of Sparse matrix 1:\n\t");
                        trans(b);
                    }
                    else
                    {
                        printf("\n\tTranspose of Sparse matrix 2:\n\t");
                        trans(b1);
                    }
                }
                else
		        {
		            printf("\n\tWhich matrix's transpose u want :\n\t1.Sparse Matrix 1\n\t2.Sparse Matrix 2\t");
                    scanf("%d",&ch);
                    if(ch==1)
                    {
                        printf("\n\tTranspose of Sparse matrix 1:\n\t");
                        fast_trans(b);
                    }
                    else
                    {
                        printf("\n\tTranspose of Sparse matrix 2:\n\t");
                        fast_trans(b1);
                    }
                }
		        break;
		}
	}while(ch!=0);
}

void acc(int a[10][10],int r,int c)
{
    int i,j;
    printf("\n\tEnter the elements of matrix : \t");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
}

void convert(int a[10][10],int r,int c,int b[max][3])
{
    int i,j,k=1;
    b[0][0]=r;
    b[0][1]=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
}

void disp(int b[max][3])
{
    int i,n;
    n=b[0][2];
    for(i=0;i<=n;i++)
        printf("%d   %d   %d\n\t",b[i][0],b[i][1],b[i][2]);
}            
    
void trans(int x[][3])
{
    int i,j,k,n,y[max][3];
    
    y[0][0]=x[0][1];
    y[0][1]=x[0][0];
    y[0][2]=x[0][2];
    k=1;
    n=x[0][2];
    
    for(i=0;i<x[0][1];i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==x[j][1])
            {
                y[k][0]=i;
                y[k][1]=x[j][0];
                y[k][2]=x[k][2];
                k++;
            }
        }
    }
    disp(y);
}
        
void fast_trans(int x[][3])
{
    int m,n,t,i,col_no,loc,total[max],index[max],y[max][3];
    
    m=y[0][1]=x[0][0];
    n=y[0][0]=x[0][1];
    t=y[0][2]=x[0][2];
    
    for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col_no=x[i][1];
        total[col_no]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];
    for(i=1;i<=t;i++)
    {
        col_no=x[i][1];
        loc=index[col_no];
        index[col_no]++;
        y[loc][0]=x[i][1];
        y[loc][1]=x[i][0];
        y[loc][2]=x[i][2];
    }
    disp(y);
}
    
void add(int b[max][3],int b1[max][3])
{
    int t,t1,i=0,j=0,k=0,sum[max][3];
    
    t=b[0][2];
    t1=b1[0][2];
    sum[0][0]=b[0][0];
    sum[0][1]=b[0][1];
    
    while(i<=t && j<=t1)
    {
        if(b[i][0] < b1[j][0])
        {
            sum[k][0]=b[i][0];
            sum[k][1]=b[i][1];
            sum[k][2]=b[i][2];
            k++;
            i++;
        }
        else if(b1[j][0] < b[i][0])
        {
            sum[k][0]=b1[j][0];
            sum[k][1]=b1[j][1];
            sum[k][2]=b1[j][2];
            k++;
            j++;
        }
        if(b[i][1] < b1[j][1])
        {
            sum[k][0]=b[i][0];
            sum[k][1]=b[i][1];
            sum[k][2]=b[i][2];
            k++;
            i++;
        }
        else if(b1[j][1] < b[i][1])
        {
            sum[k][0]=b1[j][0];
            sum[k][1]=b1[j][1];
            sum[k][2]=b1[j][2];
            k++;
            j++;
        }
        if(b[i][0]==b1[j][0]&&b[i][1]==b1[j][1])
        {
        	sum[k][0]=b[i][0];
        	sum[k][1]=b[i][1];
        	sum[k][2]=b[i][2]+b1[j][2];
        	k++;
        	i++;
        	j++;
    	}
    }
    while(i<=t)
    {
        sum[k][0]=b[i][0];
        sum[k][1]=b[i][1];
        sum[k][2]=b[i][2];
        i++;
        k++;

    }
    while(j<=t1)
    {
        sum[k][0]=b1[j][0];
        sum[k][1]=b1[j][1];
        sum[k][2]=b1[j][2];
        j++;
        k++;
    }
    sum[0][2]=k-1;
    disp(sum);
}  
