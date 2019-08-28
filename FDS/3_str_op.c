#include<stdio.h>
#include<stdlib.h>

void accept(char [],char []);
void ptr_accept(char *,char *);

int length(char []);
int ptr_length(char *);

void copy(char [],char []);
void ptr_copy(char *,char *);
  
int compare(char [],char []);
int ptr_compare(char *,char *);

void reverse(char [],char []);
void ptr_reverse(char *,char *);
  
void palin(char [],char []);
void ptr_palin(char *,char *);

void concat(char [],char []);
void ptr_concat(char *,char *);
  
void substr(char [],char []);
void ptr_substr(char *,char *);

int main()
{
	int len1,len2,ch,pointer;
	char str1[10], str2[10], *s1, *s2;
    printf("\n\t\t\u1368 Developed By Aditya Choudhari (25007) \u1368\n");
  
    printf("\n\t\t\t**STRING OPERATIONS**");
    
    do 
    {
        printf("\n------------------------------------------------------------\n");
        printf("\n\tDo u want to perform : ");
        printf("\n\t1:Without Pointer\n\t2:With pointer\n\t0:Exit \t");
        scanf("%d",&pointer);
   
        switch(pointer)
        {  
            case 1:  
		        do 
		        {
		            printf("\n\n------------------------------------------------------------\n");
		            printf("\n\tWhich operation u want 2 perform? :");
		            printf("\n\t1:Length\n\t2:Copy\n\t3:Compare\n\t4:Reverse\n\t5:Palindrome\n\t6:Concatanation\n\t7:Substring\n\t0:Exit :\t");
		            scanf("%d",&ch);
	
		            switch(ch)
		            {
		                case 1:
			                printf("\n\n\t**Length**\n");
			                accept(str1,str2);
			                len1=length(str1);
			                printf("\n\tLength of string 1 : %d ",len1);
			                len2=length(str2);
			                printf("\n\tLength of string 2 : %d ",len2);
			                break;
			                
		                case 2:
			                printf("\n\n\t**Copy**\n");
			                accept(str1,str2);
			                copy(str1,str2);
			                printf("\n\tAfter Copying string 1 into string 2,");
				            printf("\n\tstring 2 becomes :");
				            printf("\t%s\n",str1);
			                break;
			                
		                case 3:
			                printf("\n\n\t**Compare\n**");
			                accept(str1,str2);
			                compare(str1,str2)?printf("\n\tString 1 is EQUAL to String 2.\n"):printf("\n\tString 1 is NOT EQUAL to String 2.\n");
			                break;
			                
		                case 4:
			                printf("\n\n\t**Reverse**\n");
			                printf("\n\tEnter the String : \t");
			                scanf("%s",str1);
			                reverse(str1,str2);
			                printf("\n\n\tafter reversing string \n\tstring becomes :\t %s",str2);
			                break;
			                
		                case 5:
			                printf("\n\n\t**Palindrome**\n");
			                printf("\n\tEnter the String : \t");
			                scanf("%s",str1);
			                palin(str1,str2);
			                break;
			                
		                case 6:
			                printf("\n\n\t**Concatenation**\n");
			                accept(str1,str2);
			                concat(str1,str2);
			                printf("\n\tString 1 & 2 Concatenation is :  %s",str1);
			                break;
			                
		                case 7:
		                    printf("\n\n\t**Substring**\n");
			                accept(str1,str2);
			                substr(str1,str2);
			                break;
		            }
		        }while(ch!=0);
  	            break;
  	            
            case 2:	
		        do 
		        {
		            printf("\n\n------------------------------------------------------------\n");
		            printf("\t\t\t**OPERATIONS**");
		            printf("\n\t1:Length\n\t2:Copy\n\t3:Compare\n\t4:Reverse\n\t5:Palindrome\n\t6:Concatanation\n\t7:Substring\n\t0:Exit :\t");
		            scanf("%d",&ch);
		
		            s1=(char *)malloc(sizeof(char)*4);
		            s2=(char *)malloc(sizeof(char)*4);
		
		            switch(ch)
		            {
		                case 1:
			                printf("\n\n\t**Length**\n");
			                ptr_accept(s1,s2);
			                len1=ptr_length(s1);
			                printf("\n\tLength of string 1 : %d ",len1);
			                len2=ptr_length(s2);
			                printf("\n\tLength of string 2 : %d ",len2);
			                break;
			                
		                case 2:
			                printf("\n\n\t**Copy**\n");
			                ptr_accept(s1,s2);
			                copy(s1,s2);
			                printf("\n\tAfter Copying string 1 into string 2,");
				            printf("\n\tstring 2 becomes :");
				            printf("\t%s\n",s1);
			                break;
			
		                case 3:
			                printf("\n\n\t**Compare**\n");
			                ptr_accept(s1,s2);
			                ptr_compare(s1,s2)?printf("\n\tString 1 is EQUAL to String 2.\n"):printf("\n\tString 1 is NOT EQUAL to String 2.\n");
			                break;
			                
		                case 4:
			                printf("\n\n\t**Reverse**\n");
			                printf("\n\tEnter the String : \t");
			                scanf("%s",s1);
			                ptr_reverse(s1,s2);
			                printf("\n\n\tafter reversing string\n\tstring becomes :\t %s",s2);
			                break;
			                
		                case 5:
			                printf("\n\n\t**Palindrome**\n");
			                printf("\n\tEnter the String : \t");
			                scanf("%s",s1);
			                ptr_palin(s1,s2);
			                break;
			                
		                case 6:
			                printf("\n\n\t**Concatenation**\n");
			                ptr_accept(s1,s2);
			                ptr_concat(s1,s2);
			                printf("\n\tString 1 & 2 Concatenation is :  %s",s1);
			                break;
			                
		                case 7:
		                    printf("\n\n\t**Substring**\n");
			                ptr_accept(s1,s2);
			                ptr_substr(s1,s2);
			                break;
		            }
		        }while(ch!=0);
  	            break;
        }		
    }while(pointer!=0);
    printf("\n");
    return 0;
}

