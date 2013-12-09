#include<stdio.h>
int rev(int x);
int main()
{
    int T;
    int i;
    int num1,num2;
    scanf("%d",&T);
    int arr[T];
    i=0;
    while(i<T)
    {
              scanf("%d",&num1);
              scanf("%d",&num2);
              num1=rev(num1);
              num2=rev(num2);
              arr[i]=rev(num1+num2);
              i++;
    }
    i=0;
    while(i<T)
    {
              printf("%d\n",arr[i]);
              i++;
    }
    return 0;
}
int rev(int x)
{
    int t,r;
    t=0;
    while(x>0)
    {
              r=x%10;
              t=t*10+r;
              x=x/10;
    }
    return t;
}
