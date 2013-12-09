#include<stdio.h>
long int findmax(long int arr[],int size);
void eval(long int num);
int main()
{

    int T;
    scanf("%d",&T);
    long int input[T];

    int i=0;
    int k,j;
    long int num;
    long int max;
    while(i<T)
    {
              scanf("%ld",&input[i]);
              i++;
    }

    max=findmax(input,T);
    printf("%ld",max);

    short int checkprime[max+1];
        printf("I am here");
    memset(checkprime,0,sizeof(checkprime));
                   
    //Implementing Sieve of Eratosthenes
    checkprime[0]=checkprime[1]=1;
    int root=sqrt(max);

    for(j=2;j<=root;j++)
    {
                        if(!checkprime[j])
                        {
                            for(k=j*j;k<=max;k=k+j)
                            checkprime[k]=1;           
                        }
    }
    i=0;
    while(i<T)
    {
              num=input[i];
              if(checkSquare(num))
              printf("%d\n",0);
              else if(!checkprime[num])
              printf("%ld\n",(num-1));
              else
              eval(num);
              i++;
    }
     return 0;
}
long int findmax(long int arr[],int size)
{
     int i=1;
     long int max;
     max=arr[0];
     while(i<size)
     {
                  if(arr[i]>max)
                  max=arr[i];  
                  i++;
     }
     return max;
}
void eval(long int num)
{
     long int i=2;
     long int limit=num/2;
     long int num1,num2,mindiff;
     while(i<=limit)
     {
                    if((num%i)==0)
                    {
                                 limit=num/i;
                                 break;
                    }
                    i++;
     }
     num1=i;
     num2=num/i;
     mindiff=num2-num1;
     if(mindiff==1)
     {
                   printf("%d",1);
                   return;
     }
     i++;
     while(i<limit)
     {
                   
                    if((num%i)==0)
                    {
                                 num1=i;
                                 num2=num/i;
                                 limit=num2;
                                 if((num2-num1)<mindiff)
                                 {
                                                        mindiff=num2-num1;
                                                        if(mindiff==1)
                                                        {
                                                                 printf("%d\n",1);
                                                                 return;
                                                        }
                                 }
                    }
                                      
                    i++;
     }     
     printf("%ld\n",mindiff);
}
int checkSquare(long int num)
{
    int s=sqrt(num);
    if((s*s)==num)
    return 1;
    else
    return 0;
}
