#include<stdio.h>
int reform(int x);
int power(int x,int y);
int complen(int x);
int main()
{
 int N,N1;

 int a,b,l;
 int i=0;
 scanf("%d",&N);
  int arr[N];
  N1=N;
 while(N>0)
 {
           l=0;
           scanf("%d",&a);
           scanf("%d",&b);
           if(a>b)
           {
                  l=complen(a)-complen(b);
                  
                  b=power(b,l);
                  
                  arr[i]=reform(a+b);
           }
           else if(b>a)
           {
                l=complen(b)-complen(a);
                a=power(a,l);
                arr[i]=reform(a+b);
           }
           else
           arr[i]=a+b;
           i++;
           N--;
 }

 i=0;
 while(i<N1)
 {
 printf("%d\n",arr[i]);
 i++;
}
 
  return 0;
}
int complen(int x)
{
    int ctr=0;
    while(x!=0)
    {
               ctr++;
               x=x/10;
    }
    return ctr;
}
int power(int x,int y)
{
    while(y>0)
    {
     x=x*10;
     y--;
    }
    return x;
}
int reform(int x)
{
    while(x>0)
    {
              if((x%10)==0)
              x=x/10;
    }
}
