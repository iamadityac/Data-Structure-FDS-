#include<stdio.h>
#include<stdlib.h>

int siz(int *,int *);

void acc(int [5][5],int,int );
void ptr_acc(int *,int ,int );

void disp(int [5][5],int,int);
void ptr_disp(int *,int ,int );

void add(int [5][5],int [5][5],int,int);
void ptr_add(int *,int *,int,int);

void sub(int [5][5],int [5][5],int,int);
void ptr_sub(int *,int *,int,int);

void trans(int [5][5],int,int);
void ptr_trans(int *,int ,int );

void multi(int[5][5],int[5][5],int[5][5],int,int,int,int);
void ptr_multi(int *,int *,int *,int,int,int,int);

void sp(int[5][5],int,int);
void ptr_sp(int *,int ,int );

int main()
{
	int m1[5][5],m2[5][5],m3[5][5],*mat1,*mat2,*mat3,r1,r2,c1,c2,i,j,k,s,ptr;
	printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
	for(s=2;s==2;)
	{
	    printf("\n\t\t**MATRIX OPERATIONS**\n\n");
	    
	    do
        {
            printf("\n----------------------------------------------------------");
            printf("\n\tDo u want to perform : ");
            printf("\n\t1: Without Pointer\n\t2: With Pointer \t");
            scanf("%d",&ptr);
            
            switch(ptr)
            {
                case 1:
                    printf("\n\tMatrix 1:");
	                siz(&r1,&c1);
	                acc(m1,r1,c1);
	
	                printf("\n\tMatrix 2:");
	                siz(&r2,&c2);
	                acc(m2,r2,c2);
	
	                printf("\n\tMatrix 1:\n");
	                disp(m1,r1,c1);
	                printf("\n\tMatrix 2:\n");
	                disp(m2,r2,c2);

                    do
                    {
                        printf("\n--------------------------------------------------------------------------------------------");
                        printf("\n\tchoose the operation u want to perform.....\n");
                        printf("\t1.Addition\n\t2.Subtraction\n\t3.Transpose\n\t4.Multiplication\n\t5.Saddle point\n\t6.Exit\t");
                        printf("\n\tEnter ur choise..... \t");
                        scanf("%d",&s);
                        switch(s)
                        {
                            case 1:
                                if(r1==r2&&c1==c2)
                                {
                                    printf("\n\tAddition of two matrix is :\n");
                                    add(m1,m2,r1,c1);
                                }
                                else
                                    printf("\n\tAddition cant be performed on given matrices");
                                break;
                
                            case 2:
                                printf("\n\tWhich subtraction u want :\n\t1.A-B\n\t2.B-A\t");
                                scanf("%d",&s);
                                if(s==1)
                                {
                                    if(r1==r2&&c1==c2)
                                    {
                                        printf("\n\tSubtraction A-B matrix is :\n");
                                        sub(m1,m2,r1,c1);
                                    }
                                    else
                                        printf("\n\tSubtraction cant be performed on given matrices");
                                }
                                else
                                {
                                    if(r1==r2&&c1==c2)
                                    {
                                        printf("\n\tSubtraction B-A matrix is :\n");
                                        sub(m2,m1,r1,c1);
                                    }
                                    else
                                        printf("\n\tSubtraction cant be performed on given matrices");    
                                }
                                break;
                
                            case 3:
                                printf("\n\tWhich matrix's transpose u want :\n\t1.Matrix 1\n\t2.Matrix 2\t");
                                scanf("%d",&s);
                                if(s==1)
                                {
                                    printf("\n\tTranspose of matrix 1:\n");
                                    trans(m1,r1,c1);
                                }
                                else
                                {
                                    printf("\n\tTranspose of matrix 2:\n");
                                    trans(m2,r2,c2);
                                }
                                break;
                    
                            case 4:
                                printf("\n\tWhich multiplication u want :\n\t1.A*B\n\t2.B*A\t");
                                scanf("%d",&s);
                                if (s==1)
				                {
    			                if (c1==r2)
    			                {
    			                    multi(m1,m2,m3,r1,c1,r2,c2);
    			                    printf("\n\tMultiplication is :\n");
    			                    disp(m3,r1,c2);
    			                }  
    			                else 
    			                printf("\nMultiplication can't be performed on given matrices ");
    			                }
    			                else
				                {
    			                    if (c2==r1)
    			                    {
    			                        multi(m2,m1,m3,r2,c2,r1,c1);
    			                        printf("\n\tMultiplication is :\n");
    			                        disp(m3,r2,c1);
    			                    }  
    			                    else 
    			                    printf("\nMultiplication can't be performed on given matrices ");
    			                }
                                break;
                    
                            case 5:
                                printf("\n\tMatrix1 :");
    			                if(r1==c1)
    			                {
    			                    sp(m1,r1,c1);
    			                }
    			                else
    			                { 
    			                    printf("\n\tINVALID condition for finding saddle point");
    			                }
    			                printf("\n\n\tMatrix2 :");
    			                if(r2==c2)
    			                {
    			                    sp(m2,r2,c2);
    			                }
    			                else
    			                { 
    			                    printf("\n\tINVALID condition for finding saddle point");
    			                }
    			                printf("\n");
    			                break;
                                                        
                            default:
                                break;
                        }
                    }while(s!=6);
                    break;
                case 2:
                    printf("\n\tMATRIX 1:\n");
	                siz(&r1,&c1);
	                mat1=(int *)malloc(sizeof(int)*r1*c1);
	                ptr_acc(mat1,r1,c1);
	
	                printf("\n\tMATRIX 2:\n");
	                siz(&r2,&c2);
	                mat2=(int *)malloc(sizeof(int)*r2*c2);
	                ptr_acc(mat2,r2,c2);
	
	                printf("\n\tMatrix 1:\n");
                    ptr_disp(mat1,r1,c1);
                    printf("\n\tMatrix 2:\n");
	                ptr_disp(mat2,r2,c2);
	                
	                do
                    {
                        printf("\n--------------------------------------------------------------------------------------------");
                        printf("\n\tchoose the operation u want to perform.....\n");
                        printf("\t1.Addition\n\t2.Subtraction\n\t3.Transpose\n\t4.Multiplication\n\t5.Saddle point\n\t6.Exit\t");
                        printf("\n\tEnter ur choise..... \t");
                        scanf("%d",&s);
                        switch(s)
                        {
                            case 1:
                                if(r1==r2&&c1==c2)
                                {
                                    printf("\n\tAddition of two matrix is :\n");
                                    ptr_add(mat1,mat2,r1,c1);
                                }    
                                else
                                    printf("\n\tAddition cant be performed on given matrices");
                                break;
                
                            case 2:
                                printf("\n\tWhich subtraction u want :\n\t1.A-B\n\t2.B-A\t");
                                scanf("%d",&s);
                                if(s==1)
                                {
                                    if(r1==r2&&c1==c2)
                                    {
                                        printf("\n\tSubtraction A-B matrix is :\n");
                                        ptr_sub(mat1,mat2,r1,c1);
                                    }
                                    else
                                        printf("\n\tSubtraction cant be performed on given matrices");
                                }
                                else
                                {
                                    if(r1==r2&&c1==c2)
                                    {
                                        printf("\n\tSubtraction B-A matrix is :\n");
                                        ptr_sub(mat2,mat1,r1,c1);
                                    }
                                    else
                                        printf("\n\tSubtraction cant be performed on given matrices");
                                }
                                break;
                
                            case 3:
                                printf("\n\tWhich matrix's transpose u want :\n\t1.Matrix 1\n\t2.Matrix 2\t");
                                scanf("%d",&s);
                                if(s==1)
                                {
                                    printf("\n\tTranspose of matrix 1:\n");
                                    ptr_trans(mat1,r1,c1);
                                }
                                else
                                {
                                    printf("\n\tTranspose of matrix 2:\n");
                                    ptr_trans(mat2,r2,c2);
                                }
                                break;
                    
                            case 4:
                                printf("\n\tWhich multiplication u want :\n\t1.A*B\n\t2.B*A\t");
                                scanf("%d",&s);
                                if (s==1)
				                {
    			                if (c1==r2)
    			                {
    			                    mat3=(int *)malloc(sizeof(int)*r1*c2);
    			                    ptr_multi(mat1,mat2,mat3,r1,c1,r2,c2);
    			                    printf("\n\tMultiplication is :\n");
    			                    ptr_disp(mat3,r1,c2);
    			                }  
    			                else 
    			                printf("\nMultiplication can't be performed on given matrices ");
    			                }
    			                else
				                {
    			                    if (c2==r1)
    			                    {
    			                        mat3=(int *)malloc(sizeof(int)*r1*c2);
    			                        ptr_multi(mat2,mat1,mat3,r2,c2,r1,c1);
    			                        printf("\n\tMultiplication is :\n");
    			                        ptr_disp(mat3,r2,c1);
    			                    }  
    			                    else 
    			                    printf("\nMultiplication can't be performed on given matrices ");
    			                }
                                break;
                    
                            case 5:
                                printf("\n\tMatrix1 :");
    			                if(r1==c1)
    			                {
    			                    ptr_sp(mat1,r1,c1);
    			                }
    			                else
    			                { 
    			                    printf("\n\tINVALID condition for finding saddle point");
    			                }
    			                printf("\n\n\tMatrix2 :");
    			                if(r2==c2)
    			                {
    			                    ptr_sp(mat2,r2,c2);
    			                }
    			                else
    			                { 
    			                    printf("\n\tINVALID condition for finding saddle point");
    			                }
    			                printf("\n");
    			                break;
                                                        
                            default:
                                break;
                        }
                    }while(s!=6);
            }
            printf("\n\tSELECT OPTIONS :\n\t1.Perform another Opreration\n\t2.Enter New matrixs\n\t0.EXIT\t\t");
            scanf("%d",&s);
            printf("\n\n _____________________________________________________________________________________________\n");
            printf(" _____________________________________________________________________________________________\n\n");
        }while(s==1); 
    }
}

