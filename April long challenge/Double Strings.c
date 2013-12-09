#include<stdio.h>
void display(long int arr[],int sz);
void eval(long int arr[],int sz);
int main()
{
 int t;
 scanf("%d",&t);
 long int output[t];
 eval(output,t);
 display(output,t);
 return 0;
}
void display(long int arr[],int sz)
{
     int j=0;
     while(j<sz)
     {
                printf("%ld\n",arr[j]);
                j++;
     }
}
void eval(long int arr[],int sz)
{
     long int x;
     int i=0;
     while(i<sz)
     {
                scanf("%ld",&x);
                if((x%2)==0)
                arr[i]=x;
                else
                arr[i]=x-1;
                i++;
     }
}