void accept(char str1[10],char str2[10])		
{
	printf("\n\tEnter the String 1 : \t");
	scanf("%s",str1);
	printf("\n\tEnter the String 2 : \t");
	scanf("%s",str2);
}

void ptr_accept(char *s1,char *s2)
{
	printf("\n\tEnter the String 1 : \t");
	scanf("%s",s1);
	printf("\n\tEnter the String 2 : \t");
	scanf("%s",s2);
}

int length(char str1[10])						
{
	int i;
	for (i=0;str1[i]!='\0';i++);
	    return i;
}

int ptr_length(char *s1)
{
	int i;
	for (i=0;*(s1+i)!='\0';i++);
	    return i;
}

void copy(char str1[10],char str2[10])			
{
	int i,len1;
	len1=length(str1);
	for(i=0;i<len1+1;i++)
	{
	  str2[i]=str1[i];
	}
}
void ptr_copy(char *s1,char *s2)
{
	int i,len1;
	len1=ptr_length(s1);
	for(i=0;i<len1+1;i++)
	{
	    *(s2+i)=*(s1+i);
	}
}

int compare(char str1[10],char str2[10])		
{
	int i,k=0,len1;
	len1=length(str1);
	for (i=0;i<=len1;i++)
	{
	    if(str1[i]!=str2[i])
	    k=1;
	}
	if (i==len1+1&&k!=1)
	    return 1;
	else
	    return 0;
}

int ptr_compare(char *s1,char *s2)
{
	int i,k=0,len1;
	len1=ptr_length(s1);
	for (i=0;i<=len1;i++)
	{
	    if(*(s1+i)!=*(s2+i))
	    k=1;
	}
	if (i==len1+1&&k!=1)
	    return 1;
	else
	    return 0;
}

void reverse(char str1[10],char str2[10])
{
	int i,k=0,len1;
	len1=length(str1);
	for(i=len1-1;i>=0;i--)
	{
	  str2[k]=str1[i];
	  k++;
	}
	str2[k]='\0';
}

void ptr_reverse(char *s1,char *s2)
{
	int i,k=0,len1;
	len1=ptr_length(s1);
	for(i=len1-1;i>=0;i--)
	{
	  *(s2+k)=*(s1+i);
	  k++;
	}
	*(s2+k)='\0';
}

void palin(char str1[10],char str2[10])			
{
    reverse(str1,str2);
    compare(str1,str2)?printf("\n\tString is PALINDROME"):printf("\n\tString is NOT Palindrome");
}

void ptr_palin(char *s1,char *s2)
{
    ptr_reverse(s1,s2);
    ptr_compare(s1,s2)?printf("\n\tString is PALINDROME"):printf("\n\tString is NOT Palindrome");
}

void concat(char str1[10],char str2[10])	
{
	int i,k=0,len1,len2;
	len1=length(str1);
	len2=length(str2);
	for(i=len1;i<len1+len2;i++)
	{
	    str1[i]=str2[k];
	    k++;
	}
	str1[len1+len2]='\0';
}

void ptr_concat(char *s1,char *s2)
{
	int i,k=0,len1,len2;
	len1=ptr_length(s1);
	len2=ptr_length(s2);
	for(i=len1;i<len1+len2;i++)
	{
	    *(s1+i)=*(s2+k);
	    k++;
	}
	*(s1+len1+len2)='\0';
}

void substr(char str1[10],char str2[10])		
{
	int len1,len2,i,j,k=0;
	len1=length(str1);
	len2=length(str2);
	for (i=0;i<len2;i++)
	{
		for (j=0;j<len1;j++)
		{
			if (str2[i]==str1[j])
			{
			    k++;
			    break;
			}
		}		
	}
	if (k>=len2)
	    printf("\n\tstring 2 is Substring of string 1 ");
	else 
	    printf("\n\tstring2 is not a substring of string1");	
}

void ptr_substr(char *s1,char *s2)
{
	int len1,len2,i,j,k=0;
	len1=ptr_length(s1);
	len2=ptr_length(s2);
	for (i=0;i<len2;i++)
	{
		for (j=0;j<len1;j++)
		{
			if (*(s2+i)==*(s1+j))
			{
			    k++;
			    break;
			}
		}		
	}
	if (k>=len2)
	    printf("\n\tstring 2 is Substring of string 1 ");
	else 
	    printf("\n\tstring 2 is not a substring of string 1");	
}

