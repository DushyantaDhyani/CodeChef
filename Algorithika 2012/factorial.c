#include<stdio.h>
#include<conio.h>
void fact_eval(int x);
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    int i;
    for (i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<N;i++)
                    fact_eval(arr[i]);
    getch();
    return 0;    
}
void fact_eval(int x)
{
     int j;
     unsigned long int fact=1;
     for(j=1;j<=x;j++)
     {
     fact=fact*j;
     printf("\n%lu",fact);     
     }
     printf("\n%Ld\n",fact);     
}
