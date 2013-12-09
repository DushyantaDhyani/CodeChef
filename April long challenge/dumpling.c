#include<stdio.h>
int check(long long int p,long long int q,long long int z);
void display(long long int val[],int lim);
int main()
{
 int T;
 scanf("%d",&T);
 int i;
 long long int val[T];
 i=0;
 while(i<T)
 {
           val[i]=1;
           i++;
 }
 i=1;
 while(i<=T)
 {
            long long int A,B,C,D,K,temp;
            scanf("%lli",&A);
            scanf("%lli",&B);
            scanf("%lli",&C);
            scanf("%lli",&D);
            scanf("%lli",&K);
            temp=0;
            while(K>=1)
            {
                       if((check(A,B,K)==1) &&(check(C,D,K)==1))
                       val[i-1]+=2;       
                       
                       K--; 

            }
            i++;
}
 display(val,T);
 return 0;
}
int check(long long int p,long long int q,long long int z)
{
    long long int x=z/p;
    if(x<=0)
    x=z%p;
    while(x>=0)
    {
               if((z-x*p)%q==0)
               return 1;
               if((z+x*p)%q==0)
               return 1;
               x--;
    }    
    return 0;
}
void display(long long int val[],int lim)
{
     int i=0;
     while(i<lim)
     {
                 printf("%lli\n",val[i]);
                 i++;
     }
}