int siz(int *r,int *c)
{
    printf("\n\tEnter the size of row:\n\t");
	scanf("%d",r);
	printf("\tEnter the size of column:\n\t");
	scanf("%d",c);
	if ((*r<0||*c<0)||(*r>5||*c>5))
	{
	    printf("\n\tInvalid size.Enter again\n");
	    siz(r,c);
	}
	else
	return 0;
}                            
                  
void acc(int m[5][5],int r,int c)
{
    int i,j;
	printf("\n\tenter the elements of matrix\n");
	for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        printf("\telement[%d][%d]=",i,j);
	        scanf("%d",&m[i][j]);
	    }
	}
}

void ptr_acc(int *m,int r,int c)
{
    int i,j;
	printf("\n\tenter the elements of matrix\n");
	for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        printf("\telement[%d][%d]=",i,j);
	        scanf("%d",(m+(i*c)+j));
	    }
	}
}

void disp(int m[5][5],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",m[i][j]);
	        else
	        printf("  %d ",m[i][j]);
	    }
	    printf("\n");
	}
}

void ptr_disp(int *m,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",*(m+(i*c)+j));
	        else
	        printf("  %d ",*(m+(i*c)+j));
	    }
	    printf("\n");
	}
}		
	
void add(int a[5][5],int b[5][5],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",a[i][j]+b[i][j]);
	        else
	        printf("  %d ",a[i][j]+b[i][j]);
	    }
	    printf("\n");
	}
}

