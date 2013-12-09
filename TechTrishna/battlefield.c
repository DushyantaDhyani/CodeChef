#include<stdio.h>
int check_arrival(int t,int arr[],int len);
int check_depart(int k,int arr[],int len);
int main()
{
    int N;
    scanf("%d",&N);
    int arrival[N];
    int depart[N];
    int i,x,y;
    int count=0;
    int Max=0;
    int maximum=0;
    for(i=0;i<N;i++)
    {
                    scanf("%d",&arrival[i]);
    }
    for(i=0;i<N;i++)
    {
                    scanf("%d",&depart[i]);
    }        
    Max=depart[N-1];
    for(i=1;i<=Max;i++)
    {
             x=check_arrival(i,arrival,N);
             y=check_depart(i,depart,N);       
             count=count-y;
             count=count+x;
             if(count>maximum)
             maximum=count;
    }
    printf("%d",maximum);
    return 0;
}
int check_arrival(int t,int arr[],int len)
{
    int ctr=0;
    int j;
    for(j=0;j<len;j++)
                    if(arr[j]==t)
                                 ctr++;
    return ctr;
}
int check_depart(int k,int arr[],int len)
{
    int ctr=0;
    int j;
    for(j=0;j<len;j++)
                    if(arr[j]==k)
                                 ctr++;
    return ctr;
}
