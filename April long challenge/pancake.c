#include<stdio.h>
#include<conio.h>
void enter(int arr[],int size);
int maxterm(int arr[],int size);
void compute(int **arrtemp,int outtemp[],int limit,int curr);
void display(int out[],int max);
int main()
{
    int T,max=0,i;
    scanf("%d",&T);
    int arr[T];
    int *temp=malloc(sizeof(int));
    temp[0]=1;
    enter(arr,T);
    max=maxterm(arr,T);
    int out[max];
    for(i=0;i<max;i++)
    out[i]=0;
    out[0]++;
    compute(&temp,out,max,1);
    display(out,max);
    getch();
    return 0;
}
void enter(int arr[],int size)
{
     int i=0;
     while(i<size)
     {
                  scanf("%d",&arr[i]);
                  i++;
     }
}
int maxterm(int arr[],int size)
{
    int i=1;
    int max=arr[0];
    while(i<size)
    {
                 if(arr[i]>max)
                 max=arr[i];
                 i++;
    }
    return max;
}
void compute(int **arrtemp,int outtemp[],int limit,int curr)
{
     if(curr!=limit)
     {
                    printf("I am here \n");
                    int i;
                    int t=maxterm(*arrtemp,curr);
                    printf("This is the maximum value%d",t);
                    curr++;
                    *arrtemp=(int *)realloc(*arrtemp,curr*sizeof(int));
                    for(i=1;i<=t+1;i++)
                    {
                                       outtemp[curr-1]++;
                                       *(*arrtemp+curr-1)=i;
                                       printf("I am here \n");                                     
                                       display(*arrtemp,curr);
                                       compute(arrtemp,outtemp,limit,curr);
                                       printf("The value of curr is %d\n",curr);
                                       int *arrtemp=(int *)realloc(*arrtemp,curr*sizeof(int));
                    }
     }
}
void display(int out[],int max)
{
     printf("I'm luvin it :D\n");
     int i=0;
     while(i<max)
     {
                 printf("%d\n",out[i]);
                 i++;
     }
}