void ptr_add(int *a,int *b,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",*(a+(i*c)+j)+*(b+(i*c)+j));
	        else
	        printf("  %d ",*(a+(i*c)+j)+*(b+(i*c)+j));
	    }
	    printf("\n");
	}
}

void sub(int a[5][5],int b[5][5],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",a[i][j]-b[i][j]);
	        else
	        printf("  %d ",a[i][j]-b[i][j]);
	    }
	    printf("\n");
	}
}

void ptr_sub(int *a,int *b,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",*(a+(i*c)+j)-*(b+(i*c)+j));
	        else
	        printf("  %d ",*(a+(i*c)+j)-*(b+(i*c)+j));
	    }
	    printf("\n");
	}
}

void trans(int m[5][5],int r,int c)
{
    int i,j;
    for(i=0;i<c;i++)
	{
	    for(j=0;j<r;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",m[j][i]);
	        else
	        printf("  %d ",m[j][i]);
	    }
	    printf("\n");
	}
}

void ptr_trans(int *m,int r,int c)
{
    int i,j;
    for(i=0;i<c;i++)
	{
	    for(j=0;j<r;j++)
	    {
	        if(j==0)
	        printf("\t  %d ",*(m+(j*c)+i));
	        else
	        printf("  %d ",*(m+(j*c)+i));
	    }
	    printf("\n");
	}
}

void multi(int a[5][5],int b[5][5],int d[5][5],int r1,int c1,int r2,int c2)
{
    int i,j,sum,z;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            sum=0;
            for(z=0;z<r2;z++)
                sum+=a[i][z]*b[z][j];
            d[i][j]=sum;
         }
     }
}

void ptr_multi(int *a,int *b,int *d,int r1,int c1,int r2,int c2)
{
    int i,j,sum,z;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            sum=0;
            for(z=0;z<r2;z++)
                sum+= *(a+i*c1+z) * *(b+z*c2+j);
            *(d+i*c2+j)=sum;
         }
     }
}  

void sp(int m[5][5],int r,int c)
{
    int i,j,k,l;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            l=0;
	        for(k=0;k<c;k++)
	        {
		        if( (m[i][j]<=m[i][k]) && (m[i][j]>=m[k][j]) )
		            l++;
	        }
	        if (l==r)
	        {
	            printf("\n\tSaddle point is %d",m[i][j]);
	            l=0;
	            break;
	        }
	    }
	}
	if(l!=0)
	printf("\n\tSaddle point is not present in given matrix.");
}

void ptr_sp(int *m,int r,int c)
{
    int i,j,k,l;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            l=0;
	        for(k=0;k<c;k++)
	        {
		        if( (*(m+(i*c)+j)<=*(m+(i*c)+k)) && (*(m+(i*c)+j)>=*(m+(k*c)+j)) )
		            l++;
	        }
	        if (l==r)
	        {
	            printf("\n\tSaddle point is %d",*(m+(i*c)+j));
	            l=0;
	            break;
	        }
	    }
	}
	if(l!=0)
	printf("\n\tSaddle point is not present in given matrix.");
}                  
    

