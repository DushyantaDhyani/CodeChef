#include<stdio.h>
long int eval(long int no);
int main()
{

    int T;
    scanf("%d",&T);
    long int output[T];
    int i=0;
    long int num=0;
    int j=0;
    int limit=0;
    while(i<T)
    {
               scanf("%ld",&num);
               limit=sqrt(num);
                   if(checksquare(num))
                   {
                       output[i]=0;
                   }
                   else if(chec
                   {
                      j=3;
                      if(num==2)
                      {
                               output[i]=1;
                               flag=1;
                      }
                      else if((num%2)==0)
                               flag=0;
                      else
                      {
                          while(j<=limit)
                          {
                                         if((num%j)==0)
                                         {
                                          flag=0;
                                          break;
                                         }
                                         j=j+2;
                          }
                          if(j>limit)
                          {
                                     output[i]=num-1;
                                     flag=1;
                          }
                      }       
                      if(flag==0)
                      {
                                    output[i]=eval(num);
                      }   
               
            }
               i++;
    }
    i=0;
    while(i<T)
    {
               printf("%ld\n",output[i]);
               i++;
    }
    return 0;
}
long int eval(long int no)
{
     long int i=2;
     long int limit=no/2;
     long int num1,num2,mindiff;
     while(i<=limit)
     {
                    if((no%i)==0)
                    {
                                 limit=no/i;
                                 break;
                    }
                    i++;
     }
     num1=i;
     num2=no/i;
     mindiff=num2-num1;
     if(mindiff==1)
                   return 1;
     i++;
     while(i<limit)
     {
                   
                    if((no%i)==0)
                    {
                                 num1=i;
                                 num2=no/i;
                                 limit=num2;
                                 if((num2-num1)<mindiff)
                                 {
                                                        mindiff=num2-num1;
                                                        if(mindiff==1)
                                                                 return 1;
                                 }
                    }
                                      
                    i++;
     }     
     return mindiff;
}
