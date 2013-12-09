#include<stdio.h>
void enter(int arr[],int size);
long int combine(int arr[],int limit,int size);
int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    int i;
    enter(arr,n);

    long int x=combine(arr,k,n);

    printf("%ld",x);
    return 0;        
}
void enter(int arr[],int size)
{
     int i=0;
     for(i=0;i<size;i++)
     scanf("%d",&arr[i]);
}
long int combine(int arr[],int limit,int size)
{
 int i=size-1;
 int end=limit;
 long int sum=0;
 while(end>0)
 {
          end--;
          i--;
 }
 while(i>=0)
 {
  arr[i]=arr[i]*-1;
  i--;
  }
 for(i=0;i<size;i++)
 sum+=arr[i];
 return sum;
}
